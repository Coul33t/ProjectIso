//
// Created by couland-q on 24/01/2024.
//

#include "../../include/entities/entity.h"

Entity::Entity() {
    this->name = "NO_NAME";
    this->pos = mVec2<int>{0, 0};
}

Entity::Entity(const std::string& name, SPRITE_TYPE sprite_type, const std::string& spritesheet_path) {
    this->name = name;
    this->sprite.type = sprite_type;
    this->pos = mVec2<int>{0, 0};
}

Entity::~Entity() {

}

void Entity::setStaticSprite(const std::string& path_to_sprite) {
    sprite.type = SPRITE_TYPE::STATIC;

    sprite.static_sprite.name = this->name;
}

void Entity::setDynamicSprite() {

}