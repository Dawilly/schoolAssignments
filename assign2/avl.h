/*** AVL binary search tree class ***/

#ifndef __AVL_INCLUDED__
#define __AVL_INCLUDED__

#include <stdio.h>

typedef struct avl AVL;

extern AVL *newAVL(
    void (*)(FILE *, void *),           //display
    int (*)(void *,void *));            //comparator
    //void (*)(void *));                 //freeing function
extern void insertAVL(AVL *,void *);
extern int findAVLcount(AVL *,void *);
extern void *findAVL(AVL *,void *);
extern void *deleteAVL(AVL *,void *);
//extern int sizeAVL(AVL *);
//extern int duplicatesAVL(AVL *);
//extern void statisticsAVL(AVL *,FILE *);
extern void displayAVL(FILE *, AVL *);
extern void displayAVLdebug(FILE *, AVL *);
//extern void freeAVL(AVL *);

#endif
