//
// Created by couland-q on 24/01/2024.
//

#include "../../include/entities/entity.h"

Entity::Entity() {

}

Entity::Entity(SPRITE_TYPE sprite_type, const std::string& spritesheet_path) {
    if (sprite_type == SPRITE_TYPE::STATIC) {
        this->sprite = StaticSprite();
    }

    else {
        this->sprite = AnimatedSprite();
    }
}

Entity::~Entity() {

}

void Entity::setStaticSprite(const std::string& path_to_sprite) {
    
}