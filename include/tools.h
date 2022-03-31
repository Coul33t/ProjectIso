//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_TOOLS_H
#define PROJECTISO_TOOLS_H

#include "../extlib/random/random.hpp"

namespace Random {
    using EffoRandom = effolkronium::random_static;
    int get_int(int lower, int higher, int seed=7);
}

#endif //PROJECTISO_TOOLS_H
