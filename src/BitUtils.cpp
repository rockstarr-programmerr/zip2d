#include "BitUtils.h"

BitUtils::Bit BitUtils::getBit(char c, short pos)
{
    pos--;
    short mask = 0x1;
    BitUtils::Bit bit = (c >> pos) & mask;
    if (bit) {
        return 1;
    } else {
        return 0;
    }
}
