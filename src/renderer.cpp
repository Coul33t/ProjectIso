//
// Created by couland-q on 29/03/2022.
//

#include "../include/renderer.h"

Renderer::Renderer() {
    size.w = 1600;
    size.h = 900;
    scale_factor = 1.0;
}

Renderer::~Renderer() {

}

void Renderer::init() {
    InitWindow(size.w, size.h, "Project ISO - Please find a name");
}

void Renderer::load_textures() {
    tileset_info.tile_size.w = 32;
    tileset_info.tile_size.h = 32;
    tileset_info.offsets.x = 32 / 2;
    tileset_info.offsets.y = 32 / 2;
    textures["grassfull"] = LoadTexture("../res/tiles/3232iso/grassfull.png");
    textures["dirtgrassfull"] = LoadTexture("../res/tiles/3232iso/dirtgrassfull.png");
    textures["dirtfull"] = LoadTexture("../res/tiles/3232iso/dirtfull.png");
    textures["stonefull"] = LoadTexture("../res/tiles/3232iso/stonefull.png");
    textures["waterfull"] = LoadTexture("../res/tiles/3232iso/waterfull.png");

    scale_factor = 2.0;
}

Texture2D& Renderer::get_texture_from_name(Tile& tile) {
    if (textures.find(tile.texture_name) != textures.end())
        return textures[tile.texture_name];

    else {
        std::cout << "[WARNING: texture \"" << tile.texture_name << "\" not in map.]" << std::endl;
        return (*textures.begin()).second;
    }
}

void Renderer::draw_map(Map& map) {
    mVec2<float> offset;
    Vector2 pos;
    Texture2D tex;
    offset.x = size.w / 2;
    offset.y = 10;

    for (Tile& tile: map.tiles) {
        tex = get_texture_from_name(tile);
        // screen offset + actual position - left offset
        pos.x =   offset.x + (tileset_info.offsets.x * scale_factor) * tile.pos.x
                - (scale_factor * tileset_info.offsets.x * tile.pos.y);
        // screen offset + actual position + top offset
        pos.y =   offset.y + ((scale_factor * tileset_info.offsets.y) - tileset_info.offsets.y) * tile.pos.y
                - (tile.pos.z * tileset_info.offsets.y)
                + ((scale_factor * tileset_info.offsets.y - tileset_info.offsets.y) * tile.pos.x);

        if (tile.fill_under && map.adjacent_diff_is_bigger_than(tile, 2)) {
            Vector2 fill_pos = pos;
            fill_pos.y += tileset_info.tile_size.h;
            DrawTextureEx(tex, fill_pos,0.0, scale_factor, WHITE);
        }

        DrawTextureEx(tex, pos,0.0, scale_factor, WHITE);




        /*DrawTexture(get_texture_from_name(tile),
                    offset.x - get_texture_from_name(tile).width/2,
                    offset.y - get_texture_from_name(tile).height/2,
                    WHITE);*/
    }
}