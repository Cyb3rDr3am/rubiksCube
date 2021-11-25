#include "solveur.h"
#include "guiRubiksCube.h"
Cube *initCube() {
    Cube *cube = malloc(sizeof(Cube));
    if (!cube) {
        fprintf(stderr,"erreur memoire initialisation cube");
        exit(1);
    }
    cube->U = malloc(sizeof(couleur *) * 3);
    cube->D = malloc(sizeof(couleur *) * 3);
    cube->B = malloc(sizeof(couleur *) * 3);
    cube->F = malloc(sizeof(couleur *) * 3);
    cube->L = malloc(sizeof(couleur *) * 3);
    cube->R = malloc(sizeof(couleur *) * 3);
    if (!(cube->R && cube->U && cube->D && cube->B && cube->F && cube->L)) {
        fprintf(stderr,"erreur memoire initialisation cube");
        exit(1);
    }
    int i,j;
    for (i=0;i<3;i++) {
        cube->U[i] = malloc(sizeof(couleur) * 3);
        cube->D[i] = malloc(sizeof(couleur) * 3);
        cube->B[i] = malloc(sizeof(couleur) * 3);
        cube->F[i] = malloc(sizeof(couleur) * 3);
        cube->L[i] = malloc(sizeof(couleur) * 3);
        cube->R[i] = malloc(sizeof(couleur) * 3);
        if (!( (cube->R)[i] && (cube->U)[i] && (cube->D)[i] && (cube->B)[i] && (cube->F)[i] && (cube->L)[i])) {
        fprintf(stderr,"erreur memoire initialisation cube");
        exit(1);
        }
        for(j=0;j<3;j++) {
            cube->U[i][j] = U;
            cube->D[i][j] = D;
            cube->B[i][j] = B;
            cube->F[i][j] = F;
            cube->L[i][j] = L;
            cube->R[i][j] = R;
        } 
    }
    return cube;
}
void writeCube(Cube *cube,FILE *f) {
    int i,j,k;
    for (i=0;i<3;i++) {
        fprintf(f,"   ");
        for(j=0;j<3;j++) {
            fprintf(f,"%c",(cube->B)[i][j]);
        }
        fprintf(f,"   ");
        fprintf(f,"\n");
    }
    for (i=0;i<3;i++) {
        for (k=0;k<3;k++) {
            for(j=0;j<3;j++) {
                if (k==0) fprintf(f,"%c",(cube->L)[i][j]);
                else if (k==1) fprintf(f,"%c",(cube->U)[i][j]);
                else fprintf(f,"%c",(cube->R)[i][j]);
            }
        }
        fprintf(f,"\n");
    }
    for (i=0;i<3;i++) {
        fprintf(f,"   ");
        for(j=0;j<3;j++) {
            fprintf(f,"%c",(cube->F)[i][j]);
        }
        fprintf(f,"   ");
        fprintf(f,"\n");
    }
    for (i=0;i<3;i++) {
        fprintf(f,"   ");
        for(j=0;j<3;j++) {
            fprintf(f,"%c",(cube->D)[i][j]);
        }
        fprintf(f,"   ");
        fprintf(f,"\n");
    }
}
void randomizeCube(Cube *cube) {
    srand(time(NULL));
    int action;
    const int nbPerm = 100;
    void (*tab[NBACTION])(Cube *) = {f,u,l,r,d,b,fp,up,lp,rp,dp,bp};
    for (int i=0;i<nbPerm;i++) {
        action = (rand())%NBACTION;
        (tab[action])(cube);
    }
}
void afficheMenu() {
    printf("0) afficher le cube\
\n1)sauvegarder le rubiks cube\
\n2)resoudre le cube\
\n3)melanger le cube\
\n4)quitter\n");
}
int main(void) {
    FILE *f = fopen("rubiksCube.txt","w");
    Cube *cube = initCube();
    //randomizeCube(cube);
    initGui(cube);
    int continuer = 1;
    int action;
    while (continuer)
    {
        afficheMenu();
        if (!scanf("%d",&action)) {
            while(getchar() != '\n');
            printf("veuillez rentrez une action valide \n");
            afficheMenu();
        }
        else {
        switch (action)
        {
        case 0:
            writeCube(cube,stdout);
            break;
        case 1:
            rewind(f);
            writeCube(cube,f);
            printf("cube enregistrée \n");
            break;
        case 2:
            printf("Mouvement réalisée : \n");
            solve_cube(cube);
            break;
        case 3:
            randomizeCube(cube);
            printf("Cube mélangée \n");
            break;
        case 4:
            continuer = 0;
            break;
        default:
            printf("error invalid action \n");
            break;
        }
        }
    }
    fclose(f);
    return 0;
}