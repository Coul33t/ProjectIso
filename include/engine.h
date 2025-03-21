//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_ENGINE_H
#define PROJECTISO_ENGINE_H

#include <fstream>

#include <include_SDL.h>
#include <json.hpp>

#include "entities/entity.h"
#include "map.h"
#include "renderer.h"
#include "ksdl.h"

using json = nlohmann::json;

class Engine {
public:
    Engine();
    ~Engine();

    void loadFromText(const std::string& filename, const std::string& path);
    void loadFromJSON(const std::string& path);
    void saveMapToJSON(const std::string& filename="default_name");

    void loadEntity(const std::string& name, const std::string& path_to_spritesheet, SPRITE_TYPE sprite_type);

    void dummyLoadEntities();

    bool init();
    void run();

    float scale_factor;
    Renderer renderer;
    Map map;
    std::vector<Entity> entities;
    Entity cursor;
};

#endif //PROJECTISO_ENGINE_H
