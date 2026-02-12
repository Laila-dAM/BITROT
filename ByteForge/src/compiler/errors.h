#ifndef BYTEFORGE_ERRORS_H
#define BYTEFORGE_ERRORS_H

#include <stdexcept>
#include <string>

namespace bf
{
    class CompilerError : public std::runtime_error
    {
    public:
        explicit CompilerError(const std::string& message)
            : std::runtime_error(message)
        {
        }
    };
}

#endif
