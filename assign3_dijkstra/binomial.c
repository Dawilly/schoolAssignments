#include <stdio.h>
#include <stdlib.h>
#include "binomial.h"
#include "queue.h"

//Private Function Declaration
static BinomialNode *bubbleUp(Binomial*, BinomialNode*);
static void consolidate(Binomial*, BinomialNode*);
static BinomialNode* combine(Binomial*, BinomialNode*, BinomialNode*);
static void merge(Binomial*, DArray*);
static void* getSubHeap(DArray*, int);

typedef struct BinomialNode {
	void *value;
	DArray *children;
	struct BinomialNode *parent;
	void (*display)(FILE *,void *);
} BinomialNode;

typedef struct Binomial {
	DArray *rootlist;
	int (*compare)(void*,void*);
	void (*update)(void*,BinomialNode*);
	BinomialNode *extreme;
	int size;
	void (*display)(FILE*,void*);
} Binomial;

//////////////////////////
//BinomialNode functions//
//////////////////////////
BinomialNode *newBinomialNode(void (*display)(FILE *,void *),void *value) {
	
	BinomialNode *newNode = malloc(sizeof(BinomialNode));
	if (newNode == 0) {
		fprintf(stderr, "newBinomialNode: out of memory\n");
		exit(-1);
	}
	
	newNode->display = display;
	newNode->value = value;
	newNode->children = NULL; //?
	newNode->parent = NULL; //?
	
	return newNode;
}

void displayBinomialNode(FILE *fp,BinomialNode *n) {
	n->display(fp, n->value);
	fprintf(fp, "-%d", sizeDArray(n->children));
	
	if (n->parent != n) {
		fprintf(fp, "(");
		n->display(fp, n->parent->value);
		fprintf(fp, "-%d", sizeDArray(n->parent->children));
		fprintf(fp, ")");
	}
	
	return;
}

//////////////////////
//Binomial functions//
//////////////////////
Binomial *newBinomial(void (*d)(FILE *,void *), int (*c)(void *,void *), void (*u)(void *,BinomialNode *)) {
	
	Binomial *newB = malloc(sizeof(Binomial));
	if (newB == 0) {
		fprintf(stderr,"newBinomial: out of memory\n");
		exit(-1);
    }
	
	newB->rootlist = newDArray(d);
	newB->display = d;
	newB->compare = c;
	newB->update = u;
	newB->extreme = NULL;
	newB->size = 0;
	return newB;
}

BinomialNode *insertBinomial(Binomial *b,void *value) {
	BinomialNode *newNode = newBinomialNode(b->display, value);
	
	//New Extreme?
	if (b->extreme == NULL) {
		b->extreme = newNode;
	} else if (b->compare(newNode->value, b->extreme->value) < 0) {
		b->extreme = newNode;
	}
	
	newNode->parent = newNode;
	newNode->children = newDArray(b->display);
	
	//Consolidate
	consolidate(b, newNode);
	b->size++;
	return newNode;
}

int sizeBinomial(Binomial *b) {
	return b->size;
}

void deleteBinomial(Binomial *b,BinomialNode *n) {
	BinomialNode* m;
	if (sizeBinomial(b) == 0) {
		fprintf(stderr, "deleteBinomial: Empty Heap\n");
		return;
	}
	decreaseKeyBinomial(b, n, NULL);
	m = extractBinomial(b);
	if (m == NULL) {
		fprintf(stderr, "Node does not exist.\n");
	}
}

void decreaseKeyBinomial(Binomial *b,BinomialNode *n,void *value) {
	BinomialNode* newextreme;
	
	n->value = value;
	newextreme = bubbleUp(b, n);
	if (b->compare(b->extreme->value, newextreme->value) > 0) {
		b->extreme = newextreme;
	}
	
	return;
}

void *extractBinomial(Binomial *b) {
	BinomialNode* y = b->extreme;
	BinomialNode* newEx = NULL;
	//BinomialNode* curr = NULL;
	int i;
	//int foundex = 0;
	int first = 0;
	void* storedvalue;
	
	setDArray(b->rootlist, sizeDArray(y->children), NULL);
	
	/*
	for (i = 0; i < sizeDArray(b->rootlist); i++) {
		if (y == getDArray(b->rootlist, i)) {
			//printf("found the node\n");
			foundex = 1;
			setDArray(b->rootlist, i, NULL);
		}
	}
	*/
	
	//if (foundex == 0) {
	//	fprintf(stderr, "Extreme value was not found.\n");
	//}
	
	//printf("size of children: %d\n", sizeDArray(y->children));
	//printf("Begin merge\n");
	merge(b, y->children);
	//printf("End merge\n");
	b->size--;
	storedvalue = y->value;
	//free(y);
	b->extreme = NULL;
	//Find the new extreme node
	//printf("Begin find new extreme\n");
	for (i = 0; i < sizeDArray(b->rootlist); i++) {
		y = getDArray(b->rootlist, i);
		if (y == NULL) {
			continue;
		}
		
		if (first == 0) {
			newEx = y;
			first = 1;
		} else {
			if (b->compare(y->value, newEx->value) < 0) {
				newEx = y;
			}
		}
	}
	b->extreme = newEx;
	//
	return storedvalue;
}

void displayBinomial(FILE *fp,Binomial *b) {
	queue* q = newQueue(b->display);
	BinomialNode* working = NULL;
	int level;
	int x = 0;
	int y = 0;
	
	//printf("size: %d\n", sizeDArray(b->rootlist));
	
	for (x = 0; x < sizeDArray(b->rootlist); x++) {
		
		if (!(working = getDArray(b->rootlist, x))) {
			continue;
		}
		
		level = 1;
		fprintf(fp, "0:");
		
		//working = getDArray(b->rootlist, x);
		
		if (working != NULL) {
			enqueue(q, working);
			enqueue(q, NULL);
		} else {
			fprintf(fp, "\n");
		}
		
		while (sizeQueue(q) > 0) {
			working = dequeue(q);
			if (working == NULL) {
				fprintf(fp, "\n");
				if (sizeQueue(q) != 0) {
					fprintf(fp, "%d:", level);
					level++;
					if (peekQueue(q) != NULL) {
						enqueue(q, NULL);
					} else {
						break;
					}
				}
			} else {
				fprintf(fp, " ");
				displayBinomialNode(fp, working);
				//Go deep
				if (sizeDArray(working->children) > 0) {
					for (y = 0; y < sizeDArray(working->children); y++) {
						enqueue(q, getDArray(working->children, y));
					}
				}
			}
		}
		fprintf(fp, "----\n");
	}
	return;
}

//////////////////////////////
//Private Binomial functions//
//////////////////////////////

static BinomialNode *bubbleUp(Binomial *b, BinomialNode *n) {
	
	void* temp;
	
	if (n->parent == n) {
		return n;
	} else if (b->compare(n->value, n->parent->value) > 0) { //changed from < to >
		return n;
	} else {
		if (b->update != NULL) {
			//Call Updater with N's Value and N's Parent
			b->update(n->value, n->parent);
			//Call Updater with N's parent's value and N
			b->update(n->parent->value, n);
		}
		temp = n->value;
		n->value = n->parent->value;
		n->parent->value = temp;
		return bubbleUp(b, n->parent);
	}
}

static void* getSubHeap(DArray *d, int index) {
	if (sizeDArray(d) == index) {
		return 0;
	} else {
		return getDArray(d, index);
	}
}

static void consolidate(Binomial *b, BinomialNode *n) {
	//printf("Consolidate...\n");
	int degree = sizeDArray(n->children);
	while(degree < sizeDArray(b->rootlist) && getSubHeap(b->rootlist, degree) != NULL) {
		n = combine(b, n, getDArray(b->rootlist, degree));
		setDArray(b->rootlist, degree, NULL);
		degree++;
	}
	
	setDArray(b->rootlist, degree, n);
	return;
}

static BinomialNode* combine(Binomial *b, BinomialNode *x, BinomialNode *y) {
	
	int i;
	//printf("Combining...\n");
	if (b->compare(x->value, y->value) < 0) {
		i = sizeDArray(y->children);
		setDArray(x->children, i, y);
		y->parent = x;
		return x;
	} else {
		i = sizeDArray(x->children);
		setDArray(y->children, i, x);
		x->parent = y;
		return y;
	}
}

static void merge(Binomial* b, DArray* donor) {
	int i;
	BinomialNode* working;
	

	if (sizeDArray(donor) == 0) {
		return;
	}

	for (i = 0; i < sizeDArray(donor); i++) {
		//printf("Loop %d\n", i);
		working = getDArray(donor, i);
		if (working == NULL) {
			//printf("Skipping\n");
			continue;
		}
		working->parent = working;
		consolidate(b, working);
	}
	
	//free(donor);
	return;
}