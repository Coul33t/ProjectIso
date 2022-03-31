//
// Created by couland-q on 29/03/2022.
//

#include "../include/tools.h"

namespace Random {
    int get_int(int min, int max, int seed) {
        if (min == max)
            return min;

        if (min > max)
            std::swap(min, max);

        return EffoRandom::get(min, max);
    }
}

namespace Tools {
    uint coordinates2dto1d(uint x, uint y, uint w) {
        return (w * y + x);
    }

    double dst(int x1, int y1, int x2, int y2) {
        if (pow(x2 - x1, 2) + pow(y2 - y1, 2) != 0)
            return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);

        return 0;
    }
}

