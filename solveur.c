#include "solveur.h"
/*réalise la croix de la face du haut*/
void croix_up(Cube *cube,listMouvement *liste) {
    while ((cube->U)[0][1] != U || (cube->U)[1][0] != U || (cube->U)[1][2] != U || (cube->U)[2][1] != U
    || (cube -> F)[0][1] != F || (cube -> L)[1][2] != L || (cube->R)[1][0] != R || (cube->B)[2][1] != B)
    {
        if ( (cube -> D)[0][1] == U && (cube -> F)[2][1] == F) {F2();}
        elif ( (cube -> D)[1][2] == U && (cube -> R)[1][2] == R) {R2();}
        elif ( (cube -> D)[1][0] == U && (cube -> L)[1][0] == L) {L2();}
        elif ( (cube -> D)[2][1] == U && (cube -> B)[0][1] == B) {B2();}
        elif ( (cube -> D)[0][1] == R && (cube -> F)[2][1] == U) {FP();R();}
        elif ( (cube -> D)[0][1] == L && (cube -> F)[2][1] == U) {F();L();}
        elif ( (cube -> D)[1][2] == F && (cube -> R)[1][2] == U) {R();FP();}
        elif ( (cube -> D)[1][2] == B && (cube -> R)[1][2] == U) {RP();B();}
        elif ( (cube -> D)[1][0] == F && (cube -> L)[1][0] == U) {LP();F();}
        elif ( (cube -> D)[1][0] == B && (cube -> L)[1][0] == U) {L();BP();}
        elif ( (cube -> D)[2][1] == L && (cube -> B)[0][1] == U) {BP();L();}
        elif ( (cube -> D)[2][1] == R && (cube -> B)[0][1] == U) {B();RP();}
        elif ((cube->F)[1][0] == U || (cube->L)[2][1] == U) {L();D();LP();}
        elif ((cube->F)[1][2] == U || (cube->R)[2][1] == U) {RP();D();R();}
        elif ((cube->B)[1][0] == U || (cube->L)[0][1] == U) {LP();D();L();}
        elif ((cube->B)[1][2] == U || (cube->R)[0][1] == U) {R();D();RP();}
        elif ( (cube -> B)[2][1] == U || ((cube->U)[0][1] == U && (cube -> B)[2][1] != B)) {B2();D();}
        elif ( (cube -> L)[1][2] == U  || ((cube -> U)[1][0] == U && (cube -> L)[1][2] != L)   ) {L2();D();}
        elif ( (cube -> R)[1][0] == U || ((cube -> U)[1][2] == U && (cube -> R)[1][0] != R) ) {R2();D();}
        elif ( (cube -> F)[0][1] == U || ((cube -> U)[2][1] == U && (cube -> F)[0][1] != F)  ) {F2();D();}
        else {D();}
    }
}
//met les coins blancs a leur place
void coin_up(Cube *cube,listMouvement *liste) {
    while ((cube->U)[0][0] != U|| (cube->U)[0][2] != U || (cube->U)[2][0] != U||(cube->U)[2][2] != U
    || (cube->L)[0][2] !=L || (cube->L)[2][2] != L || (cube->F)[0][0] !=  F || (cube->F)[0][2] != F ||
    (cube->R)[0][0] != R || (cube->R)[2][0] != R || (cube->B)[2][0] != B || (cube->B)[2][2] != B) {
        if ( (cube->F)[2][2] == F && (cube->R)[2][2] == U && (cube->D)[0][2] == R) {RP();DP();R();}
        elif ( (cube->F)[2][2] == U && (cube->R)[2][2] == R && (cube->D)[0][2] == F) {F();D();FP();}
        elif ( (cube->F)[2][2] == R && (cube->R)[2][2] == F && (cube->D)[0][2] == U) {R2();DP();R2();D();R2();}
        elif ( (cube->L)[2][0] == L && (cube->F)[2][0] == U && (cube->D)[0][0] == F) {FP();DP();F();}
        elif ( (cube->L)[2][0] == U && (cube->F)[2][0] == F && (cube->D)[0][0] == L) {L();D();LP();}
        elif ( (cube->L)[2][0] == F && (cube->F)[2][0] == L && (cube->D)[0][0] == U) {F2();DP();F2();D();F2();}
        elif ( (cube->R)[0][2] == R && (cube->B)[0][2] == U && (cube->D)[2][2] == B) {BP();DP();B();}
        elif ( (cube->R)[0][2] == U && (cube->B)[0][2] == B && (cube->D)[2][2] == R) {R();D();RP();}
        elif ( (cube->R)[0][2] == B && (cube->B)[0][2] == R && (cube->D)[2][2] == U) {B2();DP();B2();D();B2();}
        elif ( (cube->B)[0][0] == B && (cube->L)[0][0] == U && (cube->D)[2][0] == L) {LP();DP();L();}
        elif ( (cube->B)[0][0] == U && (cube->L)[0][0] == L && (cube->D)[2][0] == B) {B();D();BP();}
        elif ( (cube->B)[0][0] == L && (cube->L)[0][0] == B && (cube->D)[2][0] == U) {L2();DP();L2();D();L2();}
        elif ( (cube->F)[0][0] == U || (cube->L)[2][2] == U || ( (cube->U)[2][0] == U && (cube->F)[0][0] != F) ) {L();D();LP();}
        elif ( (cube->F)[0][2] == U || (cube->R)[2][0] == U|| ( (cube->U)[2][2] == U && (cube->F)[0][2] != F) ) {RP();D();R();}
        elif ( (cube->B)[2][0] == U ||  (cube->L)[0][2] == U || ( (cube->U)[0][0] == U && (cube->B)[2][0] != B) ) {LP();D();L();}
        elif ( (cube->B)[2][2] == U || (cube->R)[0][0] == U || ( (cube->U)[0][2] == U && (cube->B)[2][2] != B) ) {R();D();RP();}
        else {D();}
    }
}
//forme la 2 deuxieme couche
void F2L(Cube *cube,listMouvement *liste) {
    while ( (cube->F)[1][2] != F || (cube->F)[1][0] != F || (cube->B)[1][0] != B || (cube->B)[1][2] != B ||
    (cube->R)[2][1] != R || (cube->R)[0][1] != R ||(cube->L)[2][1] != L || (cube->L)[0][1] != L) {
        if ( (cube->F)[2][1] == F && (cube->D)[0][1] == R) {DP();RP();D();R();D();F();DP();FP();}
        elif ( (cube->F)[2][1] == F && (cube->D)[0][1] == L) {D();L();DP();LP();DP();FP();D();F();}

        elif ( (cube->B)[0][1] == B && (cube->D)[2][1] == L) {DP();LP();D();L();D();B();DP();BP();}
        elif ( (cube->B)[0][1] == B && (cube->D)[2][1] == R) {D();R();DP();RP();DP();BP();D();B();}

        elif ( (cube->L)[1][0] == L && (cube->D)[1][0] == F) {DP();FP();D();F();D();L();DP();LP();}
        elif ( (cube->L)[1][0] == L && (cube->D)[1][0] == B) {D();B();DP();BP();DP();LP();D();L();}
        
        elif ( (cube->R)[1][2] == R && (cube->D)[1][2] == F) {D();F();DP();FP();DP();RP();D();R();}
        elif ( (cube->R)[1][2] == R && (cube->D)[1][2] == B) {DP();BP();D();B();D();R();DP();RP();}

        elif (  ((cube->F)[1][2] != F || (cube->R)[2][1] != R)  && (cube->F)[1][2] != D && (cube->R)[2][1]!=D) {
            DP();RP();D();R();D();F();DP();FP();
        }
        elif (  ((cube->F)[1][0] != F || (cube->L)[2][1] != L)  && (cube->F)[1][0] != D && (cube->L)[2][1] != D) {
            D();L();DP();LP();DP();FP();D();F();
        }
        elif ( ((cube->B)[1][2] != B || (cube->R)[0][1] != R)   && (cube->B)[1][2] != D && (cube->R)[0][1] != D){
            D();R();DP();RP();DP();BP();D();B();
        }
        elif ( ((cube->B)[1][0] != B || (cube->L)[0][1] != L) && (cube->B)[1][0] != D && (cube->L)[0][1] != D) {
            DP();LP();D();L();D();B();DP();BP();
        }
        else {D();}
    }
}
//forme la croix du bas
void croix_down(Cube *cube,listMouvement *liste) {
    while ( (cube->D)[0][1] != D || (cube->D)[2][1] != D || (cube->D)[1][0] != D || (cube->D)[1][2] != D) {
        if (((cube->D)[0][1] == D && (cube->D)[2][1] == D) || ((cube->D)[1][2] == D && (cube->D)[2][1] == D) ||
        ((cube->D)[1][0] == D && (cube->D)[2][1] == D) || ((cube->D)[0][1] == D && (cube->D)[1][2] == D)) {D();}
        else {F();L();D();LP();DP();FP();}
    }
}
//fait correspondre la croix du bas avec avec les pieces centrales
void edge_down(Cube *cube,listMouvement *liste) {
    while ( (cube->F)[2][1] != F || (cube->B)[0][1] != B || (cube->L)[1][0] != L || (cube->R)[1][2] != R) {
        if ( ((cube->L)[1][0] == F && (cube->F)[2][1] == L) || ((cube -> B)[0][1] == F && (cube->F)[2][1] == B)) {
            B();D();BP();D();B();D2();BP();D();
        }
        elif ( (cube->R)[1][2] == F && (cube->F)[2][1] == R) {L();D();LP();D();L();D2();LP();D();}
        elif ( ((cube->B)[0][1] == L && (cube->L)[1][0] == B) || ((cube->L)[1][0] == R && (cube->R)[1][2] == L)) {
            R();D();RP();D();R();D2();RP();D();
        }
        elif ( (cube->R)[1][2] == B && (cube->B)[0][1] == R) {F();D();FP();D();F();D2();FP();D();}
        else {D();}
    }
}
//place les coins du bas au bon endroit
void corner_down(Cube *cube,listMouvement *liste) {
    if (CFL() && CFR() && CBL() && CBR()) {
        //pass
    }
    else {
        if ( (!CFL()) && (!CFR()) && (!CBL()) && (!CBR())) {
            D();L();DP();RP();D();LP();DP();R();
        }
        if ( CFL() ) {
            while ( (!CFR()) || (!CBL()) || (!CBR()))
            {
                D();L();DP();RP();D();LP();DP();R();

            }
        }
        elif ( CFR()) {
            while ( (!CFL()) || (!CBL()) || (!CBR()))
            {
                D();F();DP();BP();D();FP();DP();B();
            }
        }
        elif ( CBL()) {
            while ( (!CFL()) || (!CBR()) || (!CFR()))
            {
                D();B();DP();FP();D();BP();DP();F();
            }
        }
        elif ( CBR()) {
            while ( (!CFL()) || (!CBL()) || (!CFR()))
            {
                D();R();DP();LP();D();RP();DP();L();
            }
        }
    }
}
//oriente les coins du bas
void orient_down(Cube *cube,listMouvement *liste) {
    int i=0;
    while ( (cube->D)[0][0] != D || (cube->D)[0][2] != D || (cube->D)[2][0] != D || (cube->D)[2][2] != D) {
        while ( (cube->D)[0][0] != D ) {
            LP();UP();L();U();
        }
        D();
        i++;
    }
    while (i-- != 0)
    {
        DP();
    }
}

//solve cube
listMouvement *solve_cube(Cube *cube) {
    listMouvement *liste = malloc(sizeof(listMouvement));
    liste->head = NULL;
    liste->tail = NULL;
    croix_up(cube,liste);
    coin_up(cube,liste);
    F2L(cube,liste);
    croix_down(cube,liste);
    edge_down(cube,liste);
    corner_down(cube,liste);
    orient_down(cube,liste);
    return liste;
}