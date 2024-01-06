//
// Created by couland-q on 29/03/2022.
//

#include "../include/engine.h"

Engine::Engine() {
    
}

Engine::~Engine() {

}

void loadFromJSON(const std::string& path) {

}

void saveMapToJSON(const std::string& filename) {

}

void Engine::init() {
    renderer.init();
}

void Engine::run() {

    map.make_test_map();
    renderer.loadTileset();
    renderer.assignNameToSprites();

    SDL_Event e;
    bool quit = false; 

    while (quit == false) { 
        while (SDL_PollEvent(&e)) { 
            if (e.type == SDL_QUIT) {
                quit = true; 
            } 
        }

        renderer.render(this->map);
    }
}