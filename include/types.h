//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_TYPES_H
#define PROJECTISO_TYPES_H

#include <cstdint>

#include "raylib.h"

typedef unsigned int uint;

template<typename T>
struct mVec2
{
    union {
        struct { T x, y;};
        struct { T w, h;};
    };
};

template<typename T>
struct mVec3
{
    union {
        struct { T x, y, z;};
        struct { T w, h, d;};
    };
};

#endif //PROJECTISO_TYPES_H
