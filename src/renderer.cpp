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

void Renderer::init() {
    // TODO: do something with return value
    ksdl.init(size.w, size.h, "Test name");
}

void Renderer::loadTileset() {
    std::string spritesheet_name = "iso_sprite_sheet.png";
    tileset = loadImage("../res/3232iso/iso_sprite_sheet.png");
    
    int tile_w = Constants::TILE_W;
    int tile_h = Constants::TILE_H;
    tileset_info.tile_size.w = tile_w;
    tileset_info.tile_size.h = tile_h;
    tileset_info.offsets.x = tile_w / 2;
    tileset_info.offsets.y = tile_h / 2;

    SDL_Point tileset_size;
    SDL_QueryTexture(tileset, NULL, NULL, &tileset_size.x, &tileset_size.y); 
    tileset_info.size.w = tileset_size.x;
    tileset_info.size.h = tileset_size.y;

    tileset_info.nb_tiles.x = tileset_info.size.w / tile_w;
    tileset_info.nb_tiles.y = tileset_info.size.h / tile_h;

    for (int i = 0; i < tileset_info.size.h / tileset_info.tile_size.h; i++) {
        for (int j = 0; j < tileset_info.size.w / tileset_info.tile_size.w; j++) {
            Sprite new_sprite;
            new_sprite.idx = i*(tileset_info.size.h / tileset_info.tile_size.h) + j;
            new_sprite.pos = mVec2<int>{j, i}; // i = y, j = x
            new_sprite.rect = SDL_Rect{i*tileset_info.tile_size.h, 
                                       j*tileset_info.tile_size.w,
                                       tileset_info.tile_size.w,
                                       tileset_info.tile_size.h};
            new_sprite.name = "";
            new_sprite.spritesheet_name = spritesheet_name;
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
    Tools::findSpriteFromPos(5, 5, this->sprites).name = "stonefull";
    Tools::findSpriteFromPos(0, 1, this->sprites).name = "waterfull";
}

SDL_Texture* Renderer::loadImage(const std::string& path) {
    //The final optimized image
    SDL_Surface* optimized_surface = NULL;
    SDL_Texture* new_texture = NULL;

    //Load image at specified path
    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == NULL) {
        std::cout << "Unable to load image " << path.c_str() << ". SDL Error: " << SDL_GetError() << std::endl;
    }

    else {
        //Convert surface to screen format
        new_texture = SDL_CreateTextureFromSurface(ksdl.getRenderer(), loaded_surface);
        if(new_texture == NULL) {
            std::cout <<"Unable to create texture from " << path.c_str() << ". SDL Error: " << SDL_GetError();
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loaded_surface);
    }

    return new_texture;
}

SDL_Rect Renderer::getSurfaceCoordFromName(Tile& tile) {
    return Tools::findSpriteByName(tile.texture_name, this->sprites).rect;
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

void Renderer::draw_map(Map& map) {
    mVec2<int> offset;
    mVec2<int> pos;
    SDL_Rect surface_coord;
    
    offset.x = static_cast<int>((size.w / 2) - (map.size.x / 2));
    offset.y = static_cast<int>((size.h / 4) - (map.size.y / 2));

    int tile_w = Constants::TILE_W;
    int tile_h = Constants::TILE_H;

    for (Tile& tile: map.tiles) {
        surface_coord = getSurfaceCoordFromName(tile);
        pos = translate2DIntoIso(tile.pos, offset);

        /*if (tile.fill_under && map.adjacent_diff_is_bigger_than(tile, 2)) {
            mVec2<int> fill_pos = pos;
            fill_pos.y += tileset_info.tile_size.h;
            SDL_Rect fill_rect = Tools::getSDLRectFromSize(fill_pos, tile_w, tile_h);
            ksdl.drawTexture(this->tileset, surface_coord, fill_rect);
        }*/

        SDL_Rect tex_rect = Tools::getSDLRectFromSize(pos, tile_w, tile_h);
        Tools::scaleRect(tex_rect, scale_factor);
        ksdl.drawTexture(this->tileset, surface_coord, tex_rect);
    }
}

void Renderer::render(Map& map) {
    this->ksdl.SDLClearRenderer();
    this->draw_map(map);
    this->ksdl.update();
    this->ksdl.SDLRenderPresent();
}