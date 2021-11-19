#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef __RUBIKSCUBE__H__
#define __RUBIKSCUBE__H__
#define NBACTION 12
typedef enum couleur {U='W',L='O',R='R',F='G',D='Y',B='B'} couleur;
typedef  couleur **Face;
typedef struct  {
    Face U;
    Face L;
    Face R;
    Face F;
    Face D;
    Face B;
} Cube;

extern void b(Cube *cube);
extern void f(Cube *cube);
extern void r(Cube *cube);
extern void l(Cube *cube);
extern void d(Cube *cube);
extern void u(Cube *cube);
extern void bp(Cube *cube);
extern void fp(Cube *cube);
extern void rp(Cube *cube);
extern void lp(Cube *cube);
extern void dp(Cube *cube);
extern void up(Cube *cube);
extern void rg(Face f);
extern void rd(Face f);
#endif  //!__RUBIKSCUBE__H__