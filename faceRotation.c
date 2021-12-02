#include "rubiksCube.h"
//rotate face to right
void rd(Face f) {
    int i,j;
    couleur oldF[3][3];
    for (i=0;i<3;i++)  {
        for (j=0;j<3;j++) {
            oldF[i][j] = f[i][j];
        }
    }
    for (i=0;i<3;i++)  {
        for (j=0;j<3;j++) {
            f[i][j] = oldF[j][2-i];
        }
    }   
}
//rotate face to left
void rg(Face f) {
    int i,j;
    couleur oldF[3][3];
    for (i=0;i<3;i++)  {
        for (j=0;j<3;j++) {
            oldF[i][j] = f[i][j];
        }
    }
    for (i=0;i<3;i++)  {
        for (j=0;j<3;j++) {
            f[i][j] = oldF[2-j][i];
        }
    }
}
//do U mov
void u(Cube *cube) {
    couleur l1[3],l2[3],l3[3],l4[3];
    int i;
    for (i=0;i<3;i++) {
        l1[i]=(cube->F)[0][i];
        l2[i]=(cube->L)[i][2];
        l3[i]=(cube->B)[2][i];
        l4[i]=(cube->R)[i][0];
    }
    for (i=0;i<3;i++) {
        (cube->L)[i][2] = l1[i];
        (cube->B)[2][i] = l2[2-i];
        (cube->R)[i][0] = l3[i];
        (cube->F)[0][i] = l4[2-i];
    }
    rg(cube->U);
}
//do U' mov
void up(Cube *cube) {
    couleur l1[3],l2[3],l3[3],l4[3];
    int i;
    for (i=0;i<3;i++) {
        l1[i]=(cube->F)[0][i];
        l2[i]=(cube->L)[i][2];
        l3[i]=(cube->B)[2][i];
        l4[i]=(cube->R)[i][0];
    }
    for (i=0;i<3;i++) {
        (cube->L)[i][2] = l3[2-i];
        (cube->B)[2][i] = l4[i];
        (cube->R)[i][0] = l1[2-i];
        (cube->F)[0][i] = l2[i];
    }
    rd(cube->U);
}
//do D mov
void d(Cube *cube) {
    couleur l1[3],l2[3],l3[3],l4[3];
    int i;
    for (i=0;i<3;i++) {
        l1[i]=(cube->F)[2][i];
        l2[i]=(cube->L)[i][0];
        l3[i]=(cube->B)[0][i];
        l4[i]=(cube->R)[i][2];
    }
    for (i=0;i<3;i++) {
        (cube->L)[i][0] = l3[2-i];
        (cube->B)[0][i] = l4[i];
        (cube->R)[i][2] = l1[2-i];
        (cube->F)[2][i] = l2[i];
    }
    rg(cube->D);
}
//do D' mov
void dp(Cube *cube) {
    couleur l1[3],l2[3],l3[3],l4[3];
    int i;
    for (i=0;i<3;i++) {
        l1[i]=(cube->F)[2][i];
        l2[i]=(cube->L)[i][0];
        l3[i]=(cube->B)[0][i];
        l4[i]=(cube->R)[i][2];
    }
    for (i=0;i<3;i++) {
        (cube->L)[i][0] = l1[i];
        (cube->B)[0][i] = l2[2-i];
        (cube->R)[i][2] = l3[i];
        (cube->F)[2][i] = l4[2-i];
    }
    rd(cube->D);
}
//do L mov
void l(Cube *cube) {
    couleur c1[3],c2[3],c3[3],c4[3];
    int i;
    for (i=0;i<3;i++) {
        c1[i]=(cube->B)[i][0];
        c2[i]=(cube->U)[i][0];
        c3[i]=(cube->F)[i][0];
        c4[i]=(cube->D)[i][0];
    }
    for (i=0;i<3;i++) {
        (cube->U)[i][0] = c1[i]; 
        (cube->F)[i][0] = c2[i];
        (cube->D)[i][0] = c3[i];
        (cube->B)[i][0] = c4[i];
    }
    rg(cube->L);
}
//do L' mov
void lp(Cube *cube) {
    couleur c1[3],c2[3],c3[3],c4[3];
    int i;
    for (i=0;i<3;i++) {
        c1[i]=(cube->B)[i][0];
        c2[i]=(cube->U)[i][0];
        c3[i]=(cube->F)[i][0];
        c4[i]=(cube->D)[i][0];
    }
    for (i=0;i<3;i++) {
        (cube->U)[i][0] = c3[i]; 
        (cube->F)[i][0] = c4[i];
        (cube->D)[i][0] = c1[i];
        (cube->B)[i][0] = c2[i];
    }
    rd(cube->L);
}
//do R mov
void r(Cube *cube) {
    couleur c1[3],c2[3],c3[3],c4[3];
    int i;
    for (i=0;i<3;i++) {
        c1[i]=(cube->B)[i][2];
        c2[i]=(cube->U)[i][2];
        c3[i]=(cube->F)[i][2];
        c4[i]=(cube->D)[i][2];
    }
        for (i=0;i<3;i++) {
        (cube->U)[i][2] = c3[i]; 
        (cube->F)[i][2] = c4[i];
        (cube->D)[i][2] = c1[i];
        (cube->B)[i][2] = c2[i];
    }
    rg(cube->R);
}
//do R' mov
void rp(Cube *cube) {
    couleur c1[3],c2[3],c3[3],c4[3];
    int i;
    for (i=0;i<3;i++) {
        c1[i]=(cube->B)[i][2];
        c2[i]=(cube->U)[i][2];
        c3[i]=(cube->F)[i][2];
        c4[i]=(cube->D)[i][2];
    }
    for (i=0;i<3;i++) {
        (cube->U)[i][2] = c1[i]; 
        (cube->F)[i][2] = c2[i];
        (cube->D)[i][2] = c3[i];
        (cube->B)[i][2] = c4[i];
    }
    rd(cube->R);
}
//do F mov
void f(Cube *cube) {
    couleur c1[3],c2[3],c3[3],c4[3];
    int i;
    for (i=0;i<3;i++) {
        c1[i] = (cube->L)[2][i];
        c2[i] = (cube->U)[2][i];
        c3[i] = (cube->R)[2][i];
        c4[i] = (cube->D)[0][i];
    }
    for (i=0;i<3;i++) {
        (cube->L)[2][i] = c4[2-i];
        (cube->U)[2][i] = c1[i];
        (cube->R)[2][i] = c2[i];
        (cube->D)[0][i] = c3[2-i];
    }
    rg(cube->F);
}
//do F' mov
void fp(Cube *cube) {
    couleur c1[3],c2[3],c3[3],c4[3];
    int i;
    for (i=0;i<3;i++) {
        c1[i] = (cube->L)[2][i];
        c2[i] = (cube->U)[2][i];
        c3[i] = (cube->R)[2][i];
        c4[i] = (cube->D)[0][i];
    }
    for (i=0;i<3;i++) {
        (cube->L)[2][i] = c2[i];
        (cube->U)[2][i] = c3[i];
        (cube->R)[2][i] = c4[2-i];
        (cube->D)[0][i] = c1[2-i];
    }
    rd(cube->F);
}
//do B mov
void b(Cube *cube) {
    couleur c1[3],c2[3],c3[3],c4[3];
    int i;
    for (i=0;i<3;i++) {
        c1[i] = (cube->L)[0][i];
        c2[i] = (cube->U)[0][i];
        c3[i] = (cube->R)[0][i];
        c4[i] = (cube->D)[2][i];
    }
    for (i=0;i<3;i++) {
        (cube->L)[0][i] = c2[i];
        (cube->U)[0][i] = c3[i];
        (cube->R)[0][i] = c4[2-i];
        (cube->D)[2][i] = c1[2-i];
    }
    rg(cube->B);
}
//do B' mov
void bp(Cube *cube) {
    couleur c1[3],c2[3],c3[3],c4[3];
    int i;
    for (i=0;i<3;i++) {
        c1[i] = (cube->L)[0][i];
        c2[i] = (cube->U)[0][i];
        c3[i] = (cube->R)[0][i];
        c4[i] = (cube->D)[2][i];
    }
    for (i=0;i<3;i++) {
        (cube->L)[0][i] = c4[2-i];
        (cube->U)[0][i] = c1[i];
        (cube->R)[0][i] = c2[i];
        (cube->D)[2][i] = c3[2-i];
    }
    rd(cube->B);
}