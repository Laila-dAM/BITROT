cmake_minimum_required(VERSION 3.10)

project(inventory_management_cli C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(inventory_management
    src/main.c
    src/database.c
    src/auth.c
    src/menu.c
)
