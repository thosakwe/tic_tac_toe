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
    unsigned int n_row = (unsigned int) board->get_size(), n_col = (unsigned int) board->get_size();
    bool ok = false;

    std::cout << "Player " << marker_ << ": It's your turn!" << std::endl;

    while (!ok) {
        std::cout << "Enter row number (0-based): ";
        std::cin >> n_row;
        std::cout << "Enter column number (0-based): ";
        std::cin >> n_col;
        ok = n_row >= 0 && n_col >= 0;
        ok = ok && n_row < board->get_size() && n_col < board->get_size();
        ok = ok && board->TileAt(n_row, n_col)->get_marker() == nullptr;
    }

    if (n_row >= board->get_size()) {
        std::cerr << "Invalid move." << std::endl;
    } else {
        board->TileAt(n_row, n_col)->set_marker(marker_);
    }
}