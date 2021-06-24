bool get_bit(char c, short pos)
{
    pos--;
    bool result = (c >> pos) & 0x1;
    return result;
}
