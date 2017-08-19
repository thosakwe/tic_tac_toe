// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#include <cstring>
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

bool Board::is_full() {
    for (unsigned int i = 0; i < size_; i++) {
        std::vector<Tile *> *row = grid_.at(i);

        for (unsigned int col = 0; col < size_; col++) {
            if (row->at(col)->get_marker() == nullptr)
                return false;
        }
    }

    return true;
}

void Board::Print() {
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

    std::cout << std::endl << std::endl;
}

Tile *Board::TileAt(unsigned int row, unsigned int col) {
    return grid_.at(row)->at(col);
}

const char *Board::Winner(const char **markers, int length) {
    bool success = true;

    for (int i = 0; i < length; i++) {
        auto * marker = markers[i];

        // Check for vertical
        for (unsigned int j = 0; j < grid_.size(); j++) {
            bool vert = true;

            for (unsigned int k = 0; k < grid_.size(); k++) {
                auto *row = grid_.at(k);
                auto *m = row->at(j)->get_marker();

                if (m == nullptr || strcmp(m, marker) != 0) {
                    vert = false;
                    break;
                }
            }

            if (vert) return marker;
        }

        // Check for horizontal
        for (unsigned int j = 0; j < grid_.size(); j++) {
            auto *row = grid_.at(j);
            bool horiz = true;

            for (unsigned int k = 0; k < row->size(); k++) {
                auto *m = row->at(k)->get_marker();

                if (m == nullptr || strcmp(m, marker) != 0) {
                    horiz = false;
                    break;
                }
            }

            if (horiz) return marker;
        }

        // Check for diagonal from top-left
        unsigned int col = 0;
        success = true;

        for (unsigned int j = 0; j < grid_.size(); j++) {
            auto *row = grid_.at(j);
            auto *m = row->at(col++)->get_marker();

            if (m == nullptr || strcmp(m, marker) != 0) {
                success = false;
                break;
            }
        }

        if (success) return marker;

        // Check for diagonal from top-right
        col = grid_.size() - 1;
        success = true;

        for (unsigned int j = 0; j < grid_.size(); j++) {
            auto *row = grid_.at(j);
            auto *m = row->at(col--)->get_marker();

            if (m == nullptr || strcmp(m, marker) != 0) {
                success = false;
                break;
            }
        }

        if (success) return marker;
    }

    return nullptr;
}
