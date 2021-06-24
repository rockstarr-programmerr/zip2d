#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "bit_utils.h"

namespace fs = std::filesystem;


int main(int argc, char* argv[])
{
    fs::path cwd = fs::current_path();
    fs::path input_dir = fs::relative("dummy_input", cwd);
    fs::path output_dir = fs::relative("dummy_output", cwd);

    for (auto& p : fs::recursive_directory_iterator(input_dir))
    {
        if (p.is_directory()) {
            continue;
        }

        fs::path path = p.path();
        std::ifstream stream(path, std::ifstream::binary);

        if (stream) {
            stream.seekg(0, stream.end);
            std::streamsize size = stream.tellg();
            stream.seekg(0, stream.beg);

            char* buffer = new char[size];
            stream.read(buffer, size);

            short bit_per_byte = 8;
            short byte_per_char = sizeof(char);
            long bit_count = size * byte_per_char * bit_per_byte;

            bool* content = new bool[bit_count];
            long content_index = 0;
            for (long index = 0; index < size; index++)
            {
                char c = buffer[index];
                for (short pos = 8; pos > 0; pos--)
                {
                    bool bit = get_bit(c, pos);
                    content[content_index] = bit;
                    content_index ++;
                }
            }

            fs::path output_path = fs::absolute(output_dir);
            output_path += "/";
            output_path += path.filename();

            std::ofstream file(output_path);
            if (file) {
                for (long index = 0; index < bit_count; index++)
                {
                    bool bit = content[index];
                    file << bit;
                }
                file.close();
            }

            stream.close();
            delete[] buffer;
            delete[] content;
        }
    }

    std::cout << "Done!" << std::endl;

    return 0;
}
