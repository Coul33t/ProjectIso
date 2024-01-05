//
// Created by couland-q on 03/01/2024.
//

#ifndef PROJECTISO_KSDL_H
#define PROJECTISO_KSDL_H

#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "constants.h"

 class KSDL {
public:
    KSDL();
    ~KSDL();
    bool init(int width, int height, std::string name="NO NAME");
    void destroy();

    SDL_Surface* getScreenSurface();
    SDL_Renderer* getRenderer();

    void drawSurface(SDL_Surface* to_draw, SDL_Rect& source_rect, SDL_Rect& target_rect);
    void drawTexture(SDL_Texture* texture, SDL_Rect& source_rect, SDL_Rect& target_rect);

    void SDLClearRenderer();
    void SDLRenderPresent();

    void update();

    void drawDEBUGSquares();
    void drawDEBUGGrid();


private:
    SDL_Window* window;
    SDL_Surface* screen_surface;
    SDL_Renderer* renderer;
};

#endif // PROJECTISO_KSDL_H