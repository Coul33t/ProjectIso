//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_RENDERER_H
#define PROJECTISO_RENDERER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "map.h"
#include "ksdl.h"
#include "tools.h"
#include "constants.h"

struct TileSetInfo {
    mVec2<int> tile_size;
    mVec2<int> offsets;
    mVec2<int> size;
    mVec2<size_t> nb_tiles;

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
    void loadTileset();
    SDL_Rect getSurfaceCoordFromName(Tile& tile);

    void draw_map(Map& map);

    SDL_Texture* loadImage(const std::string& path);

    void render(Map& map);

    mVec2<int> translate2DIntoIso(mVec3<int>& pos, mVec2<int>& offset);

    mVec2<uint> size;
    float scale_factor;
    std::map<std::string, SDL_Rect> surfaces;
    TileSetInfo tileset_info;
    KSDL ksdl;
    SDL_Texture* tileset;
};


#endif //PROJECTISO_RENDERER_H
