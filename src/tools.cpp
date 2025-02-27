//
// Created by couland-q on 29/03/2022.
//

#include "../include/tools.h"

namespace Random {
    int get_int(int min, int max, int seed) {
        if (seed != -1) {
            EffoRandom::seed(seed);
        }

        if (min == max) {
            return min;
        }    

        if (min > max) {
            std::swap(min, max);
        }
            
        return EffoRandom::get(min, max);
    }
}

namespace Tools {
    uint coordinates2dto1d(uint x, uint y, uint w) {
        return ((w * y) + x);
    }

    double dst(int x1, int y1, int x2, int y2) {
        if (pow(x2 - x1, 2) + pow(y2 - y1, 2) != 0)
            return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);

        return 0;
    }

    void scaleRect(SDL_Rect& rect_to_scale, const float scale_factor) {
        rect_to_scale.w *= scale_factor;
        rect_to_scale.h *= scale_factor;
    }

    SDL_Rect getSDLRectFromSize(int x, int y, int w, int h) {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
        return rect;
    }

    SDL_Rect getSDLRectFromSize(mVec2<int> origin, int w, int h) {
        SDL_Rect rect;
        rect.x = origin.x;
        rect.y = origin.y;
        rect.w = w;
        rect.h = h;
        return rect;
    }

    SDL_Rect getSDLRectFromCoord(int x1, int y1, int x2, int y2) {
        SDL_Rect rect;
        rect.x = x1;
        rect.y = y1;
        rect.w = x2 - x1;
        rect.h = y2 - y1;
        return rect;
    }

    SDL_Rect getSDLRectFromCoord(mVec2<int> origin, int x2, int y2) {
        SDL_Rect rect;
        rect.x = origin.x;
        rect.y = origin.y;
        rect.w = x2 - origin.x;
        rect.h = y2 - origin.y;
        return rect;
    }

    SDL_Rect getSDLRectFromCoord(int x1, int y1, mVec2<int> target) {
        SDL_Rect rect;
        rect.x = x1;
        rect.y = y1;
        rect.w = target.x;
        rect.h = target.y;
        return rect;
    }

    SDL_Rect getSDLRectFromCoord(mVec2<int> origin, mVec2<int> target) {
        SDL_Rect rect;
        rect.x = origin.x;
        rect.y = origin.y;
        rect.w = target.x;
        rect.h = target.y;
        return rect;
    }

    StaticSprite& findSpriteFromPos(mVec2<int> pos, std::vector<StaticSprite>& sprite_lst) {
        for (auto& sprite: sprite_lst) {
            if (sprite.pos.x == pos.x && sprite.pos.y == pos.y) {
                return sprite;
            }
        }

        std::cerr << "ERROR: sprite not found, returning first sprite of the list." << std::endl;
        return(sprite_lst[0]);
    }

    StaticSprite& findSpriteFromPos(int x, int y, std::vector<StaticSprite>& sprite_lst) {
        for (auto& sprite: sprite_lst) {
            if (sprite.pos.x == x && sprite.pos.y == y) {
                return sprite;
            }
        }

        std::cerr << "ERROR: sprite not found, returning first sprite of the list." << std::endl;
        return(sprite_lst[0]);
    }

    StaticSprite& findSpriteByName(const std::string& name, std::vector<StaticSprite>& sprite_lst) {
        for (auto& sprite: sprite_lst) {
            if (sprite.name == name) {
                return sprite;
            }
        }

        std::cerr << "ERROR: sprite not found, returning first sprite of the list." << std::endl;
        return(sprite_lst[0]);
    }
}

