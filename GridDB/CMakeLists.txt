cmake_minimum_required(VERSION 3.15)

project(GridDB VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE GRIDDB_SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(griddb ${GRIDDB_SOURCES})

target_include_directories(griddb PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

enable_testing()

file(GLOB_RECURSE GRIDDB_TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/tests/*.cpp
)

if(GRIDDB_TEST_SOURCES)
    add_executable(griddb_tests ${GRIDDB_TEST_SOURCES} ${GRIDDB_SOURCES})
    target_include_directories(griddb_tests PRIVATE
        ${CMAKE_SOURCE_DIR}/src
    )
    add_test(NAME GridDBTests COMMAND griddb_tests)
endif()