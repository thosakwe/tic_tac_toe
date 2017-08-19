//
// Created by thosa on 8/19/2017.
//

#include "greedy_player.h"

GreedyPlayer::GreedyPlayer(const char *marker) {
    marker_ = marker;
}

const char *GreedyPlayer::get_marker() {
    return marker_;
}

void GreedyPlayer::takeTurn(int turn_number, Board *board, Player *opponent) {
    // Just choose the first open tile
    auto grid = board->get_grid();

    Tile* target = nullptr;

    for (unsigned int i = 0; i < grid.size(); i++) {
        auto * row = grid.at(i);

        for (unsigned int col = 0; col < row->size(); col++) {
            auto * tile = row->at(col);

            if (tile->get_marker() == nullptr) {
                target = tile;
                break;
            }
        }

        if (target != nullptr) break;
    }

    if (target != nullptr) {
        target->set_marker(marker_);
        std::cout << "Greedy A.I. has made its move!" << std::endl;
    } else {
        std::cerr << "No available tiles for the Greedy A.I.!!!" << std::endl;
    }
}
