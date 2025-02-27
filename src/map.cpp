//
// Created by couland-q on 29/03/2022.
//

#include "../include/map.h"

Map::Map() {

}

Map::~Map() {

}

mVec2<uint>& Map::getSize() {
    return this->size;
}

std::vector<Tile>& Map::getTiles() {
    return this->tiles;
}

Tile& Map::getTileAt(uint x, uint y) {
    return tiles[Tools::coordinates2dto1d(x, y, size.h)];
}

void Map::rotateClockwise() {
    for (auto& tile: this->tiles) {
        int new_x = tile.pos.y;
        int new_y = this->size.w - tile.pos.x;
        tile.pos.x = new_x;
        tile.pos.y = new_y;
    }

    //this->reorderTileByCoordinates();
}

void Map::rotateCounterClockwise() {
    // Ehehehehh
    this->rotateClockwise();
    this->rotateClockwise();
    this->rotateClockwise();
}

void Map::reorderTileByCoordinates() {
    std::sort(this->tiles.begin(), this->tiles.end(), 
              [this](Tile &t1, Tile &t2){return (t1.pos.x * this->size.w) + t1.pos.y > 
                                                (t2.pos.x * this->size.w) + t2.pos.y;});
}

void Map::makeTestMap() {
    this->size.w = 10;
    this->size.h = 10;

    for (size_t y = 0; y < this->size.h; y++) {
        for (size_t x = 0; x < this->size.w; x++) {
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

void Map::generateCuteMap() {
    this->size.w = 11;
    this->size.h = 15;

    for (size_t y = 0; y < this->size.w; y++) {
        for (size_t x = 0; x < this->size.h; x++) {
            if (y == 0) {
                int z = 2;
                tiles.emplace_back(Tile("grassfull", x, y, z));
            }

            else if (y == 1) {
                int z = 2;
                tiles.emplace_back(Tile("grassfull", x, y, z));
            }

            else if (y == 2) {
                int z = 2;
                if (x <= 5 || x >= 11) {
                    z = 1;
                }

                tiles.emplace_back(Tile("grassfull", x, y, z));
            }

            else if (y == 3) {
                int z = 1;
                tiles.emplace_back(Tile("grassfull", x, y, z));
            }

            else if (y == 4) {
                int z = 1;
                tiles.emplace_back(Tile("dirtgrassfull", x, y, z));
            }

            else if (y == 5) {
                int z = 0;
                if (x <= 7) {
                    tiles.emplace_back(Tile("waterfull", x, y, z));
                }

                else {
                    tiles.emplace_back(Tile("dirtfull", x, y, z));

                }
            }

            else if (y == 6) {
                int z = 0;
                if (x >= 6 && x <= 12) {
                    tiles.emplace_back(Tile("waterfull", x, y, z));
                }

                else {
                    tiles.emplace_back(Tile("dirtfull", x, y, z));

                }
            }

            else if (y == 7) {
                int z = 0;
                if (x >= 12) {
                    tiles.emplace_back(Tile("waterfull", x, y, z));
                }

                else {
                    tiles.emplace_back(Tile("dirtfull", x, y, z));

                }
            }

            else if (y == 8) {
                int z = 1;
                tiles.emplace_back(Tile("dirtgrassfull", x, y, z));
            }

            else if (y == 9) {
                int z = 1;
                tiles.emplace_back(Tile("dirtgrassfull", x, y, z));
            }

            else if (y == 10) {
                int z = 1;
                tiles.emplace_back(Tile("dirtgrassfull", x, y, z));
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        this->getTileAt(8 + i, 5).texture_name = "sandfull";
    }

    for (int i = 0; i < 2; i++) {
        this->getTileAt(4 + i, 6).texture_name = "sandfull";
    }

    
    this->getTileAt(11, 5).texture_name = "stonefull";
    this->getTileAt(12, 5).texture_name = "stonefull";
    this->getTileAt(13, 5).texture_name = "stonefull";
    this->getTileAt(14, 5).texture_name = "stonefull";

    this->getTileAt(1, 6).texture_name = "stonefull";
    this->getTileAt(2, 6).texture_name = "stonefull";
    this->getTileAt(3, 6).texture_name = "stonefull";
    this->getTileAt(13, 6).texture_name = "sandfull";
    this->getTileAt(14, 6).texture_name = "stonefull";

    this->getTileAt(11, 7).texture_name = "sandfull";
}

bool Map::adjacentZDiffIsBiggerThan(Tile& tile, int max_level) {
    for (Tile& tile_in_lst: tiles) {
        if (&tile != &tile_in_lst) {
            if (Tools::dst(tile.get_pos_as_mvec(), tile_in_lst.get_pos_as_mvec()) > 2) {
                if (tile.pos.z - tile_in_lst.pos.z > max_level) {
                    return true;
                }
            }
        }
    }

    return false;
}