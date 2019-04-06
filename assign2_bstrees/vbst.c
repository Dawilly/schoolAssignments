#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "vbst.h"

static void displayVBSTValue(FILE*, void*);
static int compareVBSTValue(void*, void*);


vbst *newVBST(void (*d)(FILE *,void *),int (*c)(void *,void *)) {
	vbst *vanilla = malloc(sizeof(vbst));
	if (vanilla == 0) {
		fprintf(stderr,"newVBST: out of memory");
		exit(-1);
    }
	vanilla->tree = newBST(displayVBSTValue, compareVBSTValue);
	vanilla->display = d;
	vanilla->compare = c;
	vanilla->size = 0;
	vanilla->words = 0;
	return vanilla;
}

void insertVBST(vbst *vanilla, void *v) {
	
	bstNode* found_base = NULL;
	vbstValue* found = NULL;
	vbstValue* newV = malloc(sizeof(vbstValue));
	if (newV == 0) {
		fprintf(stderr,"insertVBST: out of memory");
		exit(-1);
    }
	newV->value = v;
	newV->display = vanilla->display;
	newV->compare = vanilla->compare;
	if (findVBST(vanilla, v) != 0) {
		found_base = findBSTNode(vanilla->tree, newV);
		found = found_base->value;
		found->frequency++;
		//free(newV);
	} else {
		newV->frequency = 1;
		insertBST(vanilla->tree, newV);
		vanilla->size++;
	}
	vanilla->words++;
	
	return;
}

int findVBST(vbst *vanilla, void *v) {
	
	//int x;
	vbstValue* foundV = malloc(sizeof(vbstValue));
	vbstValue* f;
	bstNode* x;
	
	if (foundV == 0) {
		fprintf(stderr,"findVBST: out of memory");
		exit(-1);
    }
	
	foundV->value = v;
	foundV->display = vanilla->display;
	foundV->compare = vanilla->compare;
	
	x = findBSTNode(vanilla->tree, foundV);
	
	if (x == NULL) {
		return 0;
	} else {
		f = x->value;
		return f->frequency;
	}
}

void deleteVBST(vbst *vanilla, void *v) {
	
	bstNode* found = NULL;
	//bstNode* theBase = malloc(sizeof(bstNode));
	vbstValue* freq = NULL;
	vbstValue* theV = malloc(sizeof(vbstValue));
	
	if (theV == 0) {
		fprintf(stderr,"deleteVBST: out of memory");
		exit(-1);
    }
	
	theV->value = v;
	theV->compare = vanilla->compare;
	theV->display = vanilla->display;
	found = findBSTNode(vanilla->tree, theV);
	if (found != 0) {
		freq = found->value;
		if (freq->frequency > 1) {
			freq->frequency--;
		} else if (freq->frequency == 1) {
			found = swapToLeafBSTNode(found);
			pruneBSTNode(vanilla->tree, found);
		}
		vanilla->words--;
		vanilla->size--;
	} else {
		fprintf(stderr, "Value ");
		theV->display(stderr, theV->value);
		fprintf(stderr, " not found.\n");
	}
	
	return;
}

int sizeVBST(vbst *vanilla) {
	return vanilla->size;
}

int wordsVBST(vbst *vanilla) {
	return vanilla->words;
}

void statisticsVBST(vbst *vanilla, FILE *fp) {
	fprintf(fp, "Words/Phrases: %d\n", wordsVBST(vanilla));
	statisticsBST(vanilla->tree, fp);
	return;
}

void displayVBST(FILE *fp, vbst *vanilla) {
	displayBST(fp, vanilla->tree);
}

void checkVBST(vbst *vanilla) {
	vbst *temp;
	temp = vanilla;
	int i = 1;
	if (i == 0) {
		vanilla->tree = temp->tree;
	}
	return;
}	//optional


/////////////////////////
/////////////////////////
////Private Functions////
/////////////////////////
/////////////////////////

static void displayVBSTValue(FILE *fp, void *v) {
	
	if (v == NULL) {
		return;
	}
	
	vbstValue *point = v;
	point->display(fp, point->value);
	if (point->frequency > 1) {
		fprintf(fp, "-%d", point->frequency);
	}
	
}

static int compareVBSTValue(void *v, void *w) {
	vbstValue *a = v;
	vbstValue *b = w;
	return a->compare(a->value, b->value);
}

/////////////////////////