#include <stdio.h>

//David Weil - CS201-001 - Spring 17
//sll.c - Single Link List Library
//Last revision: 1/25/2017

#ifndef __SLL_INCLUDED__
#define __SLL_INCLUDED__

typedef struct sllnode {
void *value;
struct sllnode *next;
} sllnode;

typedef struct sll {
sllnode *head;
sllnode *tail;
int size;
void (*display)(FILE *,void *);
} sll;

extern sll *newSLL(void (*d)(FILE *,void *));            //constructor
extern void insertSLL(sll *items,int index,void *value); //stores a generic value
extern void *removeSLL(sll *items,int index);            //returns a generic value
extern void unionSLL(sll *recipient,sll *donor);         //merge two lists into one
extern int sizeSLL(sll *items);
extern void displaySLL(FILE *,sll *items);
extern void *getSLL(sll *items,int index);				 //Do we need this?

#endif