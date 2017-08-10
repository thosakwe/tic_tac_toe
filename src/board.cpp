// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#include "board.h"

Board::Board(int size) {
    size_ = size;

    // Initialize a square grid
    for (int i = 0; i < size; i++) {
        auto *row = new std::vector<Tile *>();

        for (int j = 0; j < size; j++) {
            row->push_back(new Tile());
        }

        grid_.push_back(row);
    }
}

int Board::get_size() {
    return size_;
}

std::vector<std::vector<Tile *> *> Board::get_grid() {
    return grid_;
}

void Board::print() {
    for (unsigned int i = 0; i < size_; i++) {
        if (i > 0) {
            std::cout << std::endl;
            for (int j = 0; j < size_; j++)
                std::cout << "---";
            std::cout << std::endl;
        }

        std::vector<Tile *> *row = grid_.at(i);

        for (unsigned int col = 0; col < size_; col++) {
            if (col > 0)
                std::cout << " | ";
            Tile *tile = row->at(col);

            if (tile->get_marker() == nullptr)
                std::cout << " ";
            else std::cout << tile->get_marker();
        }
    }
}
