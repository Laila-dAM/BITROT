#include "file_utils.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace bf
{
    std::string readFile(const std::string& path)
    {
        std::ifstream file(path, std::ios::in | std::ios::binary);
        if (!file)
            throw std::runtime_error("Unable to open file: " + path);

        std::ostringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    void writeFile(const std::string& path, const std::string& content)
    {
        std::ofstream file(path, std::ios::out | std::ios::binary);
        if (!file)
            throw std::runtime_error("Unable to write file: " + path);

        file << content;
        if (!file.good())
            throw std::runtime_error("Error writing file: " + path);
    }
}
