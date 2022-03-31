//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_TOOLS_H
#define PROJECTISO_TOOLS_H

#include "../extlib/random/random.hpp"

#include "types.h"

namespace Random {
    using EffoRandom = effolkronium::random_static;
    int get_int(int lower, int higher, int seed=7);
}

namespace Tools {
    uint coordinates2dto1d(uint x, uint y, uint w);
    double dst(int x1, int y1, int x2, int y2);
    template<typename T>
    double dst(mVec2<T> p1, mVec2<T> p2);
}

#include "tools.tcc"

#endif //PROJECTISO_TOOLS_H
