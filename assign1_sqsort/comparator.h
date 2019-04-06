#include <stdio.h>
#include "queue.h"
#include "stack.h"

#ifndef __COMPARATOR_INCLUDED__
#define __COMPARATOR_INCLUDED__

typedef int (*Comparator)(void*,void*);
typedef void (*Printer)(FILE*,void*);

int intComparator(void*, void*);
int realComparator(void*, void*);
int stringComparator(void*, void*);

#endif