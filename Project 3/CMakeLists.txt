cmake_minimum_required(VERSION 3.16)

project(stockcore C)

set(CMAKE_C_STANDARD 99)

find_package(SQLite3 REQUIRED)

add_executable(stockcore
    src/main.c
)

target_link_libraries(stockcore SQLite::SQLite3)
