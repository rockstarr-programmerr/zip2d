#ifndef ZIP_2D_BIT_UTILS
#define ZIP_2D_BIT_UTILS

enum class Bit {
    OFF,
    ON,
    EMPTY
};

class BitUtils
{
private:
protected:
public:
    BitUtils() {};
    Bit getBit(char c, short pos);
    int getBitRepr(Bit bit);
};

#endif
