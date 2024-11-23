cmake_minimum_required(VERSION 3.16)
project(ChessGame)

# Use the Vcpkg toolchain file
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
else()
    set(CMAKE_TOOLCHAIN_FILE "vcpkg-master/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2 and SDL2_image using Vcpkg
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

# Add include directories (if any additional headers are outside src/)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Define the executable and source files
add_executable(ChessGame
        src/main.cpp
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
        src/Chess/InputHandler.h
        src/Chess/ScannedCell.cpp
        src/Chess/ScannedCell.h
)

# Link SDL2 and SDL2_image to your executable
target_link_libraries(ChessGame PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)