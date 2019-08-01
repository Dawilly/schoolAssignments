#include <stdio.h>
#include <stdlib.h>
#include "darray.h"

//typedef struct DArray DArray; //forward declaration of the DArray struct

typedef struct DArray {
	void **array; //an array of void pointers
	int capacity; //total number of slots
	int size; //number of filled slots
	void (*display)(FILE *,void *);
} DArray;

DArray *newDArray(void (*display)(FILE *,void *)) {
	DArray *newDA = malloc(sizeof(DArray));
	if (newDA == 0) {
		fprintf(stderr,"newDArray: out of memory\n");
		exit(-1);
    }
	
	newDA->array = malloc(sizeof(void*));
	newDA->capacity = 1;
	newDA->size = 0;
	newDA->display = display;
	
	return newDA;
}

void insertDArray(DArray *a,void *v) {
	
	if (a->size == a->capacity) {
		a->capacity = a->capacity * 2;
		a->array = (void*) realloc(a->array, a->capacity * sizeof(void *));
	}
	//You got bad credit Robert
	
	a->array[a->size] = v;
	a->size++;
	
	return;
}

void *removeDArray(DArray *a) {
	
	void *removed;
	double ratio;
	
	if (a->size == 0) {
		fprintf(stderr, "removeDArray: array is empty\n");
		exit(-1);
	}
	
	removed = a->array[a->size-1];
	a->array[a->size-1] = 0;
	a->size--;
	
	ratio = (double) a->size / (double) a->capacity;
	//printf("size: %d, capacity: %d, ratio: %f\n", a->size, a->capacity, ratio);
	if (a->capacity != 1 && ratio < 0.25) {
		a->capacity = a->capacity / 2;
		a->array = (void*) realloc(a->array, a->capacity*sizeof(void*));
	}
	
	return removed;
	
}

void *getDArray(DArray *a,int index) {
	if (index >= a->size) {
		//fprintf(stderr, "getDArray: index is greater then or equal to size.\n");
		//exit(-1);
		//printf("In get, returning NULL\n");
		return NULL;
	}
	//printf("In get, returning value\n");
	return a->array[index];
}

void setDArray(DArray *a,int index,void *value) {
	
	if (index > a->size) {
		fprintf(stderr, "setDArray: index is greater then size.\n");
		exit(-1);
	} else if (index == a->size) {
		insertDArray(a, value);
	} else {
		a->array[index] = value;
	}
	
	return;
}

int sizeDArray(DArray *a) {
	return a->size;
}

void displayDArray(FILE *fp,DArray *a) {
	
	int x;
	
	fprintf(fp, "[");
	for (x = 0; x < a->size; x++) {
		a->display(fp, a->array[x]);
		if (x+1 != a->size) {
			fprintf(fp, ",");
		}
	}
	fprintf(fp, "]");
	fprintf(fp, "[%d]", (a->capacity - a->size));
	//fprintf(fp, "\n");
	return;
}

