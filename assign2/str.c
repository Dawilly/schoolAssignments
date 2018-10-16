#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "str.h"

//extern void Fatal(char *,...);

str *newStr(char* x) {
    str *p = malloc(sizeof(str));
    if (p == 0) printf("out of memory\n");
    p->value = x;
    return p;
}

char* getStr(str *v) {
    return v->value;
}

char* setStr(str *v,char* x) {
    char* old = v->value;
    strcpy(v->value, x);
    return old;
}

void displayStr(FILE *fp,void *v) {
    fprintf(fp,"\"%s\"",getStr(v));
}

int compareStr(void *v,void *w) {
	return strcmp( ((str*)v)->value, ((str *) w)->value );
    //return ((str *) v)->value - ((str *) w)->value;
}

void freeStr(str *v) {
    free(v);
}
