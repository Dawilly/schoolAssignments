#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "dll.h"

//David Weil - CS201-001 - Spring 17
//stack.c - Stack Library
//Last revision: 1/25/2017

//newStack(void*) - Creates a new Stack data structure, with a generic display function (Accessed via void pointer).
//Parameters: (void*)d - Pointer to generic display function
//Returns: Pointer address to Stack data structure
stack *newStack(void (*d)(FILE *,void *)) {
	stack *theStack = malloc(sizeof(stack));
	if (theStack == 0) {
		fprintf(stderr,"out of memory");
		exit(-1);
    }
	theStack->items = newDLL(d);
	return theStack;
}

//push(stack*, void*) - Pushes a value onto a stack data structure.
//Parameters: (stack*)theStack - The stack we are pushing values onto.
//			: (void*)value - The value we are pushing onto the stack.
//Returns: None (Void)
void push(stack *theStack, void* value) {
	insertDLL(theStack->items, sizeDLL(theStack->items), value);
	return;
}

//pop(stack*, void*) - Pops the value that is on top of the stack data structure.
//Parameters: (stack*)theStack - The stack we are popping the value from.
//Returns: Nothing (Void). Value is printed out.
void *pop(stack *theStack) {
	void* poppedvalue = NULL;
	if (sizeStack(theStack) == 0) {
		fprintf(stderr,"stack is empty");
		exit(-1);
	}
	poppedvalue = removeDLL(theStack->items, sizeDLL(theStack->items)-1);
	return poppedvalue;
}

//peekStack (stack*) - Peeks at the value that is on top of the stack data structure.
//Parameters: (stack*)theStack - The stack which we are peeking at.
//Returns: void* of the peeked value.
void *peekStack(stack *theStack) {
	void* peakedvalue = NULL;
	peakedvalue = getDLL(theStack->items, sizeDLL(theStack->items)-1);
	return peakedvalue;
}

//sizeStack(stack*) - Gets the number of items within the stack.
//Parameters: (stack*)theStack - The stack which we are getting the size of.
//Returns: int - the size of the stack
int sizeStack(stack *theStack) {
	int size = sizeDLL(theStack->items);
	return size;
}

//displayStack(FILE*, stack*) - prints out the values within the stack data structure.
//Parameters: (FILE*)fp - The file pointer which we are streaming to.
//			: (stack*)theStack - The stack which we are printing from.
//Returns: Nothing (void), values are printed out.
void displayStack(FILE * fp,stack *theStack) {
	displayDLLreverse(fp, theStack->items);
	return;
}