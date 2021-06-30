#include <vector>
#include <filesystem>
#include <iostream>

#include "RunLengthEnc.h"
#include "FsUtils.h"

namespace fs = std::filesystem;

RunLengthEnc::RunLengthEnc(FsUtils::BitMap map)
{
    m_map = map;
};

RunLengthEnc::RLEncMap RunLengthEnc::encode()
{
    // Vector of filenames
    std::vector<fs::path> filenames;
    for (auto item : m_map)
    {
        fs::path filename = item.first;
        filenames.push_back(filename);
    }
}
