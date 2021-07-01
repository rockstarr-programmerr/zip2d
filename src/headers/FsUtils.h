#ifndef ZIP_2D_FS_UTILS
#define ZIP_2D_FS_UTILS

#include <filesystem>
#include <map>
#include <vector>

using namespace std;
namespace fs = filesystem;

class FsUtils
{
private:
    fs::path m_input_dir;
protected:
public:
    FsUtils(fs::path input_dir);

    typedef vector<bool> BitVec;
    typedef map<fs::path, BitVec> BitMap;

    BitMap mapFilenameToBits();
};

#endif
