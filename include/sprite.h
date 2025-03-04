//
// Created by couland-q on 05/01/2024.
//

#ifndef PROJECTISO_SPRITE_H
#define PROJECTISO_SPRITE_H

#include <iostream>
#include <string>

#include "include_SDL.h"

#include "types.h"
#include "macros.h"

enum SPRITE_TYPE {
    STATIC,
    ANIMATED
};

/**
 * Basic sprite, with just the name and the spritesheet name. Shouldn't be instanciated (kinda useless as is).
*/
struct BasicSprite {
    // Type of the sprite 
    SPRITE_TYPE type;
    // Name of the sprite
    std::string name;
    // Name of the spritesheet from where the sprite is taken
    std::string spritesheet_name;

    BasicSprite() = default;
};

/**
 * A sprite that isn't animated.
*/
struct StaticSprite: BasicSprite {
    // Index of the sprite (from 0 to k, with k = width * height)
    int idx;
    // Position of the top left corner of the sprite in the spritesheet
    mVec2<int> pos;
    // SDL Rectangle of the sprite in the spritesheet
    SDL_Rect rect;

    StaticSprite() {
        idx = -1;
        pos.x = -1;
        pos.y = -1;
        rect.x = -1;
        rect.y = -1;
        rect.w = -1;
        rect.h = -1;
        type = SPRITE_TYPE::STATIC;
    }

    StaticSprite(int i, int j, const TileSetInfo& tileset_info, 
                 const std::string& name, const std::string& spritesheet_name) {
        this->idx = (i*tileset_info.nb_tiles.x) + j;
        this->pos.x = j;
        this->pos.y = i;
        this->rect = SDL_Rect{i*tileset_info.tile_size.h, 
                              j*tileset_info.tile_size.w,
                              tileset_info.tile_size.w,
                              tileset_info.tile_size.h};
        this->name = name;
        this->spritesheet_name = spritesheet_name;
    }
};

/**
 * A sprite that is animated.
*/
struct AnimatedSprite: BasicSprite {
    int current_sprite_idx;
    
    AnimatedSprite() {
        type = SPRITE_TYPE::ANIMATED;
    }

    
};

#endif //PROJECTISO_SPRITE_H