#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <map>

#include "FsUtils.h"
#include "RunLengthEnc.h"

namespace fs = std::filesystem;


int main(int argc, char* argv[])
{
    fs::path cwd = fs::current_path();
    fs::path input_dir = fs::relative("dummy_input", cwd);

    FsUtils fs_utils(input_dir);
    FsUtils::BitMap map = fs_utils.mapFilenameToBits();

    RunLengthEnc encoder(map);
    RunLengthEnc::RLEncMap enc_map = encoder.encode();

    for (auto item : map)
    {
        std::cout << item.first << ": ";
        for (auto bit : item.second)
        {
            std::cout << bit;
        }
        std::cout << std::endl;
    }

    std::cout << "----------------------------" << std::endl;

    for (auto bit_repeat_vec : enc_map)
    {
        for (auto bit_repeat : bit_repeat_vec)
        {
            BitUtils::Bit bit = bit_repeat[0];
            int repeat = bit_repeat[1];
            std::cout << bit << "x" << repeat << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Done!" << std::endl;

    return 0;
}
