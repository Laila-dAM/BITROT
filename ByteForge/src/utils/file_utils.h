#ifndef BF_FILE_UTILS_H
#define BF_FILE_UTILS_H

#include <string>

namespace bf
{
    std::string readFile(const std::string& path);
    void writeFile(const std::string& path, const std::string& content);
}

#endif
