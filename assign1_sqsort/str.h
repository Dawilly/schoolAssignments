#include <stdio.h>
#include <string.h>

#ifndef __STR_INCLUDED__
#define __STR_INCLUDED__

typedef struct str
    {
    char* value;
    } str;

extern str *newStr(char*);
extern char* getStr(str *);
extern char* setStr(str *,char*);
extern void displayStr(FILE *,void *);
extern int compareStr(void *,void *);
extern void freeStr(str *);

#define PINFINITY IN_MAX
#define NINFINITY IN_MIN

#endif
