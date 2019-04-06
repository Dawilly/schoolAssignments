#include <stdio.h>

//David Weil - CS201-001 - Spring 17
//DLL.h - Double Link List Library
//Last revision: 1/25/2017

#ifndef __DLL_INCLUDED__
#define __DLL_INCLUDED__

typedef struct DLLnode {
void *value;
struct DLLnode *next;
struct DLLnode *previous;
} DLLnode;

typedef struct DLL {
DLLnode *head;
DLLnode *tail;
int size;
void (*display)(FILE *,void *);
} DLL;

DLL *newDLL(void (*d)(FILE *,void *));            //constructor
void insertDLL(DLL *items,int index,void *value); //stores a generic value
void *removeDLL(DLL *items,int index);            //returns a generic value
void unionDLL(DLL *recipient,DLL *donor);         //merge two lists into one
int sizeDLL(DLL *items);						  //size of DLL
void displayDLL(FILE *,DLL *items);				  //display all
void displayDLLreverse(FILE * fp, DLL *items);	  //display all reverse
extern void *getDLL(DLL *items,int index);		  //peeks value
extern void *setDLL(DLL *items, int index, void *value);
extern void displayDLLdebug(DLL *items, FILE *);
extern void freeDLL(DLL *items);

#endif