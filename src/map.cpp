//
// Created by couland-q on 29/03/2022.
//

#include "../include/map.h"

Map::Map() {

}

Map::~Map() {

}

Tile Map::get_tile_at(uint x, uint y) {
    return tiles[Tools::coordinates2dto1d(x, y, size.w)];
}

void Map::make_test_map() {
    size.w = 10;
    size.h = 10;

    for (size_t y = 0; y < size.h; y++) {
        for (size_t x = 0; x < size.w; x++) {
            // Debug tile
            if (x == 0 && y == 0) 
                tiles.emplace_back(Tile(("waterfull"), x, y, 0));

            // Debug tile
            else if (x == 1 && y == 0) {
                tiles.emplace_back(Tile(("stonefull"), x, y, 0));
            }

            else {
                int z = Random::get_int(-1, 0);
                if(z >= 0) {
                    tiles.emplace_back(Tile("grassfull", x, y, z));
                }
                
                else if (z == -1) {
                    tiles.emplace_back(Tile("dirtgrassfull", x, y, z));
                }

                else if (z == -2) {
                    tiles.emplace_back(Tile("dirtfull", x, y, z));
                }

                else if (z == -3) {
                    tiles.emplace_back(Tile("waterfull", x, y, z));
                }
            }
            
        }
    }
}

bool Map::adjacent_diff_is_bigger_than(Tile& tile, int max_level) {
    for (Tile& tile_in_lst: tiles) {
        if (&tile != &tile_in_lst) {
            if (Tools::dst(tile.get_pos_as_mvec(), tile_in_lst.get_pos_as_mvec()) > 2) {
                if (tile.pos.z - tile_in_lst.pos.z > max_level)
                    return true;
            }
        }
    }

    return false;
}