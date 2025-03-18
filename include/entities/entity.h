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

union EntitySprite {
    StaticSprite static_sprite;
    AnimatedSprite anim_sprite;
};

class Entity {
public:
    Entity();
    Entity(SPRITE_TYPE sprite_type, const std::string& spritesheet_path);
    ~Entity();

    void setStaticSprite(const std::string& path_to_sprite);

    mVec2<int> pos;
    EntitySprite sprite;
};

#endif //PROJECTISO_ENTITY_H
