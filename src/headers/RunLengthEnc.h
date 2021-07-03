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
    typedef vector<Bit> Bit1DVec;
    typedef vector<Bit1DVec> Bit2DVec;

    FsUtils::BitMap m_map;
    FilenameVec m_filename_vec;
    Bit2DVec m_bit_2d_vec;

    FilenameVec getFilenameVec();
    Bit2DVec getVerticalBit2DVec();

protected:

public:
    RunLengthEnc(FsUtils::BitMap map);

    struct BitRepeat {
        Bit bit;
        int repeat;
    };
    typedef vector<BitRepeat> BitRepeatVec;
    typedef vector<BitRepeatVec> RLEncMap;

    RLEncMap encode();
};

#endif
