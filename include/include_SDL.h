#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
#elif defined(_WIN32) || defined(WIN32) || defined(_WIN64)
    #include <SDL.h>
    #include <SDL_image.h>
#endif