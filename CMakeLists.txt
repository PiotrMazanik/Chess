cmake_minimum_required(VERSION 3.16)
project(ChessGame)

# Set C++ standard
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Arch/source/vcpkg-master/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add executable
add_executable(ChessGame src/main.cpp
        src/Base/Scene.cpp
        src/Base/Scene.h
        src/Chess/ChessScene.cpp
        src/Chess/ChessScene.h
        src/Base/SceneManager.cpp
        src/Base/SceneManager.h
        src/Base/Game.cpp
        src/Base/Game.h
        src/Chess/Board.cpp
        src/Chess/Board.h
        src/Chess/Piece.cpp
        src/Chess/Piece.h
        src/Chess/InputHandler.cpp
        src/Chess/InputHandler.h)

# Link SDL2 and SDL2main
# Link SDL2 and SDL2_image libraries
target_link_libraries(ChessGame PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image)