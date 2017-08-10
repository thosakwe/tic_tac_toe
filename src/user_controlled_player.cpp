// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#include "user_controlled_player.h"

UserControlledPlayer::UserControlledPlayer(const char *marker) {
    marker_ = marker;
}

const char *UserControlledPlayer::get_marker() {
    return marker_;
}

void UserControlledPlayer::takeTurn(int turn_number, Board *board, Player *opponent) {
    // Just fill the whole board up!

    for (unsigned int i = 0; i < board->get_size(); i++) {
        std::vector<Tile*>* row = board->get_grid().at(i);

        for (unsigned int col = 0; col < board->get_size(); col++) {
            Tile* tile = row->at(col);

            if (tile->get_marker() == nullptr) {
                tile->set_marker(marker_);
                return;
            }
        }
    }
}