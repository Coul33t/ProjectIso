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

class Renderer {
public:
    Renderer();
    ~Renderer();

    std::vector<StaticSprite>& getSprites();

    bool init();
    void loadTileset();
    void assignNameToSprites();
    SDL_Rect getSurfaceCoordFromName(Tile& tile);
    int getTextureIdxFromName(const std::string& name);

    void drawMap(Map& map);

    SDL_Texture* loadImage(const std::string& path);

    void render(Map& map);

    mVec2<int> translate2DIntoIso(mVec3<int>& pos, mVec2<int>& offset);

    void renderText(const std::string& msg, const mVec2<int>& pos, const SDL_Color& colour);

    mVec2<uint> size;
    float scale_factor;
    std::vector<StaticSprite> sprites;
    TileSetInfo tileset_info;
    KSDL ksdl;
    SDL_Texture* tileset;
};


#endif //PROJECTISO_RENDERER_H
