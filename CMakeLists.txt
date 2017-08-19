cmake_minimum_required(VERSION 3.0)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/board.h
        src/tile.h
        src/game.cpp
        src/game.h
        src/player.cpp
        src/player.h
        src/tile.cpp
        src/board.cpp
        src/user_controlled_player.cpp
        src/user_controlled_player.h
        src/greedy_player.cpp src/greedy_player.h)
add_executable(tic_tac_toe ${SOURCE_FILES})