//
// Created by couland-q on 29/03/2022.
//

#include "../include/renderer.h"

Renderer::Renderer() {
    size.w = Constants::WINDOW_SIZE_W;
    size.h = Constants::WINDOW_SIZE_H;
    scale_factor = 1.0;
}

Renderer::~Renderer() {
    ksdl.destroy();
}

std::vector<StaticSprite>& Renderer::getSprites() {
    return this->sprites;
}

bool Renderer::init() {
    return ksdl.init(size.w, size.h, "Test name");
}

void Renderer::loadTileset() {
    std::string spritesheet_name = "iso_sprite_sheet.png";
    this->tileset = ksdl.loadImage("../res/tiles/3232iso/iso_sprite_sheet.png");
    
    int tile_w = Constants::TILE_W;
    int tile_h = Constants::TILE_H;
    tileset_info.tile_size.w = tile_w;
    tileset_info.tile_size.h = tile_h;
    tileset_info.offsets.x = tile_w / 2;
    tileset_info.offsets.y = tile_h / 2;

    float tex_size_x, tex_size_y;
    SDL_GetTextureSize(tileset, &tex_size_x, &tex_size_y); 
    tileset_info.size.w = tex_size_x;
    tileset_info.size.h = tex_size_y;

    tileset_info.nb_tiles.x = tileset_info.size.w / tile_w;
    tileset_info.nb_tiles.y = tileset_info.size.h / tile_h;

    for (int i = 0; i < tileset_info.size.h / tileset_info.tile_size.h; i++) {
        for (int j = 0; j < tileset_info.size.w / tileset_info.tile_size.w; j++) {
            StaticSprite new_sprite(i, j, tileset_info, "", spritesheet_name);
            this->sprites.emplace_back(new_sprite);
        }
    }

    scale_factor = 2.0;
}

void Renderer::assignNameToSprites() {
    // WARNING: x = 5, y = 6 -> (6, 5)
    Tools::findSpriteFromPos(6, 5, this->sprites).name = "grassfull";
    Tools::findSpriteFromPos(6, 4, this->sprites).name = "dirtgrassfull";
    Tools::findSpriteFromPos(6, 3, this->sprites).name = "dirtfull";
    Tools::findSpriteFromPos(2, 0, this->sprites).name = "sandfull";
    Tools::findSpriteFromPos(5, 5, this->sprites).name = "stonefull";
    Tools::findSpriteFromPos(0, 1, this->sprites).name = "waterfull";
}

SDL_Rect Renderer::getSurfaceCoordFromName(Tile& tile) {
    return Tools::findSpriteByName(tile.texture_name, this->sprites).rect;
}

int Renderer::getTextureIdxFromName(const std::string& name) {
    for (auto& sprite: this->sprites) {
        if (sprite.name == name) {
            return sprite.idx;
        }
    }

    return -1;
}

mVec2<int> Renderer::translate2DIntoIso(mVec3<int>& pos, mVec2<int>& offset) {
    mVec2<int> iso_pos;  

    // First term: grid based
    // Second term: diamond shape
    // scale_factor: scaling
    iso_pos.x = offset.x + (pos.x * (tileset_info.offsets.x * scale_factor)) - (scale_factor * tileset_info.offsets.x * pos.y);
    iso_pos.y = offset.y + (pos.y * (scale_factor * tileset_info.offsets.y) / 2) + (pos.x * tileset_info.offsets.y);
    // Z offset (if any)
    iso_pos.y = iso_pos.y - (pos.z * tileset_info.offsets.y);

    return iso_pos;
}

void Renderer::drawMap(Map& map) {
    mVec2<int> offset;
    mVec2<int> pos;
    SDL_Rect surface_coord;
    
    offset.x = static_cast<int>((size.w / 2) - (map.getSize().x / 2));
    offset.y = static_cast<int>((size.h / 4) - (map.getSize().y / 2));

    int tile_w = Constants::TILE_W;
    int tile_h = Constants::TILE_H;

    for (Tile& tile: map.getTiles()) {
        // TODO: Split into static and animated sprite
        surface_coord = getSurfaceCoordFromName(tile);
        pos = translate2DIntoIso(tile.pos, offset);

        /*if (tile.fill_under && map.adjacentZDiffIsBiggerThan(tile, 2)) {
            mVec2<int> fill_pos = pos;
            fill_pos.y += tileset_info.tile_size.h;
            SDL_Rect fill_rect = Tools::getSDLRectFromSize(fill_pos, tile_w, tile_h);
            ksdl.drawTexture(this->tileset, surface_coord, fill_rect);
        }*/

        SDL_Rect tex_rect = Tools::getSDLRectFromSize(pos, tile_w, tile_h);
        Tools::scaleRect(tex_rect, scale_factor);
        // TODO: seek the right tileset (probably in Sprite)
        ksdl.drawTexture(this->tileset, surface_coord, tex_rect);
    }
}

void Renderer::drawEntities(std::vector<Entity>& entities) {
    for (auto& ent: entities) {

    }
}

void Renderer::drawCursor(Entity& cursor) {

}

void Renderer::renderText(const std::string& msg, const mVec2<int>& pos, const SDL_Color& colour) {
    this->ksdl.renderText(msg, pos, colour);
}

void Renderer::render(Map& map, std::vector<Entity>& entities, Entity& cursor) {
    this->ksdl.SDLClearRenderer();
    this->drawMap(map);
    this->drawCursor(cursor);
    this->drawEntities(entities);
    this->ksdl.update();
    this->ksdl.SDLRenderPresent();
}