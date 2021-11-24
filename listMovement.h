#ifndef __LISTMOVEMENT__H__
#define __LISTMOVEMENT__H__
#include <stdio.h>
#include <stdlib.h>
typedef struct maillon {
    const char *mov;
    struct maillon *next;
    struct maillon *prev;
} maillon;
typedef struct  {
    maillon *head;
    maillon *tail;
} listMouvement;
extern void append_mov(listMouvement *,const char *);
extern void affiche_mov(listMouvement *);
extern void freeList(listMouvement *);
#endif  //!__LISTMOVEMENT__H__