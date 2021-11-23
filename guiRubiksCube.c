#include "guiRubiksCube.h"
#include "rubiksCube.h"
void init() {
    SDL_Window *window;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("erreur initialisation SDL > %s\n",SDL_GetError());
        exit(EXIT_FAILURE);
    }
    window = SDL_CreateWindow("Rubiks cube",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH_WINDOW,HEIGHT_WINDOW,0);
    SDL_Quit();
}
int main(void) {
    init();
}