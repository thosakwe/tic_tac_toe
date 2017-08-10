// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#include "game.h"

Game::Game(int boardSize, Player *player1, Player *player2) {
    board_ = new Board(boardSize);
    _player1 = player1;
    _player2 = player2;
}

Game::~Game() {
    delete (board_);
}

Board *Game::get_board() {
    return board_;
}

int Game::get_turn_count() {
    return turn_count_;
}

void Game::start() {
    if (started_)
        throw std::logic_error("The game has already started.");

    // TODO: Figure out if a player has won
    // Should be defined on Board
    while (true) {
        turn_count_++;
        _player1->takeTurn(turn_count_, board_, _player2);
    }
}
