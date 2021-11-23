#include "guiRubiksCube.h"
#include "rubiksCube.h"
void init(Cube *cube) {
    SDL_Window *window;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LOG("erreur initialisation SDL > %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    window = SDL_CreateWindow("Rubiks cube",0,0,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH_WINDOW,HEIGHT_WINDOW);
    SDL_Quit();
}