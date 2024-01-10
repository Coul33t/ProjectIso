//
// Created by couland-q on 03/01/2024.
//

#include "../include/ksdl.h"

KSDL::KSDL() {
    this->window = nullptr;
    this->screen_surface = nullptr;
    this->font = nullptr;
}

KSDL::~KSDL() {
    
}

bool KSDL::init(int width, int height, std::string name) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize. SDL_Error: " <<  SDL_GetError() << std::endl;
        return false;
    }

    // Create window
    this->window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(this->window == nullptr) {
        std::cout << "Window could not be created. SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

        
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) {
        std::cout << "Renderer could not be created. SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Load PNG
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags)) {
        std::cout << "SDL_image could not initialize. SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    // Initialize SDL_ttf
    if(TTF_Init() == -1) {
        std::cout << "SDL_ttf could not initialize. SDL_ttf Error: " << TTF_GetError() << std::endl;
        return false;
    }

    if (!loadTTF()) {
        return false;
    }

    this->screen_surface = SDL_GetWindowSurface(this->window);
    
    return true;
}

bool KSDL::loadTTF() {
    this->font = TTF_OpenFont("../res/fonts/OldePixel.ttf", 28);
    
    if(this->font == nullptr) {
        std::cout << "Failed to load font. SDL_ttf Error: " << TTF_GetError() << std::endl;
        return false;
    }

    return true;
}

SDL_Surface* KSDL::getScreenSurface() {
    return this->screen_surface;
}

SDL_Renderer* KSDL::getRenderer() {
    return this->renderer;
}

void KSDL::drawSurface(SDL_Surface* to_draw, SDL_Rect& source_rect, SDL_Rect& target_rect) {
    SDL_BlitSurface(to_draw, &source_rect, this->screen_surface, &target_rect);
}

void KSDL::drawTexture(SDL_Texture* texture, SDL_Rect& source_rect, SDL_Rect& target_rect) {
    SDL_RenderCopy(this->renderer, texture, &source_rect, &target_rect);
}

void KSDL::renderText(const std::string& text, const mVec2<int>& pos, const SDL_Color& colour) {
    SDL_Surface* text_surface = TTF_RenderText_Solid(this->font, text.c_str(), colour);

    if(text_surface == NULL) {
        std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return;
    }

    else {
        SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, text_surface);
        
        SDL_Rect pos_rect;
        pos_rect.x = pos.x;
        pos_rect.y = pos.y;
        pos_rect.w = text_surface->w;
        pos_rect.h = text_surface->h;

        SDL_RenderCopy(this->renderer, text, nullptr, &pos_rect);
    }
}

void KSDL::drawDEBUGSquares() {
    Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(this->renderer, &r, &g, &b, &a);

    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_Rect rect{32, 32, 32, 32};
    SDL_RenderFillRect(this->renderer, &rect);

    SDL_SetRenderDrawColor(this->renderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_Rect rect2{this->screen_surface->w - 64, this->screen_surface->h - 64, 32, 32};
    SDL_RenderFillRect(this->renderer, &rect2);

    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_Rect rect3{this->screen_surface->w - 64, 32, 32, 32};
    SDL_RenderFillRect(this->renderer, &rect3);

    SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0x00, 0xFF);
    SDL_Rect rect4{32, this->screen_surface->h - 64, 32, 32};
    SDL_RenderFillRect(this->renderer, &rect4);

    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

void KSDL::drawDEBUGGrid() {
    Uint8 r, g, b, a;
    SDL_GetRenderDrawColor(this->renderer, &r, &g, &b, &a);
    SDL_SetRenderDrawColor(this->renderer, 0x55, 0x55, 0x55, 0xFF);

    for (int i = 32; i < this->screen_surface->w; i += 32) {
        SDL_RenderDrawLine(this->renderer, i, 0, i, this->screen_surface->h);
    }

    for (int i = 32; i < this->screen_surface->h; i += 32) {
        SDL_RenderDrawLine(this->renderer, 0, i, this->screen_surface->w, i);
    }

    SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

void KSDL::SDLClearRenderer() {
    SDL_RenderClear(this->renderer);
}

void KSDL::SDLRenderPresent() {
    SDL_RenderPresent(this->renderer);
}

void KSDL::update() {
    
    int frame_start = SDL_GetTicks();
    //drawDEBUGSquares();
    //drawDEBUGGrid();
    
    int frame_time = SDL_GetTicks() - frame_start;

    if (Constants::TARGET_FRAME_DELAY_MS > frame_time) {
        SDL_Delay(Constants::TARGET_FRAME_DELAY_MS - frame_time);
    }

    //SDL_UpdateWindowSurface(this->window);


}

void KSDL::destroy() {
    //Destroy window (and the screen_surface too)
    SDL_DestroyWindow(this->window);
    this->window = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}