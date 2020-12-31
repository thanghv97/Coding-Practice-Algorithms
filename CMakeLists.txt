cmake_minimum_required(VERSION 3.10.2)
project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wcast-align -Wunused -Wpointer-arith -Wno-missing-braces -g")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_subdirectory(algorithms)
add_subdirectory("data\ structures")