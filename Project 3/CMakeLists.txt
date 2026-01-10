cmake_minimum_required(VERSION 3.15)
project(StockCore C)

set(CMAKE_C_STANDARD 11)

find_package(SQLite3 REQUIRED)

add_executable(stockcore
    src/main.c
)

target_link_libraries(stockcore PRIVATE SQLite::SQLite3)
