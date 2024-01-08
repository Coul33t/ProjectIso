//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_ENGINE_H
#define PROJECTISO_ENGINE_H

#include <include_SDL.h>
#include <json.hpp>

#include "map.h"
#include "renderer.h"
#include "ksdl.h"

class Engine {
public:
    Engine();
    ~Engine();

    void loadFromJSON(const std::string& path);
    void saveMapToJSON(const std::string& filename);

    void init();
    void run();

    float scale_factor;
    Renderer renderer;
    Map map;
};

#endif //PROJECTISO_ENGINE_H
