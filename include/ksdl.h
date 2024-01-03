#ifndef PROJECTISO_KSDL_H
#define PROJECTISO_KSDL_H

#include <iostream>
#include <string>

#include <SDL.h>

 class KSDL {
public:
    KSDL();
    ~KSDL();
    bool init(int width, int height, std::string name="NO NAME");
    void destroy();

private:
    SDL_Window* window;
    SDL_Surface* screen_surface;
};

#endif // PROJECTISO_KSDL_H