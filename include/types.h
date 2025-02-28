//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_TYPES_H
#define PROJECTISO_TYPES_H

#include <cstdint>

// Lazy ass (TODO: proper sized variables)
typedef unsigned int uint;

// I know anonymous structs are UB, but there's no way to do this properly 
// without making the struct way bigger in memory
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
template<typename T>
struct mVec2
{
    union {
        struct { T x, y; };
        struct { T w, h; };
    };
};

template<typename T>
struct mVec3
{
    union {
        struct { T x, y, z; };
        struct { T w, h, d; };
    };
};
#pragma GCC diagnostic pop

struct TileSetInfo {
    mVec2<int> tile_size;
    mVec2<int> offsets;
    mVec2<int> size;
    mVec2<size_t> nb_tiles;

    TileSetInfo() {
        tile_size.w = -1;
        tile_size.h = -1;
    }

    TileSetInfo(int tile_width, int tile_height) {
        tile_size.w = tile_width;
        tile_size.h = tile_height;
    }

    TileSetInfo(int tile_width, int tile_height,
                int horizontal_offset, int vertical_offset) {
        tile_size.w = tile_width;
        tile_size.h = tile_height;
        offsets.x = horizontal_offset;
        offsets.y = vertical_offset;
    }
};

#endif //PROJECTISO_TYPES_H
