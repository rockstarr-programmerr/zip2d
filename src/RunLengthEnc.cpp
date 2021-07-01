#include <vector>
#include <filesystem>
#include <iostream>

#include "RunLengthEnc.h"
#include "FsUtils.h"

namespace fs = std::filesystem;

RunLengthEnc::RunLengthEnc(FsUtils::BitMap map)
{
    m_map = map;
}

RunLengthEnc::RLEncMap RunLengthEnc::encode()
{

}

RunLengthEnc::RLEncFilenameVec RunLengthEnc::getFilenameVec()
{
    RunLengthEnc::RLEncFilenameVec filenames;
    for (auto item : m_map)
    {
        fs::path filename = item.first;
        filenames.push_back(filename);
    }
    return filenames;
}

RunLengthEnc::RLEnc2DBitVec RunLengthEnc::getVerticalBit2DVec()
{
    std::vector<FsUtils::BitVec> bit_vecs;
    for (auto item : m_map)
    {
        FsUtils::BitVec bit_vec = item.second;
        bit_vecs.push_back(bit_vec);
    }


}
