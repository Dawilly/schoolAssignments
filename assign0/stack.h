#include <stdio.h>
#include "dll.h"

//David Weil - CS201-001 - Spring 17
//stack.h - Stack Library
//Last revision: 1/25/2017

#ifndef __STACK_INCLUDED__
#define __STACK_INCLUDED__

typedef struct stack {
DLL *items;
} stack;

stack *newStack(void (*d)(FILE *,void *));   //constructor
void push(stack *items, void* value);        //stores a generic value
void *pop(stack *items);                     //returns a generic value
void *peekStack(stack *items);               //returns a generic value
int sizeStack(stack *items);				 //size of stack
void displayStack(FILE * fp,stack *items);	 //display function

#endif