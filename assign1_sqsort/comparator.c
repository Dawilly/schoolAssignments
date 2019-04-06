#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "comparator.h"
#include "integer.h"
#include "real.h"
#include "str.h"

int intComparator(void* x, void* y) {
	
	int results;
	
	results = compareInteger(x, y);
	
	if (results < 0) {
		return -1;
	} else if (results > 0) {
		return 1;
	} else {
		return 0;
	}
	
	//return results;
}

int realComparator(void* x, void* y) {
	
	double results;
	
	results = compareReal(x, y);
	
	if (results < 0.00) {
		return -1;
	} else if (results > 0.00) {
		return 1;
	} else {
		return 0;
	}
	//return 0;
}

int stringComparator(void* x, void* y) {
	
	int results;
	
	results = compareStr(x, y);
	
	if (results < 0) {
		return -1;
	} else if (results > 0) {
		return 1;
	} else {
		return 0;
	}
	
	//return 0;
}