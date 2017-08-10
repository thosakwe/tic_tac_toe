// 
// Copyright (c) 2017 Tobe O.
// MIT License: https://github.com/chug-lang/chug/blob/master/LICENSE
//
#include "tile.h"

const char *Tile::get_marker() {
    return marker_;
}

void Tile::set_marker(const char *marker) {
    if (marker_ != nullptr)
        throw std::logic_error("This tile already has a marker.");
    marker_ = marker;
}
