#include <vector>
#include <map>
#include <filesystem>
#include <iostream>

#include "RunLengthEnc.h"
#include "FsUtils.h"

namespace fs = std::filesystem;

RunLengthEnc::RunLengthEnc(FsUtils::BitMap map)
{
    m_map = map;
    m_filename_vec = {};
    m_bit_2d_vec = {};
}

RunLengthEnc::RLEncMap RunLengthEnc::encode()
{
    m_filename_vec = getFilenameVec();
    m_bit_2d_vec = getVerticalBit2DVec();

    RLEncMap enc_map = {};
    for (auto vertical_bits : m_bit_2d_vec)
    {
        BitRepeatVec col_zip = {};
        BitRepeat bit_repeat = {m_no_bit, 0};
        BitUtils::Bit last_bit = m_no_bit;
        bool is_first_loop = true;

        for (auto current_bit : vertical_bits)
        {
            if (is_first_loop) {
                bit_repeat = {current_bit, 1};
                last_bit = current_bit;
                is_first_loop = false;
                continue;
            }

            bool is_new_sequence = last_bit != current_bit;
            if (is_new_sequence) {
                BitRepeat bit_repeat_copy = bit_repeat;
                col_zip.push_back(bit_repeat_copy);

                bit_repeat = {current_bit, 1};
            } else {
                bit_repeat[1]++;
            }

            last_bit = current_bit;
        }

        bool is_no_vertical_bits = bit_repeat[0] != m_no_bit && bit_repeat[1] != 0;
        if (!is_no_vertical_bits)
            col_zip.push_back(bit_repeat);

        enc_map.push_back(col_zip);
    }

    return enc_map;
}

RunLengthEnc::FilenameVec RunLengthEnc::getFilenameVec()
{
    FilenameVec filenames;
    for (auto item : m_map)
    {
        fs::path filename = item.first;
        filenames.push_back(filename);
    }
    return filenames;
}

RunLengthEnc::Bit2DVec RunLengthEnc::getVerticalBit2DVec()
{
    // Get number of bits of biggest file
    // Get map of which file is how much in size
    int max_file_size = 0;
    map<fs::path, int> file_size_map;

    for (auto item : m_map)
    {
        FsUtils::BitVec bit_vec = item.second;
        int file_size = bit_vec.size();

        if (file_size > max_file_size)
            max_file_size = file_size;

        fs::path path = item.first;
        file_size_map[path] = file_size;
    }

    // Create 2D vector
    Bit2DVec bit_2d_vec = {};
    for (int index = 0; index < max_file_size; index++)
    {
        Bit1DVec bit_1d_vec = {};

        for (auto filename : m_filename_vec)
        {
            FsUtils::BitVec bit_vec = m_map[filename];
            int file_size = file_size_map[filename];

            if (index < file_size) {
                BitUtils::Bit bit = bit_vec[index];
                bit_1d_vec.push_back(bit);
            } else {
                bit_1d_vec.push_back(m_no_bit);
            }
        }

        bit_2d_vec.push_back(bit_1d_vec);
    }

    return bit_2d_vec;
}
