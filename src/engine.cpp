//
// Created by couland-q on 29/03/2022.
//

#include "../include/engine.h"

Engine::Engine() {
    scale_factor = 1;
}

Engine::~Engine() {

}

void Engine::init() {
    renderer.init();
}

void Engine::run() {
    scale_factor = 0.25;

    map.make_test_map();
    renderer.load_textures();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        renderer.draw_map(map);

        DrawText("this IS a texture!", 360, 370, 10, GRAY);

        EndDrawing();
    }
}