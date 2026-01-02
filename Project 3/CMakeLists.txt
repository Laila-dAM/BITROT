cmake_minimum_required(VERSION 3.10)

project(inventory_management_cli C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include src/db)

add_executable(inventory_management
    src/main.c
    src/db/database.c
)

target_link_libraries(inventory_management sqlite3)
