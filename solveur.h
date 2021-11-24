#ifndef __SOLVEUR__H__
#define __SOLVEUR__H__
#include "rubiksCube.h"
#include "listMovement.h"
#define elif else if
#define F() f(cube);append_mov(liste,"F")
#define R() r(cube);append_mov(liste,"R")
#define L() l(cube);append_mov(liste,"L")
#define B() b(cube);append_mov(liste,"B")
#define U() u(cube);append_mov(liste,"U")
#define D() d(cube);append_mov(liste,"D")
#define FP() fp(cube);append_mov(liste,"F'")
#define RP() rp(cube);append_mov(liste,"R'")
#define LP() lp(cube);append_mov(liste,"L'")
#define BP() bp(cube);append_mov(liste,"B'")
#define UP() up(cube);append_mov(liste,"U'")
#define DP() dp(cube);append_mov(liste,"D'")
#define F2() f(cube),f(cube);append_mov(liste,"F2")
#define R2() r(cube),r(cube);append_mov(liste,"R2")
#define L2() l(cube),l(cube);append_mov(liste,"L2")
#define B2() b(cube),b(cube);append_mov(liste,"B2")
#define U2() u(cube),u(cube);append_mov(liste,"U2")
#define D2() d(cube),d(cube);append_mov(liste,"D2")
#define CFL()   (((cube->D)[0][0] == D || (cube->D)[0][0] == F || (cube ->D)[0][0] == L) && ((cube->F)[2][0] == F || (cube->F)[2][0] == L || (cube->F)[2][0] == D) && ((cube->L)[2][0] == L || (cube->L)[2][0] == F || (cube->L)[2][0] == D))
#define CFR()   (((cube->D)[0][2] == D || (cube->D)[0][2] == F || (cube ->D)[0][2] == R) && ((cube->F)[2][2] == F || (cube->F)[2][2] == R || (cube->F)[2][2] == D) && ((cube->R)[2][2] == R || (cube->R)[2][2] == F || (cube->R)[2][2] == D))
#define CBL()   (((cube->D)[2][0] == D || (cube->D)[2][0] == B || (cube ->D)[2][0] == L) && ((cube->B)[0][0] == B || (cube->B)[0][0] == L || (cube->B)[0][0] == D) && ((cube->L)[0][0] == L || (cube->L)[0][0] == B || (cube->L)[0][0] == D))
#define CBR()   (((cube->D)[2][2] == D || (cube->D)[2][2] == B || (cube ->D)[2][2] == R) && ((cube->B)[0][2] == B || (cube->B)[0][2] == R || (cube->B)[0][2] == D) && ((cube->R)[0][2] == R || (cube->R)[0][2] == B || (cube->R)[0][2] == D))
extern void croix_up(Cube *,listMouvement *);
extern void coin_up(Cube *,listMouvement *);
extern void F2L(Cube *,listMouvement *);
extern void croix_down(Cube *,listMouvement *);
extern void edge_down(Cube *,listMouvement *);
extern void corner_down(Cube *,listMouvement *);
extern void orient_down(Cube *,listMouvement *);
extern void solve_cube(Cube *);
#endif  //!__SOLVEUR__H__