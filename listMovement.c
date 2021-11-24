#include "listMovement.h"
//ajoute a une liste chaine un mouvement
void append_mov(listMouvement *liste,const char *mov) {
    maillon *m = malloc(sizeof(maillon));
    m->next = liste->head;
    m->mov = mov;
    if (liste->head == NULL) {
        liste->head = m;
        liste->tail = m;
        m -> prev = NULL;
    }
    else {
        liste->head->prev = m;
        liste->head = m;
    }
}
//affiche les mouvements de la liste chaine
void affiche_mov(listMouvement *liste) {
    maillon *m = liste->tail;
    while (m!=NULL) {
        printf("%s",m->mov);
        m = m->prev;
    }
    printf("\n");
}
void freeList(listMouvement *liste) {
    maillon *m = liste->head;
    maillon *m2;
    while (m != NULL) {
        m2 = m->prev;
        free(m);
        m=m2;
    }
    free(liste);
}