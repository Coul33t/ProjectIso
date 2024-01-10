//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_RENDERER_H
#define PROJECTISO_RENDERER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "include_SDL.h"

#include "map.h"
#include "ksdl.h"
#include "sprite.h"
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

    std::vector<Sprite>& getSprites();

    void init();
    void loadTileset();
    void assignNameToSprites();
    SDL_Rect getSurfaceCoordFromName(Tile& tile);
    int getTextureIdxFromName(const std::string& name);

    void draw_map(Map& map);

    SDL_Texture* loadImage(const std::string& path);

    void render(Map& map);

    mVec2<int> translate2DIntoIso(mVec3<int>& pos, mVec2<int>& offset);

    void renderText(const std::string& msg, const mVec2<int>& pos, const SDL_Color& colour);

    mVec2<uint> size;
    float scale_factor;
    std::vector<Sprite> sprites;
    TileSetInfo tileset_info;
    KSDL ksdl;
    SDL_Texture* tileset;
};


#endif //PROJECTISO_RENDERER_H
