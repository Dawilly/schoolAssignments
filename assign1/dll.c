#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

//David Weil - CS201-001 - Spring 17
//dll.c - Double Link List Library
//Last revision: 1/25/2017

//newDLL(void*) - Creates a new DLL data structure, with a generic display function (Accessed via void pointer).
//Parameters: (void*)d - Pointer to generic display function
//Returns: Pointer address to DLL data structure
dll *newDLL(void (*d)(FILE *, void *)) {
	dll *items = malloc(sizeof(dll));
	if (items == 0) {
		fprintf(stderr,"out of memory");
		exit(-1);
    }
	
	//Set dll values.
	items->head = 0;
	items->tail = 0;
	items->size = 0;
	items->display = d;
	return items;
}

//insertDLL(dll*, int, void*) - Adds a dllnode to an existing dll data structure.
//Parameters: (dll*) items - The pointer value to the dll data structure
//			: (int) index - The index value (array-like) to insert new dllnode. Cannot be less then 0.
//			: (void*) value - The pointer value to the generic value.
//Returns: None (Void)
void insertDLL(dll *items,int index,void *value) {
	
	int i = 0;
	int pos = 0;
	dllnode *traverse = NULL;
	
	//Check to see if index is less then 0. Terminate if so.
	if (index < 0) {
		fprintf(stderr, "insertDLL: index cannot be less then 0");
		exit(-1);
	}
	
	//If the index is further from the last node in the list, create empty nodes.
	if ((sizeDLL(items) < index) && (sizeDLL(items) != index)) {
		for (i = (index - sizeDLL(items)); i < (index - 1); i++) {
			dllnode *newNode = malloc(sizeof(dllnode));
			if (newNode == 0) {
				fprintf(stderr,"out of memory");
				exit(-1);
			}
			newNode->value = NULL;
			newNode->next = NULL;
			newNode->previous = items->tail;
			items->tail->next = newNode;
			items->tail = newNode;
			if (sizeDLL(items) == 0) {
				items->head = newNode;
			}
			items->size++;
		}
	}
	
	//Create node
	dllnode *newNode = malloc(sizeof(dllnode));
	if (newNode == 0) {
		fprintf(stderr,"out of memory");
		exit(-1);
    }
	
	//Assign value to new node.
	newNode->value = value;
	
	//Find the appropriate position
	//Front
	if (index == 0) {
		traverse = items->head;
		newNode->next = items->head;
		newNode->previous = NULL;
		items->head = newNode;
		if (sizeDLL(items) == 0) {
			items->tail = newNode;
		} else {
			traverse->previous = newNode;
		}
	//Back
	} else if (index == sizeDLL(items)) {
		newNode->next = NULL;
		newNode->previous = items->tail;
		items->tail->next = newNode;
		items->tail = newNode;
	//Middle
	} else {
		//Middle-Back
		if (index > (sizeDLL(items) / 2)) {
			traverse = items->tail;
			pos = sizeDLL(items) - 1;
			while (traverse != NULL) {
				if (pos == (index-1)) {
					newNode->next = traverse->next;
					newNode->previous = traverse;
					traverse->next = newNode;
					newNode->next->previous = newNode;
					items->size++;
					return;
				}
				pos--;
				traverse = traverse->previous;
			}
		//Middle-Front
		} else {
			traverse = items->head;
			while (traverse != NULL) {
				if ((index-1) == pos) {
					newNode->next = traverse->next;
					newNode->previous = traverse;
					traverse->next = newNode;
					newNode->next->previous = newNode;
					items->size++;
					return;
				}
				pos++;
				traverse = traverse->next;
			}
		}
		
		//Error checking
		if (traverse == NULL) {
			return;
		}
	}
	
	//Increment size.
	items->size++;
	return;
	
}

//removeDLL(dll*, int) - Removes a specified dllnode from dll structure. Node index must exist. Cannot be less then zero.
//Parameters: (dll*) items - The dll data structure we're removing from.
//			: (int) index - The array-like index which we are removing the node from.
//Returns: None (Void)
void *removeDLL(dll *items,int index) {
	
	dllnode *traverse = NULL;
	dllnode *stepback = NULL;
	void* dumpedvalue = NULL;
	int pos = 0;
	
	if (index < 0) {
		fprintf(stderr,"removeDLL: index cannot be less then 0.");
		exit(-1);
	}
	
	if (index > (sizeDLL(items) - 1)) {
		fprintf(stderr,"removeDLL: index cannot be greater then sizeDLL().");
		exit(-1);
	}
	
	traverse = items->head;
	
	//Find the appropriate position.
	//Front
	if (index == 0) {
		items->head = traverse->next;
		if (sizeDLL(items) > 1) {
			items->head->previous = NULL;
		} else {
			items->tail = NULL;
		}
		dumpedvalue = traverse->value;
		free(traverse);
	//Back
	} else if (index == (sizeDLL(items) - 1)) {
		traverse = items->tail;
		stepback = traverse->previous;
		
		dumpedvalue = traverse->value;
		
		stepback->next = NULL;
		items->tail = stepback;
		free(traverse);
	//Middle
	} else {
		//Middle-Back
		if (index > (sizeDLL(items) / 2)) {
			traverse = items->tail;
			pos = sizeDLL(items)-1;
			while (traverse != NULL) {
				if (pos == index) {
					dumpedvalue = traverse->value;
					traverse->previous->next = traverse->next;
					if (traverse->next != NULL) {
						traverse->next->previous = traverse->previous;
					}
					free(traverse);
					items->size--;
					return dumpedvalue;
				}
				stepback = traverse;
				traverse = traverse->previous;
				pos--;
			}
		//Middle-Front
		} else {
			traverse = items->head;
			while (traverse != NULL) {
				if (pos == index) {
					dumpedvalue = traverse->value;
					traverse->previous->next = traverse->next;
					if (traverse->next != NULL) {
						traverse->next->previous = traverse->previous;
					}
					free(traverse);
					items->size--;
					return dumpedvalue;
				}
				stepback = traverse;
				traverse = traverse->next;
				pos++;
			}
		}
		
		//Error checking
		if (traverse == NULL) {
			return dumpedvalue;
		}
	}
	
	//Decrease itemsize.
	items->size--;
	
	return dumpedvalue;
}

//unionDLL(dll*, dll*) - Combines two dll data structures together.
//Parameters: (dll*) recipient - The dll data structure to receive new dllnodes.
//			: (dll*) donor - The dll data structure to donate its dllnodes. Will be empty afterwords.
//Returns: None (Void)
//		 : dll recipient will have new nodes. dll donor will be empty.
void unionDLL(dll *recipient,dll *donor) {
	
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

//sizeDLL(dll*) - Returns the number of nodes within a dll data structure.
//Parameters: (dll*) items - The dll data structure to check size of.
//Returns: (int) the number of nodes.
int sizeDLL(dll *items) {
	return items->size;
}

//displayDLL(FILE*, dll*) - Traverses through each nodes and prints the data value of each dllnode with dll's stored display function.
//Parameters: (FILE*) fp - The file pointer to stream write outs to.
//			: (dll*) items - The dll data structure to traverse through
//Returns: None (Void)
void displayDLL(FILE * fp,dll *items) {
	dllnode *traverse = items->head;
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

//displayDLL(FILE*, dll*) - Traverses through each node and prints the data value of each dllnode with dll's stored display function in reverse.
//Parameters: (FILE*) fp - The file pointer to stream write outs to.
//			: (dll*) items - The dll data structure to traverse through
//Returns: None (Void)
void displayDLLreverse(FILE * fp, dll *items) {
	dllnode *traverse = items->tail;
	fprintf(fp, "[");
	while(traverse != NULL) {
		if (traverse->value != NULL) { 
			items->display(fp, traverse->value);
		} else {
			fprintf(fp, "empty");
		}
		
		if (traverse->previous != NULL) {
			fprintf(fp, ",");
		}
		
		traverse = traverse->previous;
	}
	fprintf(fp, "]");
	return;
}

//getDLL(dll*, int) - Grabs the value stored at a specific index of the dll data structure
//Parameters: (dll*) items - dll data structure to pull from
//			: (int) index - The index to pull the value from.
//Return: Nothing (Void). Value is printed out.
void* getDLL(dll *items,int index) {
	
	dllnode *traverse = NULL;
	void* pulledvalue = NULL;
	int i = 0;
	
	if (index < 0) {
		fprintf(stderr,"getDLL: index cannot be less then 0.");
		exit(-1);
	}
	
	if (index > (sizeDLL(items) - 1)) {
		fprintf(stderr,"getDLL: index cannot be more then sizeDLL().");
		exit(-1);
	} 
	
	if (index < (sizeDLL(items) / 2)) {
		traverse = items->head;
		for(i = 0; i < index; i++) {
			traverse = traverse->next;
		}
	} else {
		traverse = items->tail;
		for(i = (sizeDLL(items) - 1); i > index; i--) {
			traverse = traverse->previous;
		}
	}
	
	pulledvalue = traverse->value;
	return pulledvalue;
}