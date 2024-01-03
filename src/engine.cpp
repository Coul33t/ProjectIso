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

    KSDL ksdl;

    if (!ksdl.init(640, 480, "Test name")) {
        return;
    }

    SDL_Event e;
    bool quit = false; 

    while (quit == false) { 
        while (SDL_PollEvent( &e )) { 
            if (e.type == SDL_QUIT) {
                quit = true; 
            } 
        }
    }

    ksdl.destroy();
}