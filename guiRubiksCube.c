#include "guiRubiksCube.h"

void initGui(Cube *cube,maillon *m)
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
    if(TTF_Init() == -1)   
    {
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
    }
    SDL_bool program_launched = SDL_TRUE;
    annuleDeplace(cube,m);
    int cubeFinie = (m && m->prev)? 0:1;
    majWindow(cube,renderer,m,cubeFinie);
    SDL_Event event;
    while (program_launched) {
        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
              case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                  case SDLK_y:
                    next(cube,&m,renderer,&cubeFinie);
                    break;
                  case SDLK_z:
                    prev(cube,&m,renderer,&cubeFinie);
                    break;
                  default:
                    break;
                }
                break;
              case SDL_QUIT:
                program_launched = SDL_FALSE;
                break;
              default:
                break;
            }
        }
    } 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
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
void drawCube(Cube *cube, SDL_Renderer *r,maillon *m,int cubeFinie)
{
    SDL_Rect rect;
    rect.h = rect.w = HEIGHT_SQUARE;
    int x,y=PADDING;
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
            DRAWRECT(F);
        }
        y += HEIGHT_SQUARE + SPACE_SQUARE;
    }
    for (i = 0; i < 3; i++)
    {
        x = PADDING + 3 * (HEIGHT_SQUARE + SPACE_SQUARE);
        for (j = 0; j < 3; j++)
        {
            DRAWRECT(D);
        }
        y += HEIGHT_SQUARE + SPACE_SQUARE;
    }
    rect.h = 50;
    rect.w = 4*HEIGHT_SQUARE;
    SET_COLOR(r,CR);
    rect.x = x + 5 * (HEIGHT_SQUARE + SPACE_SQUARE);
    rect.y = y/2;
    SDL_RenderDrawRect(r, &rect);
    char txt[100];
    const char *prev;
    const char *next;
    if (cubeFinie) {
        if (m) {prev = m->mov;}
        else {prev = "";}
        next = "";
    }
    else {
        if (m) {
            if (m->next) prev = m->next->mov;
            else {prev = "";}
            next = m->mov;
        }
        else {
            next = "";
            prev = "";
        }
    }
    TTF_Font *police = NULL;
    SDL_Color textColor = { 255, 255, 255,255};
    police = TTF_OpenFont("font.otf",15);
    if (police == NULL) {
        fprintf(stderr, "Erreur d'initialisation la police : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    sprintf(txt,"next:%s\nprevius:%s\n",next,prev);
    SDL_Surface *texte = TTF_RenderText_Solid(police,txt, textColor);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(r,texte);
    SDL_QueryTexture(texture,NULL,NULL,&rect.w,&rect.h);
    SDL_RenderCopy(r,texture,NULL,&rect);
    SDL_FreeSurface(texte);
    TTF_CloseFont(police);

}
void majWindow(Cube *cube,SDL_Renderer *renderer,maillon *m,int cubeFinie) {
    SET_COLOR(renderer,CN);
    if (SDL_RenderClear(renderer) != 0) {
        SDL_ExitWithError("cube drawing fail");
    }
    drawCube(cube,renderer,m,cubeFinie);
    SDL_RenderPresent(renderer);
}
void sToRor(Cube *cube,const char *mov) {
    if (!strcmp(mov,"F")) {f(cube);}
    else if (!strcmp(mov,"B")) {b(cube);}
    else if (!strcmp(mov,"L")) {l(cube);}
    else if (!strcmp(mov,"R")) {r(cube);}
    else if (!strcmp(mov,"U")) {u(cube);}
    else if (!strcmp(mov,"D")) {d(cube);}
    else if (!strcmp(mov,"F'")) {fp(cube);}
    else if (!strcmp(mov,"B'")) {bp(cube);}
    else if (!strcmp(mov,"L'")) {lp(cube);}
    else if (!strcmp(mov,"R'")) {rp(cube);}
    else if (!strcmp(mov,"U'")) {up(cube);}
    else if (!strcmp(mov,"D'")) {dp(cube);}
    else if (!strcmp(mov,"F2")) {f(cube);f(cube);}
    else if (!strcmp(mov,"B2")) {b(cube);b(cube);}
    else if (!strcmp(mov,"L2")) {l(cube);l(cube);}
    else if (!strcmp(mov,"R2")) {r(cube);r(cube);}
    else if (!strcmp(mov,"U2")) {u(cube);u(cube);}
    else if (!strcmp(mov,"D2")) {d(cube);d(cube);}
}
void sToRorI(Cube *cube,const char *mov) {
    if (!strcmp(mov,"F")) {fp(cube);}
    else if (!strcmp(mov,"B")) {bp(cube);}
    else if (!strcmp(mov,"L")) {lp(cube);}
    else if (!strcmp(mov,"R")) {rp(cube);}
    else if (!strcmp(mov,"U")) {up(cube);}
    else if (!strcmp(mov,"D")) {dp(cube);}
    else if (!strcmp(mov,"F'")) {f(cube);}
    else if (!strcmp(mov,"B'")) {b(cube);}
    else if (!strcmp(mov,"L'")) {l(cube);}
    else if (!strcmp(mov,"R'")) {r(cube);}
    else if (!strcmp(mov,"U'")) {u(cube);}
    else if (!strcmp(mov,"D'")) {d(cube);}
    else if (!strcmp(mov,"F2")) {f(cube);f(cube);}
    else if (!strcmp(mov,"B2")) {b(cube);b(cube);}
    else if (!strcmp(mov,"L2")) {l(cube);l(cube);}
    else if (!strcmp(mov,"R2")) {r(cube);r(cube);}
    else if (!strcmp(mov,"U2")) {u(cube);u(cube);}
    else if (!strcmp(mov,"D2")) {d(cube);d(cube);}
}
void annuleDeplace(Cube *cube,maillon *m) {
    while (m->prev!=NULL) m = m->prev;
    while (m!=NULL) {
        sToRorI(cube,m->mov);
        m = m->next;
    }
}
void next(Cube *cube,maillon **m,SDL_Renderer *r,int *cubeFini) {
    if (*cubeFini == 0) {
        sToRor(cube,(*m)->mov);
        if ((*m)->prev) {
            *m = (*m)->prev;
        }
        else {*cubeFini = 1;}
        majWindow(cube,r,*m,*cubeFini);
    }
}
void prev(Cube *cube,maillon **m,SDL_Renderer *r,int *cubeFini) {
    if (*m && (*m)->next) {
        if (*cubeFini == 1) {
            sToRorI(cube,(*m)->mov);
            *cubeFini = 0;
        }
        else {
            *m = (*m)->next;
            sToRorI(cube,(*m)->mov);
        }
        majWindow(cube,r,*m,*cubeFini);
    }
}