#include <stdio.h>

//David Weil - CS201-001 - Spring 17
//dll.h - Double Link List Library
//Last revision: 1/25/2017

#ifndef __DLL_INCLUDED__
#define __DLL_INCLUDED__

typedef struct dllnode {
void *value;
struct dllnode *next;
struct dllnode *previous;
} dllnode;

typedef struct dll {
dllnode *head;
dllnode *tail;
int size;
void (*display)(FILE *,void *);
} dll;

dll *newDLL(void (*d)(FILE *,void *));            //constructor
void insertDLL(dll *items,int index,void *value); //stores a generic value
void *removeDLL(dll *items,int index);            //returns a generic value
void unionDLL(dll *recipient,dll *donor);         //merge two lists into one
int sizeDLL(dll *items);						  //size of dll
void displayDLL(FILE *,dll *items);				  //display all
void displayDLLreverse(FILE * fp, dll *items);	  //display all reverse
extern void *getDLL(dll *items,int index);		  //peeks value

#endif