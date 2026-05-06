cmake_minimum_required(VERSION 3.16)
project(GaymEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(ASCII-Renderer ${SOURCES})

target_include_directories(ASCII-Renderer PRIVATE include/stb)
target_include_directories(ASCII-Renderer PUBLIC src)

set(CMAKE_BUILD_TYPE Release)