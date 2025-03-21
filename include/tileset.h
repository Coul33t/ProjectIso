#ifndef PROJECTISO_TILESET_H
#define PROJECTISO_TILESET_H

#include "ksdl.h"
#include "types.h"

struct Tileset {
    TileSetInfo info;
    SDL_Texture* texture = nullptr;

    Tileset() = default;

    void loadTexture(const std::string& path, KSDL& ksdl) {
        this->texture = ksdl.loadImage(path);
    }
};

#endif