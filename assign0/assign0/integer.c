#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "integer.h"

//extern void Fatal(char *,...);

integer *
newINTEGER(int x)
    {
    integer *p = malloc(sizeof(integer));
    if (p == 0) printf("out of memory\n");
    p->value = x;
    return p;
    }

int 
getINTEGER(integer *v)
    {
    return v->value;
    }

int 
setINTEGER(integer *v,int x)
    {
    int old = v->value;
    v->value = x;
    return old;
    }

void 
displayINTEGER(void *v, FILE *fp)
    {
    fprintf(fp,"%d",getInteger(v));
    }

int
compareINTEGER(void *v,void *w)
    {
    return ((integer *) v)->value - ((integer *) w)->value;
    }

void
freeINTEGER(integer *v)
    {
    free(v);
    }
