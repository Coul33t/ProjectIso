//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_RENDERER_H
#define PROJECTISO_RENDERER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "raylib.h"

#include "map.h"

struct TileSetInfo {
    mVec2<int> tile_size;
    mVec2<int> offsets;

    TileSetInfo() {
        tile_size.w = -1;
        tile_size.h = -1;
    }

    TileSetInfo(int tile_width, int tile_height) {
        tile_size.w = tile_width;
        tile_size.h = tile_height;
    }

    TileSetInfo(int tile_width, int tile_height,
                int horizontal_offset, int vertical_offset) {
        tile_size.w = tile_width;
        tile_size.h = tile_height;
        offsets.x = horizontal_offset;
        offsets.y = vertical_offset;
    }
};

class Renderer {
public:
    Renderer();
    ~Renderer();

    void init();
    void load_textures();
    Texture2D& get_texture_from_name(Tile& tile);

    void draw_map(Map& map);

    mVec2<uint> size;
    float scale_factor;
    std::map<std::string, Texture2D> textures;
    TileSetInfo tileset_info;
};


#endif //PROJECTISO_RENDERER_H
