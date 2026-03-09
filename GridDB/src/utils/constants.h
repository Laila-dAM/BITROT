#pragma once
#include <cstddef>
#include <string>

namespace Constants
{
    constexpr std::size_t PAGE_SIZE = 4096;
    constexpr std::size_t MAX_COLUMNS = 64;
    constexpr std::size_t MAX_TABLES = 1024;
    constexpr std::size_t MAX_ROW_SIZE = 8192;

    const std::string DATABASE_FILE_EXTENSION = ".db";
    const std::string LOG_FILE_NAME = "database.log";
}