// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#ifndef TIC_TAC_TOE_PLAYER_H
#define TIC_TAC_TOE_PLAYER_H


#include "board.h"

class Player {
public:
    virtual const char *get_marker() = 0;

    virtual void takeTurn(int turn_number, Board *board, Player *opponent) = 0;
};


#endif //TIC_TAC_TOE_PLAYER_H
