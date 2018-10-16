#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "sll.h"

//David Weil - CS201-001 - Spring 17
//queue.c - Queue Library
//Last revision: 1/25/2017

//newQueue(void*) - Creates a new Queue data structure, with a generic display function (Accessed via void pointer).
//Parameters: (void*)d - Pointer to generic display function
//Returns: Pointer address to Queue data structure
queue *newQueue(void (*d)(FILE *,void *)) {
	queue *theQueue = malloc(sizeof(queue));
	if (theQueue == 0) {
		fprintf(stderr,"out of memory");
		exit(-1);
    }
	theQueue->items = newSLL(d);
	return theQueue;
}

//enqueue(queue*, void*) - Inserts a new value to the back of the queue.
//Parameters: (queue*)theQueue - The queue which we are setting the value to.
//			: (void*)value - The generic value we are enqueuing.
//Returns: Nothing (Void)
void enqueue(queue *theQueue,void *value) {
	insertSLL(theQueue->items, sizeSLL(theQueue->items), value);
}

//dequeue(queue*) - Removes the value at the front of the queue.
//Parameters: (queue*)theQueue - The queue which we are removing the value at the front from.
//Returns: void* of the generic value.
void *dequeue(queue *theQueue) {
	void* devalue = NULL;
	if (sizeQueue(theQueue) == 0) {
		fprintf(stderr,"stack is empty");
		exit(-1);
	}
	devalue = removeSLL(theQueue->items, 0);
	return devalue;
}

//peekQueue(queue*) - Gets the value at the front of the queue, but does not remove it.
//Parameters: (queue*)theQueue - The queue which we are peeking at the front of.
//Returns: void* of the generic value. 
void *peekQueue(queue *theQueue) {
	void* peakedvalue = NULL;
	peakedvalue = getSLL(theQueue->items, 0);
	return peakedvalue;
}

//sizeQueue(queue*) - Gets the size of the queue, how many values are enqueued.
//Parameters: (queue*)theQueue - THe queue which we are getting the size of.
//Returns: int - the size of the queue.
int sizeQueue(queue *theQueue) {
	int size = sizeSLL(theQueue->items);
	return size;
}

//displayQueue(FILE*, queue*) - Prints all the values that are within the queue.
//Parameters: (FILE*)fp - The File Pointer we are streaming to.
//			: (queue*)theQueue - The queue which we are printing from.
//Returns: Nothing (Void). Values are printed out.
void displayQueue(FILE *fp,queue *theQueue) {
	displaySLL(fp, theQueue->items);
	return;
}