#include "guiRubiksCube.h"
#include "rubiksCube.h"

void initGui(Cube *cube)
{
    SDL_Window *window;
    SDL_Renderer *renderer = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_ExitWithError("SDL initialization  fail");
    }
    window = SDL_CreateWindow("Rubiks cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH_WINDOW, HEIGHT_WINDOW, 0);
    if (!window)
    {
        SDL_ExitWithError("Window initialization fail");
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer)
    {
        SDL_ExitWithError("Window initialization fail");
    }
    drawCube(cube,renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void SDL_ExitWithError(const char *msg)
{
    SDL_Log("ERROR : %s > %s\n", msg, SDL_GetError());
    SDL_Quit();
    exit(1);
}
void setCouleurFace(couleur c, SDL_Renderer *r)
{
    switch (c)
    {
    case U:
        SET_COLOR(r, CW);
        break;
    case F:
        SET_COLOR(r, CG);
        break;
    case L:
        SET_COLOR(r, CO);
        break;
    case R:
        SET_COLOR(r, CR);
        break;
    case B:
        SET_COLOR(r, CB);
        break;
    case D:
        SET_COLOR(r, CY);
        break;
    default:
        break;
    }
}
void drawCube(Cube *cube, SDL_Renderer *r)
{
    SDL_Rect rect;
    rect.h = rect.w = HEIGHT_SQUARE;
    int x,y=0;
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        x = PADDING + 3 * (HEIGHT_SQUARE + SPACE_SQUARE);
        for (j = 0; j < 3; j++)
        {
            DRAWRECT(B);
        }
        y += HEIGHT_SQUARE + SPACE_SQUARE;
    }
    x = PADDING;
    for (i=0;i<3;i++) {
        for (k=0;k<3;k++) {
            for(j=0;j<3;j++) {
                if (k==0) {
                    DRAWRECT(L);
                }
                else if (k==1) {
                    DRAWRECT(U);                   
                }
                else {
                    DRAWRECT(R); 
                }
            }
        }
        y += HEIGHT_SQUARE + SPACE_SQUARE;
        x = PADDING;
    }
    for (i = 0; i < 3; i++)
    {
        x = PADDING + 3 * (HEIGHT_SQUARE + SPACE_SQUARE);
        for (j = 0; j < 3; j++)
        {
            rect.x = x;
            rect.y = y;
            x += HEIGHT_SQUARE + SPACE_SQUARE;
            setCouleurFace((cube->F)[i][j],r);
            SDL_RenderDrawRect(r, &rect);
            SDL_RenderFillRect(r, &rect);
        }
        y += HEIGHT_SQUARE + SPACE_SQUARE;
    }
    for (i = 0; i < 3; i++)
    {
        x = PADDING + 3 * (HEIGHT_SQUARE + SPACE_SQUARE);
        for (j = 0; j < 3; j++)
        {
            rect.x = x;
            rect.y = y;
            x += HEIGHT_SQUARE + SPACE_SQUARE;
            setCouleurFace((cube->D)[i][j],r);
            SDL_RenderDrawRect(r, &rect);
            SDL_RenderFillRect(r, &rect);
        }
        y += HEIGHT_SQUARE + SPACE_SQUARE;
    }
}