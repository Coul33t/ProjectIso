//
// Created by couland-q on 05/01/2024.
//

#ifndef PROJECTISO_SPRITE_H
#define PROJECTISO_SPRITE_H

#include <string>

#include "include_SDL.h"

#include "types.h"

struct Sprite {
    int idx;
    mVec2<int> pos;
    SDL_Rect rect;
    std::string name;
    std::string spritesheet_name;
};

#endif //PROJECTISO_SPRITE_H