#ifndef __SOLVEUR__H__
#define __SOLVEUR__H__
#include "rubiksCube.h"
typedef struct listMouvement {
    const char *mov;
    struct listMouvement *next;
} listMouvement;
extern void croix_up(Cube *cube,listMouvement **liste);
extern void coin_up(Cube *cube,listMouvement **liste);
extern void F2L(Cube *cube,listMouvement **liste);
extern void croix_down(Cube *cube,listMouvement **liste);
extern void edge_down(Cube *cube,listMouvement **liste);
extern void corner_down(Cube *cube,listMouvement **liste);
extern void orient_down(Cube *cube,listMouvement **liste);
extern void solve_cube(Cube *cube);
extern void append_mov(listMouvement **liste,const char *mov);
extern void affiche_mov(listMouvement *liste);
#endif  //!__SOLVEUR__H__