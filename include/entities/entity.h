//
// Created by couland-q on 24/01/2024.
//

#ifndef PROJECTISO_ENTITY_H
#define PROJECTISO_ENTITY_H

#include <iostream>
#include <string>
#include <vector>

#include "sprite.h"
#include "tools.h"

class Entity {
public:
    Entity();
    Entity(const std::string& spritesheet_path);
    ~Entity();

private:
    mVec2<int> pos;
    AnimatedSprite sprite;
};

#endif //PROJECTISO_ENTITY_H
