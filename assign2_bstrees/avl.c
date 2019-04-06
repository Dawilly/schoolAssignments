#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "avl.h"

static void displayAVLValue(FILE*, void*);
static int compareAVLValue(void*, void*);
static void insertionFixup(bst*, bstNode*);
static void setBalance(bstNode*);
static int findBSTheight(bstNode*);
static int findFavortism(bstNode*);
static bstNode* getFavortism(bstNode*);
static bstNode* getParent(bstNode*);
static int linearCheck(bstNode*, bstNode*, bstNode*);
static void leftRotation(bst*, bstNode*);
static void rightRotation(bst*, bstNode*);

typedef struct avl {
	bst *tree;
	void (*display)(FILE *, void *);
	int (*compare)(void *, void *);
	int size;
	int words;
} AVL;

typedef struct avlNode {
	void* value;
	int height;
	int leftHeight;
	int rightHeight;
	int frequency;
	void (*display)(FILE *, void *);
	int (*compare)(void *, void *);
} avlNode;

AVL *newAVL(void (*d)(FILE *, void *), int (*c)(void *,void *)) {
	AVL* avlTree = malloc(sizeof(AVL));
	if (avlTree == 0) {
		fprintf(stderr,"newAVL: out of memory");
		exit(-1);
	}
	avlTree->tree = newBST(displayAVLValue,compareAVLValue);
	avlTree->display = d;
	avlTree->compare = c;
	avlTree->size = 0;
	avlTree->words = 0;
	return avlTree;
}

void insertAVL(AVL *t, void *v) {
	bstNode* foundBase = NULL;
	avlNode* found = NULL;
	avlNode* newAvlNode = malloc(sizeof(avlNode));
	
	if (newAvlNode == 0) {
		fprintf(stderr, "insertAVL: out of memory");
		exit(-1);
	}
	
	newAvlNode->value = v;
	newAvlNode->display = t->display;
	newAvlNode->compare = t->compare;
	
	if (findAVLcount(t, v) != 0) {
		foundBase = findBSTNode(t->tree, newAvlNode);
		found = foundBase->value;
		found->frequency++;
	} else {
		newAvlNode->frequency = 1;
		newAvlNode->height = 1;
		newAvlNode->leftHeight = 0;
		newAvlNode->rightHeight = 0;
		foundBase = insertBST(t->tree, newAvlNode);
		t->size++;
		insertionFixup(t->tree, foundBase);
	}
	t->words++;
	return;
}
int findAVLcount(AVL *AVLtree, void *v) {
	avlNode* foundAVL = malloc(sizeof(avlNode));
	bstNode* x;
	avlNode* f;
	int results;
	
	if (foundAVL == 0) {
		fprintf(stderr, "findAVL: out of memory");
		exit(-1);
	}
	
	foundAVL->value = v;
	foundAVL->display = AVLtree->display;
	foundAVL->compare = AVLtree->compare;
	
	x = findBSTNode(AVLtree->tree, foundAVL);
	if (x == NULL) {
		results = 0;
	} else {
		f = x->value;
		results = f->frequency;
	}
	
	free(foundAVL);
	
	return results;
}

void *findAVL(AVL *tree,void *v) {
	return NULL;
}

void *deleteAVL(AVL *tree,void *v) {
	return NULL;
}

//int sizeAVL(AVL *);
//int duplicatesAVL(AVL *);
//void statisticsAVL(AVL *,FILE *);
void displayAVL(FILE *fp, AVL *AVLtree) {
	displayBST(fp, AVLtree->tree);
	return;
}

void displayAVLdebug(FILE *fp, AVL *AVLtree) {
	displayBSTDebug(fp, AVLtree->tree);
	return;
}
//void freeAVL(AVL *);

//Private functions

static void displayAVLValue(FILE *fp, void *v) {
	
	if (v == NULL)
		return;
	
	avlNode* point = v;
	point->display(fp, point->value);
	
	return;
}

static int compareAVLValue(void *v, void *w) {
	avlNode *a = v;
	avlNode *b = w;
	return a->compare(a->value, b->value);
}

static void insertionFixup(bst* tree, bstNode *x) {
	int loop = 1;
	//avlNode* n = x->value;
	bstNode *y = NULL;
	bstNode *p = NULL;
	while (loop) {
        if (x == tree->root) {
            loop = 0;
		} else if (findFavortism(x) == -1 || findFavortism(x) == 1) {        //case 1
            setBalance(x);
            loop = 0;
        } else if (findFavortism(x) == 0) {              //case 2
            setBalance(x);
            x = x->parent;
            //continue looping
        } else {
            //y = the favorite child of x
			y = getFavortism(x);
            p = getParent(x);
            if (y != NULL && !linearCheck(x, y, p)) { //case 3
				if (x->right == y && p->left == x) {
					//Left-Right Rotation
					leftRotation(tree, y);
					rightRotation(tree, y);
				} else {
					//Right-Left Rotation
					rightRotation(tree, y);
					leftRotation(tree, y);
				}
                setBalance(x);
				setBalance(p);
				setBalance(y);
            } else {                                  //case 4
                if (p->left == x) {
					rightRotation(tree, x);
				} else {
					leftRotation(tree, x);
				}

				setBalance(p);
				setBalance(x);
            }
            loop = 0;
        }
    }
	return;
}

static void setBalance(bstNode *n) {
	avlNode* x = n->value;
	//set x's leftHeight to the height of the left child, zero if there is no left child
	if (n->left != NULL) {
		x->leftHeight = findBSTheight(n->left);
    } else {
		x->leftHeight = 0;
	}
	
    //set x's rightHeight to the height of the right child, zero if there is no right child
	if (n->right != NULL) {
		x->rightHeight = findBSTheight(n->right);
	} else {
		x->rightHeight = 0;
	}
	
    //set x's height to the max of leftHeight and rightHeight, plus one
	if (x->leftHeight > x->rightHeight) {
		x->height = x->leftHeight + 1;
	} else {
		x->height = x->rightHeight + 1;
	}
	
	return;
}

static int findBSTheight(bstNode *n) {
	
	int left = 0;
	int right = 0;
	int results = 0;
	
	if (n == NULL) {
		return 0;
	} else {
		left = findBSTheight(n->left);
		right = findBSTheight(n->right);
		
		if (right > left) {
			results = right + 1;
		} else {
			results = left + 1;
		}
	}
	
	return results;
}

static int findFavortism(bstNode *n) {
	avlNode* x = n->value;
	return x->leftHeight - x->rightHeight;
}

static bstNode* getFavortism(bstNode* n) {
	int results = findFavortism(n);
	bstNode* favorite;
	if (results > 0) {
		favorite = n->left;
	} else {
		favorite = n->right;
	}
	return favorite;
}

static bstNode* getParent(bstNode* n) {
	return n->parent;
}

static int linearCheck(bstNode *n, bstNode *child, bstNode *parent) {
	if (parent->left == n && n->left == child) {
		return 1;
	} else if (parent->right == n && n->right == child) {
		return 1;
	}
	return 0;
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