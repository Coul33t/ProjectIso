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
    std::cout << "Running" << std::endl;
    scale_factor = 0.25;

    std::cout << "Make test map" << std::endl;
    map.make_test_map();
    std::cout << "Load tileset" << std::endl;
    renderer.loadTileset();

    SDL_Event e;
    bool quit = false; 

    std::cout << "Before while loop" << std::endl;

    while (quit == false) { 
        while (SDL_PollEvent(&e)) { 
            if (e.type == SDL_QUIT) {
                quit = true; 
            } 
        }

        renderer.render(this->map);
        std::cout << "Rendering" << std::endl;
    }
}