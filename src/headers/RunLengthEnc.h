#ifndef ZIP_2D_RUN_LENGTH_ENCODER
#define ZIP_2D_RUN_LENGTH_ENCODER

#include <vector>

#include "FsUtils.h"
#include "BitUtils.h"

using namespace std;

class RunLengthEnc
{
private:
    typedef vector<fs::path> FilenameVec;
    typedef vector<BitUtils::Bit> Bit1DVec;
    typedef vector<Bit1DVec> Bit2DVec;

    FsUtils::BitMap m_map;
    FilenameVec m_filename_vec;

    FilenameVec getFilenameVec();
    Bit2DVec getVerticalBit2DVec();

protected:

public:
    RunLengthEnc(FsUtils::BitMap map);

    typedef vector<vector<vector<BitUtils::Bit, int>>> RLEncMap;

    int m_no_bit = 2;  // "ON" bit is 1, "OFF" bit is 0, so here we define no bit as 2

    RLEncMap encode();
};

#endif
