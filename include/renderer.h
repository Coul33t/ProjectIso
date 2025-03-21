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
#include "tileset.h"
#include "entities/entity.h"
#include "ksdl.h"
#include "sprite.h"
#include "tools.h"
#include "constants.h"

typedef std::vector<std::pair<std::string, Tileset>> TilesetVec;

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

    void addEntitySpritesheet(const std::string& name, const std::string& spritesheet_path);

    void drawMap(Map& map);
    void drawEntities(std::vector<Entity>& entities);
    void drawCursor(Entity& cursor);

    void render(Map& map, std::vector<Entity>& entities, Entity& cursor);

    mVec2<int> translate2DIntoIso(mVec3<int>& pos, mVec2<int>& offset);

    void renderText(const std::string& msg, const mVec2<int>& pos, const SDL_Color& colour);

    mVec2<uint> size;
    float scale_factor;
    std::vector<StaticSprite> sprites;
    Tileset map_tileset;
    KSDL ksdl;
    TilesetVec entities_tilesets;
};


#endif //PROJECTISO_RENDERER_H
