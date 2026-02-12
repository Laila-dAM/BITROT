#ifndef BYTEFORGE_STRING_UTILS_H
#define BYTEFORGE_STRING_UTILS_H

#include <string>

namespace bf
{
    std::string ltrim(const std::string& str);
    std::string rtrim(const std::string& str);
    std::string trim(const std::string& str);

    std::string toLower(const std::string& str);
    std::string toUpper(const std::string& str);
}

#endif
