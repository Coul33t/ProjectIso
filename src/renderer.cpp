//
// Created by couland-q on 29/03/2022.
//

#include "../include/renderer.h"

Renderer::Renderer() {
    size.w = 1600;
    size.h = 900;
    scale_factor = 1.0;
}

Renderer::~Renderer() {
    ksdl.destroy();
}

void Renderer::init() {
    // TODO: do something with return value
    ksdl.init(640, 480, "Test name");
}

void Renderer::loadTileset() {
    tileset = loadImage("../res/3232iso/iso_sprite_sheet.png");
    int tile_w = Constants::TILE_W;
    int tile_h = Constants::TILE_H;
    tileset_info.tile_size.w = tile_w;
    tileset_info.tile_size.h = tile_h;
    tileset_info.offsets.x = tile_w / 2;
    tileset_info.offsets.y = tile_h / 2;
    tileset_info.size.w = tileset->w;
    tileset_info.size.h = tileset->h;
    tileset_info.nb_tiles.x = tileset_info.size.w / tile_w;
    tileset_info.nb_tiles.y = tileset_info.size.h / tile_h;

    surfaces["grassfull"]       = Tools::getSDLRectFromSize(5*tile_w, 6*tile_h, tile_w, tile_h);
    surfaces["dirtgrassfull"]   = Tools::getSDLRectFromSize(4*tile_w, 6*tile_h, tile_w, tile_h);
    surfaces["dirtfull"]        = Tools::getSDLRectFromSize(3*tile_w, 6*tile_h, tile_w, tile_h);
    surfaces["stonefull"]       = Tools::getSDLRectFromSize(5*tile_w, 5*tile_h, tile_w, tile_h);
    surfaces["waterfull"]       = Tools::getSDLRectFromSize(1*tile_w, 0*tile_h, tile_w, tile_h);

    scale_factor = 2.0;
}

SDL_Surface* Renderer::loadImage(std::string path) {
    //The final optimized image
    SDL_Surface* optimized_surface = NULL;

    //Load image at specified path
    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == NULL) {
        std::cout << "Unable to load image %s! SDL Error: " << path.c_str() << " | " << SDL_GetError() << std::endl;
    }

    else {
        //Convert surface to screen format
        optimized_surface = SDL_ConvertSurface(loaded_surface, ksdl.getScreenSurface()->format, 0);
        if(optimized_surface == NULL) {
            std::cout <<"Unable to optimize image " << path.c_str() << "! SDL Error: " << SDL_GetError();
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loaded_surface);
    }

    return optimized_surface;
}

SDL_Rect Renderer::getSurfaceCoordFromName(Tile& tile) {
    if (this->surfaces.find(tile.texture_name) != this->surfaces.end())
        return this->surfaces[tile.texture_name];

    else {
        std::cout << "[WARNING: texture \"" << tile.texture_name << "\" not in map.]" << std::endl;
        return (*this->surfaces.begin()).second;
    }
}

void Renderer::draw_map(Map& map) {
    mVec2<float> offset;
    mVec2<int> pos;
    SDL_Rect surface_coord;
    offset.x = size.w / 2;
    offset.y = 10;

    int tile_w = Constants::TILE_W;
    int tile_h = Constants::TILE_H;

    for (Tile& tile: map.tiles) {
        surface_coord = getSurfaceCoordFromName(tile);
        // screen offset + actual position - left offset
        pos.x =   offset.x + (tileset_info.offsets.x * scale_factor) * tile.pos.x
                - (scale_factor * tileset_info.offsets.x * tile.pos.y);
        // screen offset + actual position + top offset
        pos.y =   offset.y + ((scale_factor * tileset_info.offsets.y) - tileset_info.offsets.y) * tile.pos.y
                - (tile.pos.z * tileset_info.offsets.y)
                + ((scale_factor * tileset_info.offsets.y - tileset_info.offsets.y) * tile.pos.x);

        if (tile.fill_under && map.adjacent_diff_is_bigger_than(tile, 2)) {
            mVec2<int> fill_pos = pos;
            fill_pos.y += tileset_info.tile_size.h;
            ksdl.drawSurface(this->tileset, surface_coord, Tools::getSDLRectFromSize(fill_pos, tile_w, tile_h));
        }

        ksdl.drawSurface(this->tileset, surface_coord, Tools::getSDLRectFromSize(pos, tile_w, tile_h));
    }
}

void Renderer::render(Map& map) {
    this->draw_map(map);
    this->ksdl.update();
}