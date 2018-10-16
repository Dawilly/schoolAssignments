#include <stdio.h>

#ifndef __INTEGER_INCLUDED__
#define __INTEGER_INCLUDED__

typedef struct integer
    {
    int value;
    } integer;

extern integer *newINTEGER(int);
extern int getINTEGER(integer *);
extern int setINTEGER(integer *,int);
extern void displayINTEGER(void *,FILE *);
extern int compareINTEGER(void *,void *);
extern void freeINTEGER(integer *);

#define PINFINITY IN_MAX
#define NINFINITY IN_MIN

#endif
