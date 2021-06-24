#include <vector>
#include <map>
#include <fstream>
#include <filesystem>
#include <iostream>

#include "FsUtils.h"
#include "BitUtils.h"

namespace fs = std::filesystem;

FsUtils::FsUtils(fs::path input_dir)
{
    m_input_dir = input_dir;
}

FsUtils::BitMap FsUtils::mapFilenameToBits()
{
    FsUtils::BitMap map;
    BitUtils bit_utils;

    for (auto& p : fs::recursive_directory_iterator(m_input_dir))
    {
        if (p.is_directory())
            continue;

        fs::path path = p.path();
        std::ifstream stream(path, std::ifstream::binary);

        if (stream) {
            stream.seekg(0, stream.end);
            std::streamsize size = stream.tellg();
            stream.seekg(0, stream.beg);

            char* buffer = new char[size];
            stream.read(buffer, size);

            std::vector<bool> content;

            for (long i = 0; i < size; i++)
            {
                char c = buffer[i];
                for (short pos = 8; pos > 0; pos--)
                {
                    bool bit = bit_utils.getBit(c, pos);
                    content.push_back(bit);
                }
            }

            fs::path filename = path.filename();
            map[filename] = content;

            delete[] buffer;

        } else {
            std::cout << "FsUtils::mapFilenameToBits open file failed: "
                      << path.filename()
                      << std::endl;
        }
    }

    return map;
}
