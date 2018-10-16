#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "rbt.h"

void displayRBTValue(FILE*, void*);
int compareRBTValue(void*, void*);
void insertionFixUp(bst*, bstNode*);
void leftRotation(bst*, bstNode*);
void rightRotation(bst*, bstNode*);
bstNode *uncle(bstNode*);
bstNode *grandparent(bstNode*);
int color(bstNode*);
void setcolor(bstNode*, int);

rbt *newRBT(void (*d)(FILE *,void *),int (*c)(void *,void *)) {
	rbt *redblack = malloc(sizeof(rbt));
	if (redblack == 0) {
		fprintf(stderr,"newRBT: out of memory");
		exit(-1);
	}
	
	redblack->tree = newBST(displayRBTValue, compareRBTValue);
	redblack->display = d;
	redblack->compare = c;
	redblack->size = 0;
	redblack->words = 0;
	
	return redblack;
}

void insertRBT(rbt *redblack,void *v) {
	
	//printf("Inserting...\n");
	
	bstNode* found_base = NULL;
	rbtValue* found = NULL;
	rbtValue* newRB = malloc(sizeof(rbtValue));
	
	if (newRB == 0) {
		fprintf(stderr,"insertRBT: out of memory");
		exit(-1);
	}
	
	newRB->value = v;
	newRB->display = redblack->display;
	newRB->compare = redblack->compare;
	//printf("Search if it exists already...\n");
	if (findRBT(redblack, v) != 0) {
		//printf("It exists!\n");
		found_base = findBSTNode(redblack->tree, newRB);
		found = found_base->value;
		found->frequency++;
		//free(newV);
	} else {
		//printf("It does not exist...\n");
		newRB->frequency = 1;
		newRB->color = 0;
		found_base = insertBST(redblack->tree, newRB);
		redblack->size++;
		//Call insertionfixup w/ found_base
		insertionFixUp(redblack->tree, found_base);
	}
	redblack->words++;
	
	//printf("Done!\n");
	
	return;	
}

int findRBT(rbt *redblack, void *v) {
	
	//int x;
	rbtValue* foundRB = malloc(sizeof(rbtValue));
	bstNode* x;
	rbtValue* f;
	
	if (foundRB == 0) {
		fprintf(stderr,"findRBT: out of memory");
		exit(-1);
	}
	
	foundRB->value = v;
	foundRB->display = redblack->display;
	foundRB->compare = redblack->compare;
	
	x = findBSTNode(redblack->tree, foundRB);
	if (x == NULL) {
		return 0;
	} else { 
		f = x->value;
		return f->frequency;	
	}
}

//This function should do nothing, since we are informed to not
//worry about deletion in a redblack tree
void deleteRBT(rbt *redblack,void *v) {
	bst *tree = redblack->tree;
	int i = 1;
	if (i == 0 && v == NULL) {
		redblack->tree = tree;
	}
	return;
}

int sizeRBT(rbt *redblack) {
	return redblack->size;
}

int wordsRBT(rbt *redblack) {
	return redblack->words;
}

void statisticsRBT(rbt *redblack, FILE *fp) {
	fprintf(fp, "Words/Phrases: %d\n", wordsRBT(redblack));
	statisticsBST(redblack->tree, fp);
	return;
}

void displayRBT(FILE *fp, rbt *redblack) {
	displayBST(fp, redblack->tree);
}

void checkRBT(rbt *redblack) {
	bst* temp = redblack->tree;
	int i = 1;
	if (i == 0) {
		redblack->tree = temp;
	}
	return;
}

/////////////////////////
/////////////////////////
////Private Functions////
/////////////////////////
/////////////////////////

void displayRBTValue(FILE *fp, void *v) {
	
	if (v == NULL) {
		return;
	}
	
	rbtValue *point = v;
	point->display(fp, point->value);
	if (point->frequency > 1) {
		fprintf(fp, "-%d", point->frequency);
	}
	if (point->color == 1) {
		fprintf(fp, "-B");
	} else {
		fprintf(fp, "-R");
	}
	
}

int compareRBTValue(void *v, void *w) {
	rbtValue *a = v;
	rbtValue *b = w;
	return a->compare(a->value, b->value);
}

// x is the newly inserted node
void insertionFixUp(bst *tree, bstNode *x) {

	//printf("Fixing up...\n");
	bstNode *oldparent = NULL;
	
	int l = 1;
	bstNode *temp = malloc(sizeof(bstNode));
	if (temp == 0) {
		fprintf(stderr, "insertRBTfixup: out of memory\n");
		exit(-1);
	}

	//loop {
	while(l == 1) {
		if (tree->root == x) {
			l = 0;
			continue;
		}
		//if (parent is black) {
		if (color(x->parent) == 1) {
			l = 0;
			continue;
		}
		//if (uncle is red) {
		if (color(uncle(x)) == 0) {
			//color parent black
			setcolor(x->parent, 1);
			//color uncle black
			setcolor(uncle(x), 1);
			//color grandparent red
			setcolor(grandparent(x), 0);
			//x = grandparent
			x = grandparent(x);
		} else {
		// uncle must be black

			//if (x and parent are not linear) {
			//if (x->parent->right == x && !(x->parent != tree->root)) {
			if (x->parent->right == x) {
				if (x->parent->parent->left == x->parent) {
					oldparent = x->parent;
					leftRotation(tree, x);
					x = oldparent;
				}
			//} else if (x->parent->left == x && !(x->parent != tree->root)) {
			} else if (x->parent->left == x) {
				if (x->parent->parent->right == x->parent) {
					oldparent = x->parent;
					rightRotation(tree, x);
					x = oldparent;
				}
			}

			//color parent black
			setcolor(x->parent, 1);
			//color grandparent red
			setcolor(grandparent(x), 0);
			//rotate parent to grandparent
			if (x->parent == x->parent->parent->left) {
				rightRotation(tree, x->parent);
			} else {
				leftRotation(tree, x->parent);
			}
			//exit the loop
			l = 0;
		}
	}
	//color root black
	setcolor(tree->root, 1);
	return;
}

void leftRotation(bst *tree, bstNode *b) {

	//B goes to A, A goes to the left child of B.
	bstNode *a = NULL;
	bstNode *oldleft = NULL;
	
	a = b->parent;
	
	b->parent = a->parent;
	
	if (a != tree->root) {
		if (a->parent->left == a) {			
			a->parent->left = b;
		} else {
			a->parent->right = b;
		}
	}
	
	oldleft = b->left;
	b->left = a;
	a->parent = b;
	a->right = oldleft;
	if (oldleft != NULL) {
		oldleft->parent = a;
	}
	
	if (a == tree->root) {
		tree->root = b;
		b->parent = b;
	}
	
	return;
}

void rightRotation(bst *tree, bstNode *b) {
	
	//B goes to A, A goes to the right child of B.
	bstNode *a = NULL;
	bstNode *oldright = NULL;
	
	a = b->parent;
	
	b->parent = a->parent;
	if (a != tree->root) {
		if (a->parent->left == a) {
			a->parent->left = b;
		} else {
			a->parent->right = b;
		}
	}
	
	oldright = b->right;
	b->right = a;
	a->parent = b;
	a->left = oldright;
	if (oldright != NULL) {
		oldright->parent = a;
	}
	
	if (a == tree->root) {
		tree->root = b;
		b->parent = b;
	}
	
	return;
}
		
bstNode *uncle(bstNode *x) {	
	if (x->parent == x->parent->parent->left) {
		return x->parent->parent->right;
	} else {
		return x->parent->parent->left;
	}
}

bstNode *grandparent(bstNode *x) {
	return x->parent->parent;
}
		
int color(bstNode *x) {
	rbtValue *rbNode = NULL;
	if (x == NULL) {
		//NIL (Leaf) is always black
		return 1;
	} else {
		rbNode = x->value;
		return rbNode->color;
	}
}

void setcolor(bstNode *x, int color) {
	rbtValue *rbNode = NULL;
	if (x != NULL) {
		rbNode = x->value;
		rbNode->color = color;
	}
	return;
}

/////////////////////////
