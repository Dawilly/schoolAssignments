#include <stdio.h>
#include "sll.h"

//David Weil - CS201-001 - Spring 17
//queue.h - Queue Library
//Last revision: 1/25/2017

#ifndef __QUEUE_INCLUDED__
#define __QUEUE_INCLUDED__

typedef struct queue {
sll *items;
} queue;

queue *newQueue(void (*d)(FILE *,void *));   //constructor
void enqueue(queue *items,void *value);      //stores a generic value
void *dequeue(queue *items);                 //returns a generic value
void *peekQueue(queue *items);               //returns a generic value
int sizeQueue(queue *items);				 //returns size of queue
void displayQueue(FILE *fp,queue *items);	 //prints queue

#endif