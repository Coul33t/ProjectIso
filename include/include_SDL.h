#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
    #include <SDL3/SDL.h>
    #include <SDL3_image/SDL_image.h>
    #include <SDL3_ttf/SDL_ttf.h>
#elif defined(_WIN32) || defined(WIN32) || defined(_WIN64)
    #include <SDL3/SDL.h>
    #include <SDL3_image/SDL_image.h>
    #include <SDL3_ttf/SDL_ttf.h>
#endif