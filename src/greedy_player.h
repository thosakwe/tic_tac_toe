//
// Created by thosa on 8/19/2017.
//

#ifndef TIC_TAC_TOE_GREEDY_PLAYER_H
#define TIC_TAC_TOE_GREEDY_PLAYER_H

#include "player.h"

class GreedyPlayer : public Player {
public:
    GreedyPlayer(const char* marker);

    const char *get_marker() override;

    void takeTurn(int turn_number, Board *board, Player *opponent) override;

private:
    const char* marker_;
};


#endif //TIC_TAC_TOE_GREEDY_PLAYER_H
