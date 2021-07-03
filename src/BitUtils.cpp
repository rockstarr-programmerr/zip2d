#include "BitUtils.h"

Bit BitUtils::getBit(char c, short pos)
{
    pos--;
    short mask = 0x1;
    bool is_on_bit = (c >> pos) & mask;
    if (is_on_bit) {
        return Bit::ON;
    } else {
        return Bit::OFF;
    }
}

int BitUtils::getBitRepr(Bit bit)
{
    if (bit == Bit::ON) {
        return 1;
    } else if (bit == Bit::OFF) {
        return 0;
    } else {
        return 2;
    }
}
