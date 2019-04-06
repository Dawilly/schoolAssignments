#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "da.h"

struct da {
	void** array;
	int capacity;
	int size;
	void (*freeIt)(void*);
	void (*displayIt)(void* , FILE*);
};

extern DA* newDA() {
	DA *theNewOne = malloc(sizeof(DA));
	theNewOne->capacity = 1;
	theNewOne->size = 0;
	theNewOne->array = malloc(sizeof(void*) * theNewOne->capacity);
	theNewOne->freeIt = NULL;
	theNewOne->displayIt = NULL;
}

extern void  setDAdisplay(DA *myDA, void (*dis)(void *,FILE *)){
	myDA->displayIt = dis;
}
extern void  setDAfree(DA *myDA,void (*f)(void *)){
	myDA->freeIt = f;	
}
extern void  insertDA(DA *items,int index,void *value){
	if (items->size == items->capacity){
		items->capacity = items->capacity * 2;
		items->array = realloc(items->array, sizeof(void*) * items->capacity);
		assert(items->array !=0 );
	}/*
	for(int i = index; i >= 0; i--){
		items->array[index] = items->array[index+1];
	}*/
	for(int i = items->size ; i >= index; i--){
		items->array[i] = items->array[i+1];
	}
	items->array[index] = value;
	items->size = items->size + 1;	
}
extern void *removeDA(DA *items,int index){
	assert(items->size > 0); //capacity
	void *itemToFree = items->array[index];
	for(int i = index; i <= items->size ; i++){
		items->array[i] = items->array[i-1];
	}
	items->size = items->size - 1;	
	float ratio = items->size / items->capacity;
	if (ratio <= 0.25){
		items->capacity = items->capacity / 2;
		items->array = realloc(items->array,sizeof(void*) *items->capacity);
	}
	//myDA->freeIt(itemToFree);
	return itemToFree;
}
extern void  unionDA(DA *recipient,DA *donor){
	/*if (recipient->size + donor->size < recipient->capacity){
	int index = recipient->size ;
	for(int i = 0; i<= donor->size; i++){
		insertDA(recipient, index+i, donor->array[i]);
	}*/
	//free donor array
	while(donor->size > 0){
		void* value = removeDA(donor, 0);
		insertDA(recipient, recipient->size, value);
	}
}
extern void *getDA(DA *items,int index){
	assert(0 <= index < items->size);
	void *value = items->array[index];
	return value;
}
extern void *setDA(DA *items,int index,void *value){
	assert(0 <= index <= items->size);
	void *oldValue = items->array[index];
	if(items->size > index){
		items->array[index]= value;
	}
	if(items->size == index){
		insertDA(items, index, value);
	}
	return oldValue;	
}
extern int   sizeDA(DA *items){
	int size = items->size;
	return size;
}
extern void  displayDA(DA *items,FILE *fp){
	int index = items->size - 1;
	//If no display method is set (see setDAdisplay), the address of each item is printed (using %p). 
	//Each address is preceded by an @ sign. 
	fprintf(fp,"%c", '[');
	if(items->displayIt != NULL){
		for( int i = 0; i <= index; i++){
		//while(item->size > 0){
			items->displayIt(items->array[i], fp);
			if(i < index){
				fprintf(fp,"%c", ',');
			}
		}
	}
	else{
		for( int i = 0; i <= index; i++){
			fprintf(fp,"%c%p",'@', items->array[i]);
			if(i < index){
				fprintf(fp,"%c", ',');
			}
		}
	}

	

	fprintf(fp,"%c", ']');

}
extern int  debugDA(DA *items,int level){
	int flag = items->capacity - items->size; 
	/*if(flag > 0){
		if(item->size == 0){
			fprintf("[%d]", flag);
		}
		else {
			fprintf(",[%d]", flag);
		}
	}*/
	return flag;
}

extern void  freeDA(DA *items){
	if(items->freeIt != NULL){
		while(items->size>0){
			items->freeIt(items);
		}
	}
	free(items);
}


























