//
// Created by couland-q on 29/03/2022.
//

#include "../include/engine.h"

Engine::Engine() {
    
}

Engine::~Engine() {

}

void Engine::loadFromText(const std::string& filename, const std::string& path) {
     std::ifstream input_file(path + filename + ".txt");

     if (input_file.is_open()) {
        std::string line;
        while(getline(input_file, line)) {  // read data from file object and put it into string.
            std::cout << line << std::endl; // print the data of the string
        }
     }

     else {
        std::cerr << FULL_LOCATION << "ERROR: " << path << filename << " can't be opened." << std::endl; 
     }
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

void Engine::loadEntity(const std::string& name, const std::string& path_to_spritesheet, SPRITE_TYPE sprite_type) {
    Entity ent;
    ent.name = name;
    ent.sprite.type = sprite_type;
    if (sprite_type == SPRITE_TYPE::STATIC) {
        ent.setStaticSprite(path_to_spritesheet);
    }

    else {
        ent.setDynamicSprite();
    }

    renderer.addEntitySpritesheet(name, path_to_spritesheet);
}

bool Engine::init() {
    if (!renderer.init()) {
        return false;
    }

    // Init cursor (tmp)
    cursor.name = "Cursor";
    cursor.setStaticSprite("../res/sprites/cursor.png");

    return true;
}

void Engine::dummyLoadEntities() {

}

void Engine::run() {
    map.generateCuteMap();
    renderer.loadTileset();
    renderer.assignNameToSprites();

    //this->loadFromText("../res/maps/", "test_map_text");

    this->saveMapToJSON();

    SDL_Event e;
    bool quit = false; 

    while (quit == false) { 
        while (SDL_PollEvent(&e)) { 
            if (e.type == SDL_EVENT_QUIT) {
                quit = true; 
            } 
        }

        renderer.renderText("Test", mVec2<int>{10, 10}, {255, 255, 255, 255});
        renderer.render(this->map, this->entities, this->cursor);
    }
}