#include "BitUtils.h"

bool BitUtils::getBit(char c, short pos)
{
    pos--;
    short mask = 0x1;
    bool bit = (c >> pos) & mask;
    return bit;
}
