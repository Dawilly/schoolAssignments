#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*

	Lab 7 - Memory Reference Generator
	By David Weil
	
	As Engineers, we're lazy. This program creates psuedorandom
	list of memory references for Lab 7. Cause why not?
	
*/

bool memSet = false;
bool outSet = false;
bool seedSet = false;
bool amountSet = false;
int AOption = 0;
int MOption = 0;
char OOption[100] = "";
unsigned int seed = 0;

bool validateByTwo(int);
void processOptions(int, char**);

int main(int argc, char** argv) {
	FILE* output;
	int i;
	int rw;
	int address;
	
	if (argc > 1) {
		processOptions(argc, argv);
	} else {
		printf("Syntax: ./genMem -A LINEAMOUNT -O=FILENAME -M MMBYTES [-s SEED]\n");
		exit(0);
	}
	
	if (!memSet && !outSet) {
		printf("Syntax: ./genMem -A LINEAMOUNT -O=FILENAME -M MMBYTES [-s SEED]\n");
		exit(0);
	}
	
	if (!validateByTwo(MOption)) {
		printf("Error: Main Memory needs to be to the power of two you dummy.\n");
		exit(0);
	}
	
	if (seedSet) {
		srand(seed);
	} else {
		srand(time(NULL));
	}
	
	output = fopen(OOption, "w");
	if (output == NULL) {
		printf("Error: Unable to open file <%s>\n", OOption);
		exit(-1);
	} else {
		printf("Writing to file <%s>...\n", OOption);
	}
	
	fprintf(output, "%d\n\n", AOption);
	for (i = 0; i < AOption; i++) {
		rw = rand() % 2;
		address = rand() % MOption;
		printf("Mem Ref #%d: %c %d\n", i, (rw == 1) ? 'W' : 'R', address);
		fprintf(output, "%c %d\n", (rw == 1) ? 'W' : 'R', address);
	}
	fprintf(output, "\n");
	printf("Done!\n");
	fclose(output);
	
	return 0;
}

bool validateByTwo(int x) {
	int c; 
	int f;
	
	if (x <= 0) {
		return false;
	}
	
	c = (int) ceil(log(x) / log(2));
	f = (int) floor(log(x) / log(2));
	if (c == f) {
		return true;
	} else {
		return false;
	}
}

void processOptions(int argc, char** argv) {
	int index = 1;
	int used;
	int seperate;
	char* arg;
	
	while (index < argc && *argv[index] == '-') {
		if (argv[index][1] == '\0') {
			return;
		}
		
		seperate = 0;
		used = 0;
		
		if (argv[index][2] == '\0') {
			arg = argv[index+1];
			seperate = 1;
		} else {
			arg = argv[index]+2;
		}
		
		switch (argv[index][1]) {
			case 'M':
				MOption = atoi(arg);
				memSet = true;
				used = 1;
				break;
			case 'A':
				AOption = atoi(arg);
				amountSet = true;
				used = 1;
				break;
			case 's':
				seed = atoi(arg);
				seedSet = true;
				used = 1;
				break;
			case 'O':
				if (argv[index][2] == '=' && strlen(&argv[index][3]) < 101) {
					strcpy(OOption, &argv[index][3]);
					outSet = true;
				}
				break;
			default:
				break;
		}
		
		if (seperate && used) {
			index++;
		}
		
		index++;
	}
}