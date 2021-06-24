#ifndef ZIP_2D_FS_UTILS
#define ZIP_2D_FS_UTILS

#include <filesystem>
#include <map>
#include <vector>

namespace fs = std::filesystem;

class FsUtils
{
private:
    fs::path m_input_dir;
protected:
public:
    FsUtils(fs::path input_dir);

    typedef std::map<fs::path, std::vector<bool>> BitMap;
    BitMap mapFilenameToBits();
};

#endif
