cmake_minimum_required(VERSION 3.8)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/board.h src/tile.h src/game.cpp src/game.h src/player.cpp src/player.h src/tile.cpp src/board.cpp)
add_executable(tic_tac_toe ${SOURCE_FILES})