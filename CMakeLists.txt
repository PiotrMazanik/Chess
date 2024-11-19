cmake_minimum_required(VERSION 3.16)
project(ChessGame)

# Set C++ standard
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Arch/source/vcpkg-master/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add executable
add_executable(ChessGame src/main.cpp)

# Link SDL2 and SDL2main
target_link_libraries(ChessGame PRIVATE SDL2::SDL2 SDL2::SDL2main)