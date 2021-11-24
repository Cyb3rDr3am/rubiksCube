#ifndef __GUIRUBIKSCUBE__H__
#define __GUIRUBIKSCUBE__H__
#include <SDL.h>
#include "rubiksCube.h"
#include <stdio.h>
#include <stdlib.h>
#define PADDING 20
#define HEIGHT_SQUARE 40
#define HEIGHT_WINDOW HEIGHT_SQUARE * 12 + PADDING
#define WIDTH_WINDOW HEIGHT_SQUARE*12 + PADDING
#define CW 255,255,255,SDL_ALPHA_OPAQUE
#define CR 255,0,0,SDL_ALPHA_OPAQUE
#define CG 0,255,0,SDL_ALPHA_OPAQUE
#define CB 0,0,255,SDL_ALPHA_OPAQUE
#define CY 255,255,0,SDL_ALPHA_OPAQUE  
#define CO 255,165,0,SDL_ALPHA_OPAQUE
extern void  init();
extern void  SDL_ExitWithError(const char *);
extern void drawCube(Cube *,SDL_Renderer *);
#endif  //!__GUIRUBIKSCUBE__H__