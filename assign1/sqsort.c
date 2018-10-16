#include <stdio.h>
#include <stdlib.h>
#include "comparator.h"
#include "scanner.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"
#include "str.h"
#include "real.h"

void sort(queue*, stack*, queue*, int (*comp)(void *,void *), int);

int main(int argc, char** argv) {
	
	FILE *fp;
	
	Comparator comp;
	Printer print;	
	char option;
	
	int finInt;
	double finReal;
	char* finStr;
	
	queue* In;
	queue* Out;
	stack* working;
	
	if (argc < 2) {
		fprintf(stderr,"Not enough arguments.\n");
		exit(-1);
	}
	
	//Set up queue and stack, according to option flag. Also check if option is valid.
	switch (argv[1][1]) {
		case 'd':
			//printf("d flag enabled.\n");
			comp = intComparator;
			print = displayInteger;
			option = 'd';
			break;
		case 'r':
			//printf("r flag enabled.\n");
			comp = realComparator;
			print = displayReal;
			option = 'r';
			break;
		case 's':
			//printf("s flag enabled.\n");
			comp = stringComparator;
			print = displayStr;
			option = 's';
			break;
		case 'v':
			printf("David Michael A. Weil\n");
			return 0;
			break;
		default:
			printf("Unknown flag '%c', valid flags are -d, -r, -s, and -v.\n", argv[1][1]);
			return 0;
			break;
	}
	
	//Set up stack and queues
	In = newQueue(print);
	Out = newQueue(print);
	working = newStack(print);
	
	//Read in from file source
	if (argc == 2) {
		fp = stdin;
	} else {
		fp = fopen(argv[2], "r");
	}
	
	if (fp) {
		if (option == 's') {
			finStr = readString(fp);
			while(!feof(fp)) {
				enqueue(In, newStr(finStr));
				finStr = readString(fp);
			}
		} else if (option == 'r') {
			finReal = readReal(fp);
			while(!feof(fp)) {
				enqueue(In, newReal(finReal));
				finReal = readReal(fp);
			}
		} else if (option == 'd') {
			finInt = readInt(fp);
			while(!feof(fp)) {
				enqueue(In, newInteger(finInt));
				finInt = readInt(fp);
			}
		} else {
			fprintf(stderr, "Unknown flag\n");
			exit(-1);
		}
	} else {
		fprintf(stderr, "Error: File not found\n");
		exit(-1);
	}
	displayQueue(stdout, In);
	printf("\n");
	sort(In, working, Out, comp, 1);
	
	return 0;
	
}

void sort(queue* in, stack* working, queue* out, int (*comp)(void *,void *), int first) {
	
	/*
	while input is not empty, do one of these operations, with prioritiy in order
		operation 1) if (qinput[0] <= stack_top <= last item moved to qoutput), move item from stack to qoutput
		operation 2) if (qinput only has 1 item left), move item from qinput to qoutput
		operation 3) if (qinput[0] < qinput[1]), move item from qinput to stack
		operation 4) if (qinput[0] >= qinput[1]), move item from qinput to qoutput
	
	after you are out of while loop
		move everything from stack to qoutput
		
		
	*/
	
	void* working_value = NULL;
	void* previous_value = NULL;
	int change = 0;
	int results;
	
	while (sizeQueue(in)) {
		//Operation 1
		if (sizeStack(working) != 0 && previous_value != NULL) {
			results = comp(peekQueue(in), peekStack(working));
			if (results <= 0) {
				results = comp(peekStack(working), previous_value);
				if (results <= 0) {
					//printf("Perform Operation 1.\n");
					working_value = pop(working);
					enqueue(out, working_value);
					previous_value = working_value;
					continue;
				}
			}
		}
		
		//Operation 2
		if (sizeQueue(in) == 1) {
			//printf("Perform Operation 2.\n");
			working_value = dequeue(in);
			enqueue(out, working_value);
			//if (previous_value != NULL) {
			//	results = comp(working_value, previous_value);
			//	if (results > 0) {
			//		change = 1;
			//	}
			//}
			previous_value = working_value;
			continue;
		}
		
		//Operation 3 & 4
		working_value = dequeue(in);
		results = comp(working_value, peekQueue(in));
		if (results < 0) {
			//printf("Perform Operation 3.\n");
			push(working, working_value);
			change = 1;
		} else {
			//printf("Perform Operation 4.\n");
			enqueue(out, working_value);
		}
		previous_value = working_value;
		
	}
	
	while(sizeStack(working)) {
		//change = 1;
		working_value = pop(working);
		enqueue(out, working_value);
	}
	
	if (change) {
		displayQueue(stdout, out);
		printf("\n");
		sort(out, working, in, comp, 0);
	}
	
	if (!change && first) {
		displayQueue(stdout, out);
		printf("\n");
	}
	
	////-------
	
	return;
}