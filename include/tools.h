//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_TOOLS_H
#define PROJECTISO_TOOLS_H

#include "include_SDL.h"

#include "../extlib/random/random.hpp"

#include "types.h"
#include "sprite.h"

#define FULL_LOCATION "[" << __FILE__ << " | " << __FUNCTION__ << " | l." << __LINE__ << "]"
#define FILE_NAME "[" << __FILE__ << "]"
#define FUNCTION_NAME "[" << __FUNCTION__ << "]"
#define LINE "l." << __LINE__

namespace Random {
    using EffoRandom = effolkronium::random_static;
    int get_int(int lower, int higher, int seed=7);
}

namespace Tools {
    uint coordinates2dto1d(uint x, uint y, uint w);
    double dst(int x1, int y1, int x2, int y2);
    template<typename T>
    double dst(mVec2<T> p1, mVec2<T> p2);

    SDL_Rect getSDLRectFromSize(int x, int y, int w, int h);
    SDL_Rect getSDLRectFromSize(mVec2<int> origin, int w, int h);

    void scaleRect(SDL_Rect& rect_to_scale, const float scale_factor);

    SDL_Rect getSDLRectFromCoord(int x1, int y1, int x2, int y2);
    SDL_Rect getSDLRectFromCoord(mVec2<int> origin, int x2, int y2);
    SDL_Rect getSDLRectFromCoord(int x1, int y1, mVec2<int> target);
    SDL_Rect getSDLRectFromCoord(mVec2<int> origin, mVec2<int> target);

    Sprite& findSpriteFromPos(mVec2<int> pos, std::vector<Sprite>& sprite_lst);
    Sprite& findSpriteFromPos(int x, int y, std::vector<Sprite>& sprite_lst);
    Sprite& findSpriteByName(const std::string& name, std::vector<Sprite>& sprite_lst);
}

#include "tools.tcc"

#endif //PROJECTISO_TOOLS_H
