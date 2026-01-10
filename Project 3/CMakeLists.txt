cmake_minimum_required(VERSION 3.10)

project(stockcore_cli C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(stockcore
    src/core/main.c
    src/core/app.c
    src/database/database.c
    src/auth/auth.c
    src/inventory/inventory.c
    src/reports/reports.c
)

find_package(SQLite3 REQUIRED)

target_link_libraries(stockcore SQLite::SQLite3)
