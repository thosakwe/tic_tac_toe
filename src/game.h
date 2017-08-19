// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H


#include <exception>
#include "board.h"
#include "player.h"

class Game {
public:
    Game(int boardSize, Player *player1, Player *player2);
    ~Game();
    Board* get_board();
    int get_turn_count();
    const char* start();

    static const int possible_markers_count = 2;
private:
    Board *board_;
    Player *_player1, *_player2;
    const char** possible_markers = new const char*[possible_markers_count];
    bool started_ = false;
    int turn_count_ = 0;
};


#endif //TIC_TAC_TOE_GAME_H
