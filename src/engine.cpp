//
// Created by couland-q on 29/03/2022.
//

#include "../include/engine.h"

Engine::Engine() {
    
}

Engine::~Engine() {

}

void Engine::loadFromJSON(const std::string& path) {

}

void Engine::saveMapToJSON(const std::string& filename) {
    // Create empty JSON object
    json json_file = json::object();
    json_file["sprites"] = json::array();

    // Save sprites first
    for (auto& sprite: this->renderer.getSprites()) {
        std::string sprite_name = "sprite_" + std::to_string(sprite.idx);
        json sprite_array;
        sprite_array["idx"] = sprite.idx;
        sprite_array["pos"] = {sprite.pos.x, sprite.pos.y};
        sprite_array["rect"] = {sprite.rect.x, sprite.rect.y, sprite.rect.w, sprite.rect.h};
        sprite_array["name"] = sprite.name;
        sprite_array["spritesheet_name"] = sprite.spritesheet_name;

        json_file["sprites"].push_back(sprite_array);
    }

    json_file["map"] = json::array();

    // Save the map with tiles as idx
    for (auto& tile: this->map.getTiles()) {
        json tile_array;
        tile_array["tile_idx"] = this->renderer.getTextureIdxFromName(tile.texture_name);
        tile_array["pos"] = {tile.pos.x, tile.pos.y, tile.pos.z};
        tile_array["fill_under"] = tile.fill_under;

        json_file["map"].push_back(tile_array);
    }

    std::ofstream file(filename + ".json");
    file << json_file;
    
}

void Engine::init() {
    renderer.init();
}

void Engine::run() {

    map.generateCuteMap();
    renderer.loadTileset();
    renderer.assignNameToSprites();

    this->saveMapToJSON();

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