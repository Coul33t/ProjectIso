//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_MAP_H
#define PROJECTISO_MAP_H

#include <string>
#include <vector>

#include "raylib.h"

#include "types.h"


struct Tile {
    Texture2D texture;
    mVec3<int> pos; // x, y, z

    Tile() {

    }
    Tile(std::string path_to_texture) {
        texture = LoadTexture(path_to_texture.c_str());
    }

    Tile(std::string path_to_texture, int x, int y, int z=1) {
        texture = LoadTexture(path_to_texture.c_str());
        pos.x = x;
        pos.y = y;
        pos.z = z;
    }

    void load_from_image(std::string path_to_texture) {
        texture = LoadTexture(path_to_texture.c_str());
    }
};

class Map {
    Map();
    ~Map();

    void make_test_map();

    std::vector<Tile> tiles;
};

#endif //PROJECTISO_MAP_H
