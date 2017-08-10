// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <iostream>
#include <vector>
#include "tile.h"

class Board {
public:
    explicit Board(int size);
    int get_size();
    std::vector<std::vector<Tile *> *> get_grid();
    bool is_full();

    void Print();
private:
    int size_;
    std::vector<std::vector<Tile*>*> grid_;
};

#endif //TIC_TAC_TOE_BOARD_H
