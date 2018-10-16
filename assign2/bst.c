#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "queue.h"
#include "sll.h"

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

static bstNode *findSuccessor(bstNode*);
static bstNode *findPredecessor(bstNode*);
static bstNode *swapValues(bstNode*, bstNode*);
static int findBSTheight(bstNode*);
static int findBSTminheight(bstNode *);
static void displayPreOrderSub(FILE *, bstNode *, bst *);
static void displayBSTInOrder(FILE *,bst *);


bst *newBST(void (*d)(FILE *,void *),int (*c)(void *,void *)) {
	bst *newTree = malloc(sizeof(bst));
	if (newTree == 0) {
		fprintf(stderr,"newBST: out of memory");
		exit(-1);
    }
	newTree->root = NULL;
	newTree->display = d;
	newTree->compare = c;
	newTree->size = 0;
	return newTree;
}

bstNode *insertBST(bst *tree,void *v) {
	
	bstNode *traverse = NULL;
	
	bstNode *newNode = malloc(sizeof(bstNode));
	if (newNode == 0) {
		fprintf(stderr,"insertBST: out of memory");
		exit(-1);
	}
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->value = v;
	
	//Find duplicate, if found, return NULL, indicating there was one already existing.
	if (findBST(tree, v) == 1) {
		return NULL;
	}
	
	if (tree->root == NULL) {
		newNode->parent = newNode;
		tree->root = newNode;
	} else {
		traverse = tree->root;
		while (traverse != NULL) {
			//Left node
			if (tree->compare(newNode->value, traverse->value) < 0) {
				//Left node is empty, insert into it
				if (traverse->left == NULL) {
					newNode->parent = traverse;
					traverse->left = newNode;
					traverse = NULL;
					continue;
				//Continue traversing through left node
				} else {
					traverse = traverse->left;
				}
			//Right node
			} else {
				//Right node is empty, insert into it
				if (traverse->right == NULL) {
					newNode->parent = traverse;
					traverse->right = newNode;
					traverse = NULL;
					continue;
				//Continue traversing through right node
				} else {
					traverse = traverse->right;
				}
			}
		}
	}
	tree->size++;
	return newNode;
}

//Currently searches for the node as if it was inserting.
int findBST(bst *tree,void *v) {
	
	bstNode *traverse = NULL;
	
	if (tree != NULL) {
		traverse = tree->root;
		while (traverse != NULL) {
			//For VBST and RBT, we must make v into v->value. Otherwise it will break.
			if (tree->compare(v, traverse->value) == 0) {
				return 1;
			} else if (tree->compare(v, traverse->value) < 0) {
				traverse = traverse->left;
			} else {
				traverse = traverse->right;
			}
		}
	}
	return 0;
}

//Currently searches for the node as if it was inserting.
bstNode *findBSTNode(bst *tree,void *v) {
	bstNode *traverse = NULL;
	//printf("Finding BSTnode...\n");
	if (tree != NULL) {
		traverse = tree->root;
		while (traverse != NULL) {
			//For VBST and RBT, we must make v into v->value. Otherwise it will break.
			if (tree->compare(v, traverse->value) == 0) {
				//printf("BST find done! Found!\n");
				return traverse;
			} else if (tree->compare(v, traverse->value) < 0) {
				//printf("Traversing left.\n");
				traverse = traverse->left;
			} else {
				//printf("Traversing right.\n");
				traverse = traverse->right;
			}
		}
	}
	//printf("BST insert done!\n");
	return 0;
}

bstNode *swapToLeafBSTNode(bstNode *n) {

	bstNode *t = NULL;
	if (n->left == NULL && n->right == NULL) {
		return n;
	//Right exist, but not left, do Successor
	} else if (n->left == NULL && n->right != NULL) {
		t = swapValues(n, findSuccessor(n));
	//Left exist, but not right, do Predessesor. 
	} else if (n->left != NULL && n->right == NULL) {
		t = swapValues(n, findPredecessor(n));
	//If both exist, go with Predessesor
	} else {
		t = swapValues(n, findPredecessor(n));
	}
	
	return swapToLeafBSTNode(t);
	
}

void pruneBSTNode(bst *tree, bstNode *n) {
	
	if (n->left != NULL || n->right != NULL) {
		fprintf(stderr, "Prune: node has a child. Cannot prune. bstrees terminated.");
		exit(-1);
	}
	
	if (n == tree->root) {
		//It is the root, we must set the root to be null.
		tree->root = NULL;
	} else {
		if (n->parent->left == n) {
			//printf("Its the left child.\n");
			n->parent->left = NULL;
		} else {
			//printf("Its the right child\n");
			n->parent->right = NULL;
		}
		n = NULL;
	}
	
	free(n);
	
	tree->size--;
	
	return;
	
}

int sizeBST(bst *tree) {
	return tree->size;
}

void statisticsBST(bst *tree,FILE * fp) {
	fprintf(fp, "Nodes: %d\n", sizeBST(tree));
    fprintf(fp, "Minimum depth: %d\n", findBSTminheight(tree->root));
    fprintf(fp, "Maximum depth: %d\n", findBSTheight(tree->root));
	return;
}

void displayBST(FILE *fp, bst *tree) {
	
	if (tree->root != NULL) {
		// fprintf(fp, "[");
		// tree->display(fp, tree->root->value);
		// displayBSTpreorder(fp, tree->root->left, tree);
		// displayBSTpreorder(fp, tree->root->right, tree);
		displayPreOrderSub(fp, tree->root, tree);
	} else {
		fprintf(fp, "[ ]\n");
	}
	
	return;
}

//Private function
static void displayPreOrderSub(FILE *fp, bstNode *n, bst *tree) {
	if (n == NULL) {
		return;
	}
	fprintf(fp, "[");
	tree->display(fp, n->value);
	if (n->left != NULL) {
		displayPreOrderSub(fp, n->left, tree);
		if (n->right == NULL) {
			fprintf(fp, "]");
		}
	}
	if (n->right != NULL) {
		displayPreOrderSub(fp, n->right, tree);
		fprintf(fp, "]");
	}
	return;
}


void displayBSTDebug(FILE *fp, bst *tree) {
	displayBSTInOrder(fp, tree);
	return;
}

static void displayBSTInOrder(FILE *fp,bst *tree) {
	
	queue *theQueue = newQueue(tree->display);
	void *value;
	int level = 1;
	
	fprintf(fp, "0:");
	
	if (tree->root != NULL) {
		enqueue(theQueue, tree->root->value);
		enqueue(theQueue, NULL);
	} else {
		fprintf(fp, "\n");
	}
	
	while (sizeQueue(theQueue) > 0) {
		value = dequeue(theQueue);
		if (value == NULL) {
			fprintf(fp, "\n");
			if (sizeQueue(theQueue) != 0) {
				fprintf(fp, "%d:", level);
				level++;
				if (peekQueue(theQueue) != NULL) {
					enqueue(theQueue, NULL);
				} else {
					break;
				}
			}
		} else {
			bstNode *theNode = findBSTNode(tree, value);
			fprintf(fp, " ");
			if (theNode->left == NULL && theNode->right == NULL) {
				fprintf(fp, "=");
			}
			tree->display(fp, value);
			fprintf(fp, "(");
			tree->display(fp, theNode->parent->value);
			fprintf(fp, ")");
			if (theNode->parent->left == theNode) {
				fprintf(fp, "-l");
			} else if (theNode->parent->right == theNode) {
				fprintf(fp, "-r");
			} else if (theNode == tree->root) {
				fprintf(fp, "-");
			}
			if (theNode->left != NULL) {
				enqueue(theQueue, theNode->left->value);
			}
			if (theNode->right != NULL) {
				enqueue(theQueue, theNode->right->value);
			}
		}
	}

	return;
}

//optional
void checkBST(bst *tree) {
	bst *temp;
	temp = tree;
	int i = 1;
	if (i == 0) {
		temp->root = tree->root;
	}
	return;
}

/////////////////////////
/////////////////////////
////Private Functions////
/////////////////////////
/////////////////////////

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
	
	// if (n == NULL) {
		// return 0;
	// }
	// if (n->left == NULL || n->right == NULL) {
		// return 1;
	// }
	// if (n->left == NULL) {
		// return findBSTheight(n->right) + 1;
	// }
	// if (n->right == NULL) {
		// return findBSTheight(n->left) + 1;
	// }
	
	// return max(findBSTheight(n->left), findBSTheight(n->right)) + 1;
}



static int findBSTminheight(bstNode *n) {
	
	if (n == NULL) {
		return 0;
	}
	if (n->left == NULL || n->right == NULL) {
		return 1;
	} 
	if (n->left == NULL) {
		return findBSTminheight(n->right) + 1;
	}
	if (n->right == NULL) {
		return findBSTminheight(n->left) + 1;
	}
	
	//#define min(a,b) (a < b ? a : b)
	return min(findBSTminheight(n->left), findBSTminheight(n->right)) + 1;
	
	//return ((findBSTminheight(n->left) < findBSTminheight(n->right)) ? findBSTminheight(n->left) : findBSTminheight(n->right)) + 1;  
}

static bstNode *findSuccessor(bstNode *n) {
	
	bstNode *traverse = NULL;
	
	if (n->right == NULL) {
		return n;
	}
	
	traverse = n->right;
	
	while(traverse->left != NULL) {
		traverse = traverse->left;
	}
	
	return traverse;
}

static bstNode *findPredecessor(bstNode *n) {
	
	bstNode *traverse = NULL;
	
	if (n->left == NULL) {
		return n;
	}
	
	traverse = n->left;
	
	while(traverse->right != NULL) {
		traverse = traverse->right;
	}
	
	return traverse;
	
}

static bstNode *swapValues(bstNode *n, bstNode *m) {
	
	bstNode *temp = malloc(sizeof(bstNode));
	
	temp->value = n->value;
	n->value = m->value;
	m->value = temp->value;
	
	return m;
}


/////////////////////////
