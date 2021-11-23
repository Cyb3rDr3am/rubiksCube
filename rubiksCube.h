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

extern void b(Cube *);
extern void f(Cube *);
extern void r(Cube *);
extern void l(Cube *);
extern void d(Cube *);
extern void u(Cube *);
extern void bp(Cube *);
extern void fp(Cube *);
extern void rp(Cube *);
extern void lp(Cube *);
extern void dp(Cube *);
extern void up(Cube *);
extern void rg(Face );
extern void rd(Face );
#endif  //!__RUBIKSCUBE__H__