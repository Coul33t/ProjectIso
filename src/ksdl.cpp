#include "../include/ksdl.h"

KSDL::KSDL() {
    window = nullptr;
    screen_surface = nullptr;
}

KSDL::~KSDL() {
    
}

bool KSDL::init(int width, int height, std::string name) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " <<  SDL_GetError() << std::endl;
        return false;
    }

    else {
        //Create window
        window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if(window == NULL) {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            return false;
        }

        else {
            screen_surface = SDL_GetWindowSurface(window);
        }
    }

    return true;
}

void KSDL::destroy() {
    //Destroy window
    SDL_DestroyWindow(window);

    //Quit SDL subsystems
    SDL_Quit();
}