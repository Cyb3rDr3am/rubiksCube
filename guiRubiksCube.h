#ifndef __GUIRUBIKSCUBE__H__
#define __GUIRUBIKSCUBE__H__
#include <SDL.h>
#include "rubiksCube.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listMovement.h"
#include <SDL2/SDL_ttf.h>
#define PADDING 110
#define HEIGHT_SQUARE 40
#define SPACE_SQUARE 2
#define HEIGHT_WINDOW (HEIGHT_SQUARE+SPACE_SQUARE) * 15 + PADDING
#define WIDTH_WINDOW (HEIGHT_SQUARE+SPACE_SQUARE)*15 + PADDING
#define CW 255,255,255,SDL_ALPHA_OPAQUE
#define CR 255,0,0,SDL_ALPHA_OPAQUE
#define CG 0,255,0,SDL_ALPHA_OPAQUE
#define CB 0,0,255,SDL_ALPHA_OPAQUE
#define CY 255,255,0,SDL_ALPHA_OPAQUE  
#define CO 255,165,0,SDL_ALPHA_OPAQUE
#define CN 0,0,0,SDL_ALPHA_OPAQUE
#define DRAWRECT(f)  rect.x = x; \
            rect.y = y;\
            x += HEIGHT_SQUARE + SPACE_SQUARE;\
            setCouleurFace((cube->f )[i][j],r);\
            if (SDL_RenderDrawRect(r, &rect) != 0) {\
                SDL_ExitWithError("cube drawing fail");\
            };\
            if (SDL_RenderFillRect(r, &rect) != 0) {\
                SDL_ExitWithError("cube drawing fail");\
            }
#define SET_COLOR(r,c) if (SDL_SetRenderDrawColor(r,c) != 0) {\
    SDL_ExitWithError("cube initialization fail");\
}
extern void  initGui();
extern void  SDL_ExitWithError(const char *);
extern void drawCube(Cube *,SDL_Renderer *,maillon *,int);
extern void setCouleurFace(couleur,SDL_Renderer *);
extern void majWindow(Cube *,SDL_Renderer *,maillon *,int);
extern void sToRor(Cube *,const char *);
extern void sToRorI(Cube *,const char *);
extern void annuleDeplace(Cube *,maillon *);
extern void next(Cube *,maillon **,SDL_Renderer *,int *);
extern void prev(Cube *,maillon **,SDL_Renderer *,int *);
#endif  //!__GUIRUBIKSCUBE__H__