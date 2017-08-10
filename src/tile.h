// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#ifndef TIC_TAC_TOE_TILE_H
#define TIC_TAC_TOE_TILE_H

class Tile {
public:
    char* get_marker();
    void set_marker(char*);
private:
    char* marker_ = nullptr;
};

#endif //TIC_TAC_TOE_TILE_H
