// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#ifndef TIC_TAC_TOE_USER_CONTROLLED_PLAYER_H
#define TIC_TAC_TOE_USER_CONTROLLED_PLAYER_H

#include "player.h"

class UserControlledPlayer : public Player {
public:
    explicit UserControlledPlayer(const char *marker);

    const char *get_marker() override;

    void takeTurn(int turn_number, Board *board, Player *opponent) override;

private:
    const char *marker_;
};


#endif //TIC_TAC_TOE_USER_CONTROLLED_PLAYER_H
