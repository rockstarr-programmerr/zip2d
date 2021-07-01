#ifndef ZIP_2D_RUN_LENGTH_ENCODER
#define ZIP_2D_RUN_LENGTH_ENCODER

#include <vector>
#include "FsUtils.h"

using namespace std;

class RunLengthEnc
{
private:
    FsUtils::BitMap m_map;

    typedef vector<fs::path> RLEncFilenameVec;
    typedef vector<vector<bool>> RLEnc2DBitVec;

    RLEncFilenameVec getFilenameVec();
    RLEnc2DBitVec getVerticalBit2DVec();

protected:

public:
    RunLengthEnc(FsUtils::BitMap map);

    typedef vector<vector<vector<bool, int>>> RLEncMap;

    RLEncMap encode();
};

#endif
