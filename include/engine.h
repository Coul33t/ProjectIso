//
// Created by couland-q on 29/03/2022.
//

#ifndef PROJECTISO_ENGINE_H
#define PROJECTISO_ENGINE_H

#include "raylib.h"

#include "map.h"
#include "renderer.h"

class Engine {
public:
    Engine();
    ~Engine();

    void init();
    void run();

    float scale_factor;
    Renderer renderer;
    Map map;
};

#endif //PROJECTISO_ENGINE_H
