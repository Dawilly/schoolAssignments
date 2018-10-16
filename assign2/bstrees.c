#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "bst.h"
#include "vbst.h"
#include "scanner.h"
#include "str.h"
#include "queue.h"
#include "rbt.h"
#include "avl.h"

char* cleanstring(char*);
char *removeSpaces(char *);
char* getNextWord(FILE*);
char getNextCommand(FILE*);

int main(int argc, char** argv) {
	
	FILE *out;
	FILE *in;
	FILE *commands;
	
	char *str;
	char cmd;
	
	int x = 0;
	
	bst *Basic = NULL;
	vbst *VanillaTree = NULL;
	rbt *RedBlack = NULL;
	AVL *AVLTree = NULL;
	
	bstNode *search_base = NULL;
	
	if (argc == 4) {
		out = stdout;
	} else if (argc == 5) {
		out = fopen(argv[4], "w");
		if (!out) {
			fprintf(stderr, "Unable to open file: %s\n", argv[4]);
			exit(-1);
		}
	} else {
		fprintf(stderr, "Insufficient number of command line arguments.\n");
		fprintf(stderr, "Program syntax: bstrees -v/-r corpus commands [output]\n");
		exit(-1);
	}
	
	in = fopen(argv[2], "r");
	
	if (!in) {
		fprintf(stderr, "Unable to open file: %s\n", argv[2]);
		exit(-1);
	}
	
	commands = fopen(argv[3], "r");
	
	if (!commands) {
		fprintf(stderr, "Unable to open file: %s\n", argv[3]);
		exit(-1);
	}
	
	switch(argv[1][1]) {
		case 'b':
			//Basic tree (DEBUG ONLY)
			
			//Declare new tree
			Basic = newBST(displayStr, compareStr);
			
			//Read in from corpus (in)
			str = getNextWord(in);
			while(!feof(in)) {
				insertBST(Basic, newStr(str));
				str = getNextWord(in);
			}
			
			//Read in from commands
			while(!feof(commands)) {
				cmd = getNextCommand(commands);
				switch (cmd) {
					case 'i':
						str = getNextWord(commands);
						insertBST(Basic, newStr(str));
						break;
					case 'd':
						str = getNextWord(commands);
						search_base = findBSTNode(Basic, newStr(str));
						if (search_base != 0) {
							search_base = swapToLeafBSTNode(search_base);
							pruneBSTNode(Basic, search_base);
						} else {
							fprintf(stderr, "Value \"%s\" not found.\n", str);
						}
						break;
					case 'f':
						//No frequency in Basic BST. Read the next word and dump it.
						str = getNextWord(commands);
						break;
					case 's':
						displayBST(out, Basic);
						break;
					case 'r':
						statisticsBST(Basic, out);
						break;
				}
			}
			break;
		case 'v':
			//Vanilla tree
			
			//Declare new tree
			VanillaTree = newVBST(displayStr, compareStr);
			
			//Read in from corpus (in)
			str = getNextWord(in);
			while(!feof(in)) {
				//printf("in: %s\n", str);
				if (strlen(str) != 0) {
					insertVBST(VanillaTree, newStr(str));
				}
				str = getNextWord(in);
				
			}
			
			//Read in from commands
			while(!feof(commands)) {
				cmd = getNextCommand(commands);
				//printf("cmd: %c\n", cmd);
				switch (cmd) {
					case 'i':
						str = getNextWord(commands);
						//printf("read in: %s\n", str);
						if (strlen(str) != 0) {
							insertVBST(VanillaTree, newStr(str));
						}
						break;
					case 'd':
						str = getNextWord(commands);
						deleteVBST(VanillaTree, newStr(str));
						break;
					case 'f':
						str = getNextWord(commands);
						x = findVBST(VanillaTree, newStr(str));
						fprintf(out, "Frequency of \"%s\"", str);
						fprintf(out, ": %d\n", x);
						break;
					case 's':
						displayVBST(out, VanillaTree);
						break;
					case 'r':
						statisticsVBST(VanillaTree, out);
						break;
				}
				//printf("str: %s\n", str);
			}
			break;
		case 'r':
			//Red-Black Tree
			
			//Declare new tree
			RedBlack = newRBT(displayStr, compareStr);
			
			//Read in from corpus (in)
			str = getNextWord(in);
			while(!feof(in)) {
				if (strlen(str) != 0) {
					insertRBT(RedBlack, newStr(str));
				}
				str = getNextWord(in);
			}
			
			//Read in from commands
			while(!feof(commands)) {
				cmd = getNextCommand(commands);
				switch (cmd) {
					case 'i':
						str = getNextWord(commands);
						if (strlen(str) != 0) {
							insertRBT(RedBlack, newStr(str));
						}
						break;
					case 'd':
						str = getNextWord(commands);
						deleteRBT(RedBlack, newStr(str));
						break;
					case 'f':
						str = getNextWord(commands);
						x = findRBT(RedBlack, newStr(str));
						fprintf(out, "Frequency of \"%s\"", str);
						fprintf(out, ": %d\n", x);
						break;
					case 's':
						displayRBT(out, RedBlack);
						break;
					case 'r':
						statisticsRBT(RedBlack, out);
						break;
				}
			}
			
			break;
		case 'a':
			//AVL Tree
			
			AVLTree = newAVL(displayStr, compareStr);
			
			str = getNextWord(in);
			while(!feof(in)) {
				if (strlen(str) != 0) {
					insertAVL(AVLTree, newStr(str));
				}
				str = getNextWord(in);
			}
			
			//Read in from commands
			while(!feof(commands)) {
				cmd = getNextCommand(commands);
				switch (cmd) {
					case 'i':
						str = getNextWord(commands);
						if (strlen(str) != 0) {
							insertAVL(AVLTree, newStr(str));
						}
						break;
					case 'd':
						str = getNextWord(commands);
						deleteAVL(AVLTree, newStr(str));
						break;
					case 'f':
						//str = getNextWord(commands);
						//x = findRBT(RedBlack, newStr(str));
						//fprintf(out, "Frequency of \"%s\"", str);
						//fprintf(out, ": %d\n", x);
						break;
					case 's':
						displayAVL(out, AVLTree);
						break;
					case 'r':
						//statisticsRBT(RedBlack, out);
						break;
					case 'p':
						displayAVLdebug(out, AVLTree);
						break;
				}
			}
			
			break;
		default:
			fprintf(out, "Invalid flag -%c. Valid flags are -v or -r", argv[1][1]);
			break;
	}
	fclose(in);
	fclose(out);
	fclose(commands);
	return 0;
}

char* cleanstring(char *ch) {
	char *input = ch;
	char *output = ch;
	do {
		if (isspace(*input)) {
			while (isspace(*input) && isspace(*(input+1))) {
				input++;
			}
			*output++ = ' ';
		}
		else if (isalpha(*input) || *input == 0) {
			*output++ = tolower(*input);
		}
	} while(*input++ != 0);
	
	//if (ch != NULL) {
		//return removeSpaces(ch);
	//} else {
		return ch;
}

char *removeSpaces(char *str) {
    char *input = str;
	char *output = str;
    int previousWasSpace = 0;

    while (*input) {
		//printf("char: %c\n", input);
        if (isspace(*input)) {
            if (!previousWasSpace) {
                *output++ = ' ';
                previousWasSpace = 1;
            }
        } else {
            *output++ = *input;
            previousWasSpace = 0;
        }
        ++input;
    }
    *output = '\0';
    return str;
}

char getNextCommand(FILE *fp) {
	char command;
	if (!feof(fp)) {
		command = readChar(fp);
	} else {
		command = 0;
	}
	return command;
}

char* getNextWord(FILE *fp) {
	char* str;
	int pending;
	if (!feof(fp)) {
		pending = stringPending(fp);
		if (pending) {
			str = readString(fp);
			//printf("Read in: %s\n", str);
		} else {
			str = readToken(fp);
			//printf("Read in: %s\n", str);
		}
		if (str != NULL) {
			str = cleanstring(str);
			//printf("After cleaning: %s\n", str);
		}
	} else {
		str = NULL;
	}
	return str;
}