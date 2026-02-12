#include "string_utils.h"
#include <algorithm>
#include <cctype>

namespace bf
{
    std::string ltrim(const std::string& str)
    {
        size_t start = 0;
        while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start])))
            start++;
        return str.substr(start);
    }

    std::string rtrim(const std::string& str)
    {
        if (str.empty())
            return str;

        size_t end = str.size() - 1;
        while (end > 0 && std::isspace(static_cast<unsigned char>(str[end])))
            end--;

        return str.substr(0, end + 1);
    }

    std::string trim(const std::string& str)
    {
        return rtrim(ltrim(str));
    }

    std::string toLower(const std::string& str)
    {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(),
            [](unsigned char c) { return std::tolower(c); });
        return result;
    }

    std::string toUpper(const std::string& str)
    {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(),
            [](unsigned char c) { return std::toupper(c); });
        return result;
    }
}
