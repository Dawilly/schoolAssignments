#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

//David Weil - CS201-001 - Spring 17
//sll.c - Single Link List Library
//Last revision: 1/25/2017

//newSLL(void*) - Creates a new SLL data structure, with a generic display function (Accessed via void pointer)
//Parameters: (void*)d - Pointer to generic display function
//Returns: Pointer address to SLL data structure
sll *newSLL(void (*d)(FILE *, void *)) {
	sll *items = malloc(sizeof(sll));
	if (items == 0) {
		fprintf(stderr,"out of memory");
		exit(-1);
    }
	items->head = 0;
	items->tail = 0;
	items->size = 0;
	items->display = d;
	return items;
}

//insertSLL(sll*, int, void*) - Adds a sllnode to an existing sll data structure.
//Parameters: (sll*) items - The pointer value to the sll data structure
//			: (int) index - The index value (array-like) to insert new sllnode. Cannot be less then 0.
//			: (void*) value - The pointer value to the generic value.
//Returns: None (Void)
void insertSLL(sll *items,int index,void *value) {
	
	int i = 0;
	int pos = 0;
	sllnode *traverse = NULL;
	
	if (index < 0) {
		fprintf(stderr, "insertSLL: index cannot be less then 0");
		exit(-1);
	}
	
	//Check to see if size is smaller than index. If so we need to malloc the
	//appropriate amount of nodes.
	if ((sizeSLL(items) < index) && (sizeSLL(items) != index)) {
		for (i = (index - sizeSLL(items)); i < (index - 1); i++) {
			sllnode *newNode = malloc(sizeof(sllnode));
			if (newNode == 0) {
				fprintf(stderr,"out of memory");
				exit(-1);
			}
			newNode->value = NULL;
			newNode->next = NULL;
			items->tail->next = newNode;
			items->tail = newNode;
			if (sizeSLL(items) == 0) {
				items->head = newNode;
			}
			items->size++;
		}
	}
	
	//Create node
	sllnode *newNode = malloc(sizeof(sllnode));
	if (newNode == 0) {
		fprintf(stderr,"out of memory");
		exit(-1);
	}
	newNode->value = value;
	
	//Find the appropriate position
	//Front
	if (index == 0) {
		newNode->next = items->head;
		items->head = newNode;
		if (sizeSLL(items) == 0) {
			items->tail = newNode;
		}
	//End
	} else if (index == sizeSLL(items)) {
		newNode->next = NULL;
		items->tail->next = newNode;
		items->tail = newNode;
	//Middle
	} else {
		traverse = items->head;
		while (traverse != NULL) {
			if ((index-1) == pos) {
				newNode->next = traverse->next;
				traverse->next = newNode;
				items->size++;
				return;
			}
			pos++;
			traverse = traverse->next;
		}
		
		//Error checking
		if (traverse == NULL) {
			printf("Unable to find node (insert), oddly enough");
			return;
		}
	}
	
	//Increment size
	items->size++;
	return;
}

//removeSLL(sll*, int) - Removes a specified sllnode from sll structure. Node index must exist. Cannot be less then zero.
//Parameters: (sll*) items - The sll data structure we're removing from.
//			: (int) index - The array-like index which we are removing the node from.
//Returns: None (Void)
void *removeSLL(sll *items,int index) {
	
	sllnode *traverse = NULL;
	sllnode *stepback = NULL;
	void* dumpedvalue = NULL;
	int pos = 0;
	
	if (index < 0) {
		fprintf(stderr,"removeSLL: index cannot be less then 0.");
		exit(-1);
	}
	
	if (index > (sizeSLL(items) - 1)) {
		fprintf(stderr,"removeSLL: index cannot be more then sizeSLL.");
		exit(-1);
	}
	
	traverse = items->head;
	//Front
	if (index == 0) {
		items->head = traverse->next;
		dumpedvalue = traverse->value;
		free(traverse);
	//Back
	} else if (index == (sizeSLL(items) - 1)) {
		while(traverse != items->tail) {
			stepback = traverse;
			traverse = traverse->next;
		}
		stepback->next = NULL;
		items->tail = stepback;
		dumpedvalue = traverse->value;
		free(traverse);
	//Middle
	} else {
		while(traverse != NULL) {
			if (pos == index) {
				dumpedvalue = traverse->value;
				stepback->next = traverse->next;
				free(traverse);
				items->size--;
				return dumpedvalue;
			}
			stepback = traverse;
			traverse = traverse->next;
			pos++;
		}
		
		//Error checking
		if (traverse == NULL) {
			printf("Unable to find node (remove), oddly enough");
			return dumpedvalue;
		}
	}
	
	//Decrement size
	items->size--;
	
	return dumpedvalue;
}

//unionSLL(sll*, sll*) - Combines two sll data structures together.
//Parameters: (sll*) recipient - The sll data structure to receive new sllnodes.
//			: (sll*) donor - The sll data structure to donate its sllnodes. Will be empty afterwords.
//Returns: None (Void)
//		 : sll recipient will have new nodes. sll donor will be empty.
void unionSLL(sll *recipient,sll *donor) {
	//sllnode *doney = donor->head;
	//sllnode *recipy = recipient->tail;
	
	if (donor->head == NULL) {
		//Simply return, we have an empty donor list.
		return;
	} else if (recipient->tail == NULL) {
		//Recipient is emtpy, just set the recipient variables to match donors
		recipient->head = donor->head;
		recipient->tail = donor->tail;
		recipient->size = recipient->size + donor->size;
	} else {
		recipient->tail->next = donor->head;
		recipient->tail = donor->tail;
		recipient->size = recipient->size + donor->size;
	}
	
	donor->head = NULL;
	donor->tail = NULL;
	donor->size = 0;
	
	return;
}

//sizeSLL(sll*) - Returns the number of nodes within a sll data structure.
//Parameters: (sll*) items - The dll data structure to check size of.
//Returns: (int) the number of nodes.
int sizeSLL(sll *items) {
	return items->size;
}

//displaySLL(FILE*, sll*) - Traverses through each nodes and prints the data value of each sllnode with sll's stored display function.
//Parameters: (FILE*) fp - The file pointer to stream write outs to.
//			: (sll*) items - The sll data structure to traverse through
//Returns: None (Void)
void displaySLL(FILE * fp,sll *items) {
	sllnode *traverse = items->head;
	fprintf(fp, "[");
	while(traverse != NULL) {
		if (traverse->value != NULL) { 
			items->display(fp, traverse->value);
		} else {
			fprintf(fp, "empty");
		}
		
		if (traverse->next != NULL) {
			fprintf(fp, ",");
		}
		
		traverse = traverse->next;
	}
	fprintf(fp, "]");
	return;
}

//displaySLL(FILE*, sll*) - Traverses through each node and prints the data value of each sllnode with sll's stored display function in reverse.
//Parameters: (FILE*) fp - The file pointer to stream write outs to.
//			: (sll*) items - The sll data structure to traverse through
//Returns: None (Void)
void* getSLL(sll *items,int index) {
	
	sllnode *traverse = items->head;
	void* pulledvalue = NULL;
	int i;
	
	if (index < 0) {
		fprintf(stderr,"getSLL: index cannot be less then 0.");
		exit(-1);
	}
	
	if (index > (sizeSLL(items) - 1)) {
		fprintf(stderr,"getSLL: index cannot be more then sizeSLL().");
		exit(-1);
	} 
	
	for(i = 0; i < index; i++) {
		traverse = traverse->next;
	}
	
	pulledvalue = traverse->value;
	return pulledvalue;
	
}