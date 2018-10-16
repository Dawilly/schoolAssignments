#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "dll.h"
#include "stack.h"
#include "queue.h"
#include "integer.h"

//David Weil - CS201-001 - Spring 17
//assign0.c - Assignment 0 Test file
//This file is used to test sll.h, sll.c, dll.h, dll.c
//stack.h, stack.c, queue.h, and queue.c
//Last revision: 1/25/2017

//Main test
int main() {
	
	int random;
	int count;
	
	printf("TEST #1\n");
    sll *a = newSLL(displayInteger);
    insertSLL(a,0,newInteger(83));
    insertSLL(a,0,newInteger(86));
    insertSLL(a,0,newInteger(77));
    insertSLL(a,0,newInteger(15));
    insertSLL(a,0,newInteger(93));
    insertSLL(a,0,newInteger(35));
    insertSLL(a,0,newInteger(86));
    insertSLL(a,0,newInteger(92));
    insertSLL(a,0,newInteger(49));
    insertSLL(a,0,newInteger(21));
	
	printf("Your output:\n");
    displaySLL(stdout,a);
	printf("\n");

	printf("Expected output:\n");
	printf("[21,49,92,86,35,93,15,77,86,83]\n");
	printf("\n");

	printf("TEST #2\n");
    sll *b = newSLL(displayInteger);
    insertSLL(b,sizeSLL(b),newInteger(83));
    insertSLL(b,sizeSLL(b),newInteger(86));
    insertSLL(b,sizeSLL(b),newInteger(77));
    insertSLL(b,sizeSLL(b),newInteger(15));
    insertSLL(b,sizeSLL(b),newInteger(93));
    insertSLL(b,sizeSLL(b),newInteger(35));
    insertSLL(b,sizeSLL(b),newInteger(86));
    insertSLL(b,sizeSLL(b),newInteger(92));
    insertSLL(b,sizeSLL(b),newInteger(49));
    insertSLL(b,sizeSLL(b),newInteger(21));
	printf("Your output:\n");
    displaySLL(stdout,b);
	printf("\n");

	printf("Expected output:\n");
	printf("[83,86,77,15,93,35,86,92,49,21]\n");
	printf("\n");

	printf("TEST #3\n");
    sll *c = newSLL(displayInteger);
    insertSLL(c,0,newInteger(83));
    insertSLL(c,1,newInteger(77));
    insertSLL(c,1,newInteger(93));
    insertSLL(c,0,newInteger(86));
    insertSLL(c,1,newInteger(49));
    insertSLL(c,1,newInteger(62));
    insertSLL(c,4,newInteger(90));
    insertSLL(c,6,newInteger(63));
    insertSLL(c,0,newInteger(40));
    insertSLL(c,6,newInteger(72));
    insertSLL(c,8,newInteger(11));
    insertSLL(c,9,newInteger(67));
    insertSLL(c,5,newInteger(82));
    insertSLL(c,13,newInteger(62));
    insertSLL(c,10,newInteger(67));
    insertSLL(c,10,newInteger(29));
    insertSLL(c,0,newInteger(22));
    insertSLL(c,3,newInteger(69));
    insertSLL(c,15,newInteger(93));
    insertSLL(c,2,newInteger(11));
    insertSLL(c,18,newInteger(29));
    insertSLL(c,1,newInteger(21));
    insertSLL(c,1,newInteger(84));
    insertSLL(c,20,newInteger(98));
    insertSLL(c,20,newInteger(15));
    insertSLL(c,24,newInteger(13));
    insertSLL(c,26,newInteger(91));
    insertSLL(c,9,newInteger(56));
    insertSLL(c,0,newInteger(62));
    insertSLL(c,1,newInteger(96));
    insertSLL(c,21,newInteger(5));
    insertSLL(c,7,newInteger(84));
    insertSLL(c,20,newInteger(36));
    insertSLL(c,5,newInteger(46));
    insertSLL(c,7,newInteger(13));
    insertSLL(c,27,newInteger(24));
    insertSLL(c,19,newInteger(82));
    insertSLL(c,13,newInteger(14));
    insertSLL(c,23,newInteger(34));
    insertSLL(c,30,newInteger(43));
	printf("Your output:\n");
    displaySLL(stdout,c);
	printf("\n");

	printf("Expected output:\n");
	printf("[62,96,22,84,21,46,40,13,11,84,86,69,62,14,49,56,83,82,90,72,82,93,11,34,29,36,67,67,5,93,43,24,63,15,98,29,77,13,62,91]\n");
	printf("\n");
	
	printf("TEST #4\n");
    sll *d = newSLL(displayInteger);
    insertSLL(d,0,newInteger(86));
    insertSLL(d,1,newInteger(93));
    insertSLL(d,0,newInteger(92));
    insertSLL(d,3,newInteger(62));
    insertSLL(d,3,newInteger(59));
    insertSLL(d,0,newInteger(40));
    insertSLL(d,3,newInteger(36));
    insertSLL(d,5,newInteger(67));
    insertSLL(d,8,newInteger(30));
    insertSLL(d,5,newInteger(67));
    insertSLL(d,10,newInteger(2));
    removeSLL(d,7);
    removeSLL(d,3);
    insertSLL(d,2,newInteger(11));
    removeSLL(d,3);
    removeSLL(d,2);
    insertSLL(d,5,newInteger(37));
    insertSLL(d,0,newInteger(15));
    insertSLL(d,2,newInteger(26));
    insertSLL(d,9,newInteger(56));
    insertSLL(d,6,newInteger(70));
    insertSLL(d,13,newInteger(5));
    insertSLL(d,11,newInteger(27));
    insertSLL(d,1,newInteger(46));
    insertSLL(d,11,newInteger(57));
    removeSLL(d,14);
    removeSLL(d,14);
    removeSLL(d,14);
    insertSLL(d,5,newInteger(43));
    insertSLL(d,12,newInteger(8));
	printf("Your output:\n");
    displaySLL(stdout,d);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");

	printf("TEST #5\n");
    sll *e = newSLL(displayInteger);
    insertSLL(e,0,newInteger(86));
    insertSLL(e,1,newInteger(93));
    insertSLL(e,0,newInteger(92));
    insertSLL(e,3,newInteger(62));
    insertSLL(e,3,newInteger(59));
    insertSLL(e,0,newInteger(40));
    insertSLL(e,3,newInteger(36));
    insertSLL(e,5,newInteger(67));
    insertSLL(e,8,newInteger(30));
    insertSLL(e,5,newInteger(67));
    insertSLL(e,10,newInteger(2));
    removeSLL(e,7);
    removeSLL(e,3);
    insertSLL(e,2,newInteger(11));
    removeSLL(e,3);
    removeSLL(e,2);
    insertSLL(e,5,newInteger(37));
    insertSLL(e,0,newInteger(15));
    insertSLL(e,2,newInteger(26));
    insertSLL(e,9,newInteger(56));
    insertSLL(e,6,newInteger(70));
    insertSLL(e,13,newInteger(5));
    insertSLL(e,11,newInteger(27));
    insertSLL(e,1,newInteger(46));
    insertSLL(e,11,newInteger(57));
    removeSLL(e,14);
    removeSLL(e,14);
    removeSLL(e,14);
    insertSLL(e,5,newInteger(43));
    insertSLL(e,12,newInteger(8));
	printf("Your output:\n");
    displaySLL(stdout,e);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");

	printf("TEST #6\n");
    sll *f = newSLL(displayInteger);
    insertSLL(f,0,newInteger(86));
    insertSLL(f,1,newInteger(93));
    insertSLL(f,0,newInteger(92));
    insertSLL(f,3,newInteger(62));
    insertSLL(f,3,newInteger(59));
    insertSLL(f,0,newInteger(40));
    insertSLL(f,3,newInteger(36));
    insertSLL(f,5,newInteger(67));
    insertSLL(f,8,newInteger(30));
    insertSLL(f,5,newInteger(67));
    insertSLL(f,10,newInteger(2));
    removeSLL(f,7);
    removeSLL(f,3);
    insertSLL(f,2,newInteger(11));
    removeSLL(f,3);
    removeSLL(f,2);
    insertSLL(f,5,newInteger(37));
    insertSLL(f,0,newInteger(15));
    insertSLL(f,2,newInteger(26));
    insertSLL(f,9,newInteger(56));
    insertSLL(f,6,newInteger(70));
    insertSLL(f,13,newInteger(5));
    insertSLL(f,11,newInteger(27));
    insertSLL(f,1,newInteger(46));
    insertSLL(f,11,newInteger(57));
    removeSLL(f,14);
    removeSLL(f,14);
    removeSLL(f,14);
    insertSLL(f,5,newInteger(43));
    insertSLL(f,12,newInteger(8));
	printf("Your output:\n");
    displaySLL(stdout,f);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");

	printf("TEST #7\n");
    sll *g = newSLL(displayInteger);
    insertSLL(g,0,newInteger(86));
    insertSLL(g,1,newInteger(93));
    insertSLL(g,0,newInteger(92));
    insertSLL(g,3,newInteger(62));
    insertSLL(g,3,newInteger(59));
    insertSLL(g,0,newInteger(40));
    insertSLL(g,3,newInteger(36));
    insertSLL(g,5,newInteger(67));
    insertSLL(g,8,newInteger(30));
    insertSLL(g,5,newInteger(67));
    insertSLL(g,10,newInteger(2));
    removeSLL(g,7);
    removeSLL(g,3);
    insertSLL(g,2,newInteger(11));
    removeSLL(g,3);
    removeSLL(g,2);
    insertSLL(g,5,newInteger(37));
    insertSLL(g,0,newInteger(15));
    insertSLL(g,2,newInteger(26));
    insertSLL(g,9,newInteger(56));
    insertSLL(g,6,newInteger(70));
    insertSLL(g,13,newInteger(5));
    insertSLL(g,11,newInteger(27));
    insertSLL(g,1,newInteger(46));
    insertSLL(g,11,newInteger(57));
    removeSLL(g,14);
    removeSLL(g,14);
    removeSLL(g,14);
    insertSLL(g,5,newInteger(43));
    insertSLL(g,12,newInteger(8));
	printf("Your output:\n");
    displaySLL(stdout,g);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");

	printf("TEST #8\n");
    sll *h = newSLL(displayInteger);
    insertSLL(h,0,newInteger(86));
    insertSLL(h,1,newInteger(93));
    insertSLL(h,0,newInteger(92));
    insertSLL(h,3,newInteger(62));
    insertSLL(h,3,newInteger(59));
    insertSLL(h,0,newInteger(40));
    insertSLL(h,3,newInteger(36));
    insertSLL(h,5,newInteger(67));
    insertSLL(h,8,newInteger(30));
    insertSLL(h,5,newInteger(67));
    insertSLL(h,10,newInteger(2));
    removeSLL(h,7);
    removeSLL(h,3);
    insertSLL(h,2,newInteger(11));
    removeSLL(h,3);
    removeSLL(h,2);
    insertSLL(h,5,newInteger(37));
    insertSLL(h,0,newInteger(15));
    insertSLL(h,2,newInteger(26));
    insertSLL(h,9,newInteger(56));
    insertSLL(h,6,newInteger(70));
    insertSLL(h,13,newInteger(5));
    insertSLL(h,11,newInteger(27));
    insertSLL(h,1,newInteger(46));
    insertSLL(h,11,newInteger(57));
    removeSLL(h,14);
    removeSLL(h,14);
    removeSLL(h,14);
    insertSLL(h,5,newInteger(43));
    insertSLL(h,12,newInteger(8));
	printf("Your output:\n");
    displaySLL(stdout,h);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");

	printf("TEST #9\n");
    sll *i = newSLL(displayInteger);
    sll *j = newSLL(displayInteger);
    printf("(inserting 100 random integers into list a at random locations)\n");
    printf("(inserting 100 random integers into list b at random locations)\n");
    printf("(unioning list a and list b, 10000 times)\n");
	printf("Expected output:\n");
	//printf("[");
	for (count = 0; count < 100; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		//printf("%d,", random);
		insertSLL(i,0,newInteger(random));
	}
	for (count = 0; count < 100; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		//printf("%d,", random);
		insertSLL(j,0,newInteger(random));
	}
	displaySLL(stdout, i);
	displaySLL(stdout, j);
	//printf("]\n");
	for (count = 1; count < 10000; count++) {
		if ((count % 2) == 0) {
			unionSLL(j,i);
		} else {
			unionSLL(i,j);
		}
	}
	printf("Your output:\n");
    displaySLL(stdout,i);
    displaySLL(stdout,j);
	printf("\n");

	printf("TEST #10\n");
    sll *k = newSLL(displayInteger);
    insertSLL(k,0,newInteger(86));
    insertSLL(k,0,newInteger(35));
    removeSLL(k,1);
    insertSLL(k,1,newInteger(27));
    insertSLL(k,0,newInteger(26));
    insertSLL(k,0,newInteger(36));
    removeSLL(k,1);
    insertSLL(k,3,newInteger(30));
    insertSLL(k,2,newInteger(35));
    removeSLL(k,3);
    insertSLL(k,1,newInteger(67));
    insertSLL(k,3,newInteger(42));
    removeSLL(k,5);
    insertSLL(k,2,newInteger(37));
    insertSLL(k,5,newInteger(70));
    insertSLL(k,1,newInteger(80));
    insertSLL(k,4,newInteger(70));
    removeSLL(k,0);
    insertSLL(k,8,newInteger(27));
    insertSLL(k,7,newInteger(29));
    removeSLL(k,5);
    removeSLL(k,0);
    insertSLL(k,5,newInteger(67));
    removeSLL(k,5);
    insertSLL(k,8,newInteger(8));
    insertSLL(k,1,newInteger(84));
    insertSLL(k,8,newInteger(99));
    insertSLL(k,4,newInteger(68));
    insertSLL(k,1,newInteger(86));
    removeSLL(k,7);
	printf("Your output:\n");
    displaySLL(stdout,k);
	printf("\n");

	printf("Expected output:\n");
	printf("[67,86,84,37,70,68,35,29,35,99,27,8]");
	printf("\n");

	printf("TEST #11\n");
    sll *l = newSLL(displayInteger);
    insertSLL(l,0,newInteger(83));
    insertSLL(l,0,newInteger(86));
    insertSLL(l,0,newInteger(77));
    insertSLL(l,0,newInteger(15));
    insertSLL(l,0,newInteger(93));
    insertSLL(l,0,newInteger(35));
    insertSLL(l,0,newInteger(86));
    printf("repeated 9993 times: insertSLL(l,0,newInteger(X))\n");
	for (count = 0; count < 9993; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		insertSLL(l,0,newInteger(random));
	}
    printf("repeated 10000 times: insertSLL(l,sizeSLL(l),newInteger(X))\n");
	for (count = 0; count < 10000; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		insertSLL(l,sizeSLL(l),newInteger(random));
	}
    printf("repeated 19993 times: removeSLL(l,0)\n");
	for (count = 0; count < 19993; count++) {
		removeSLL(l,0);
	}
    removeSLL(l,0);
    removeSLL(l,0);
    removeSLL(l,0);
    removeSLL(l,0);
    removeSLL(l,0);
    removeSLL(l,0);
    removeSLL(l,0);
	printf("Your output:\n");
    displaySLL(stdout,l);
	printf("\n");
	printf("Expected output:\n");
	printf("[]\n");
	printf("\n");

	printf("DOUBLE LINK TEST:\n");
	printf("TEST #12\n");
    DLL *m = newDLL(displayInteger);
    insertDLL(m,0,newInteger(83));
    insertDLL(m,0,newInteger(86));
    insertDLL(m,0,newInteger(77));
    insertDLL(m,0,newInteger(15));
    insertDLL(m,0,newInteger(93));
    insertDLL(m,0,newInteger(35));
    insertDLL(m,0,newInteger(86));
    insertDLL(m,0,newInteger(92));
    insertDLL(m,0,newInteger(49));
    insertDLL(m,0,newInteger(21));
	printf("Your output:\n");
    displayDLL(stdout,m);
	printf("\n");

	printf("Expected output:\n");
	printf("[21,49,92,86,35,93,15,77,86,83]\n");
	printf("\n");
	
	printf("Your output reversed:\n");
    displayDLLreverse(stdout,m);
	printf("\n");

	printf("TEST #13\n");
    DLL *n = newDLL(displayInteger);
    insertDLL(n,sizeDLL(n),newInteger(83));
    insertDLL(n,sizeDLL(n),newInteger(86));
    insertDLL(n,sizeDLL(n),newInteger(77));
    insertDLL(n,sizeDLL(n),newInteger(15));
    insertDLL(n,sizeDLL(n),newInteger(93));
    insertDLL(n,sizeDLL(n),newInteger(35));
    insertDLL(n,sizeDLL(n),newInteger(86));
    insertDLL(n,sizeDLL(n),newInteger(92));
    insertDLL(n,sizeDLL(n),newInteger(49));
    insertDLL(n,sizeDLL(n),newInteger(21));
	printf("Your output:\n");
    displayDLL(stdout,n);
	printf("\n");

	printf("Expected output:\n");
	printf("[83,86,77,15,93,35,86,92,49,21]\n");
	printf("\n");
	
	printf("Your output reversed:\n");
    displayDLLreverse(stdout,n);
	printf("\n");

	printf("TEST #14\n");
    DLL *o = newDLL(displayInteger);
    insertDLL(o,0,newInteger(83));
    insertDLL(o,1,newInteger(77));
    insertDLL(o,1,newInteger(93));
    insertDLL(o,0,newInteger(86));
    insertDLL(o,1,newInteger(49));
    insertDLL(o,1,newInteger(62));
    insertDLL(o,4,newInteger(90));
    insertDLL(o,6,newInteger(63));
    insertDLL(o,0,newInteger(40));
    insertDLL(o,6,newInteger(72));
    insertDLL(o,8,newInteger(11));
    insertDLL(o,9,newInteger(67));
    insertDLL(o,5,newInteger(82));
    insertDLL(o,13,newInteger(62));
    insertDLL(o,10,newInteger(67));
    insertDLL(o,10,newInteger(29));
    insertDLL(o,0,newInteger(22));
    insertDLL(o,3,newInteger(69));
    insertDLL(o,15,newInteger(93));
    insertDLL(o,2,newInteger(11));
    insertDLL(o,18,newInteger(29));
    insertDLL(o,1,newInteger(21));
    insertDLL(o,1,newInteger(84));
    insertDLL(o,20,newInteger(98));
    insertDLL(o,20,newInteger(15));
    insertDLL(o,24,newInteger(13));
    insertDLL(o,26,newInteger(91));
    insertDLL(o,9,newInteger(56));
    insertDLL(o,0,newInteger(62));
    insertDLL(o,1,newInteger(96));
    insertDLL(o,21,newInteger(5));
    insertDLL(o,7,newInteger(84));
    insertDLL(o,20,newInteger(36));
    insertDLL(o,5,newInteger(46));
    insertDLL(o,7,newInteger(13));
    insertDLL(o,27,newInteger(24));
    insertDLL(o,19,newInteger(82));
    insertDLL(o,13,newInteger(14));
    insertDLL(o,23,newInteger(34));
    insertDLL(o,30,newInteger(43));
	printf("Your output:\n");
    displayDLL(stdout,o);
	printf("\n");

	printf("Expected output:\n");
	printf("[62,96,22,84,21,46,40,13,11,84,86,69,62,14,49,56,83,82,90,72,82,93,11,34,29,36,67,67,5,93,43,24,63,15,98,29,77,13,62,91]");
	printf("\n");
	
	printf("Your output reversed:\n");
    displayDLLreverse(stdout,o);
	printf("\n");
	
	printf("TEST #15\n");
    DLL *p = newDLL(displayInteger);
    insertDLL(p,0,newInteger(86));
    insertDLL(p,1,newInteger(93));
    insertDLL(p,0,newInteger(92));
    insertDLL(p,3,newInteger(62));
    insertDLL(p,3,newInteger(59));
    insertDLL(p,0,newInteger(40));
    insertDLL(p,3,newInteger(36));
    insertDLL(p,5,newInteger(67));
    insertDLL(p,8,newInteger(30));
    insertDLL(p,5,newInteger(67));
    insertDLL(p,10,newInteger(2));
    removeDLL(p,7);
    removeDLL(p,3);
    insertDLL(p,2,newInteger(11));
    removeDLL(p,3);
    removeDLL(p,2);
    insertDLL(p,5,newInteger(37));
    insertDLL(p,0,newInteger(15));
    insertDLL(p,2,newInteger(26));
    insertDLL(p,9,newInteger(56));
    insertDLL(p,6,newInteger(70));
    insertDLL(p,13,newInteger(5));
    insertDLL(p,11,newInteger(27));
    insertDLL(p,1,newInteger(46));
    insertDLL(p,11,newInteger(57));
    removeDLL(p,14);
    removeDLL(p,14);
    removeDLL(p,14);
    insertDLL(p,5,newInteger(43));
    insertDLL(p,12,newInteger(8));
	printf("Your output:\n");
    displayDLL(stdout,p);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");
	
	printf("Your output reversed:\n");
    displayDLLreverse(stdout,p);
	printf("\n");

	printf("TEST #16\n");
    DLL *q = newDLL(displayInteger);
    insertDLL(q,0,newInteger(86));
    insertDLL(q,1,newInteger(93));
    insertDLL(q,0,newInteger(92));
    insertDLL(q,3,newInteger(62));
    insertDLL(q,3,newInteger(59));
    insertDLL(q,0,newInteger(40));
    insertDLL(q,3,newInteger(36));
    insertDLL(q,5,newInteger(67));
    insertDLL(q,8,newInteger(30));
    insertDLL(q,5,newInteger(67));
    insertDLL(q,10,newInteger(2));
    removeDLL(q,7);
    removeDLL(q,3);
    insertDLL(q,2,newInteger(11));
    removeDLL(q,3);
    removeDLL(q,2);
    insertDLL(q,5,newInteger(37));
    insertDLL(q,0,newInteger(15));
    insertDLL(q,2,newInteger(26));
    insertDLL(q,9,newInteger(56));
    insertDLL(q,6,newInteger(70));
    insertDLL(q,13,newInteger(5));
    insertDLL(q,11,newInteger(27));
    insertDLL(q,1,newInteger(46));
    insertDLL(q,11,newInteger(57));
    removeDLL(q,14);
    removeDLL(q,14);
    removeDLL(q,14);
    insertDLL(q,5,newInteger(43));
    insertDLL(q,12,newInteger(8));
	printf("Your output:\n");
    displayDLL(stdout,q);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");
	
	printf("Your output reversed:\n");
    displayDLLreverse(stdout,q);
	printf("\n");

	printf("TEST #17\n");
    DLL *r = newDLL(displayInteger);
    insertDLL(r,0,newInteger(86));
    insertDLL(r,1,newInteger(93));
    insertDLL(r,0,newInteger(92));
    insertDLL(r,3,newInteger(62));
    insertDLL(r,3,newInteger(59));
    insertDLL(r,0,newInteger(40));
    insertDLL(r,3,newInteger(36));
    insertDLL(r,5,newInteger(67));
    insertDLL(r,8,newInteger(30));
    insertDLL(r,5,newInteger(67));
    insertDLL(r,10,newInteger(2));
    removeDLL(r,7);
    removeDLL(r,3);
    insertDLL(r,2,newInteger(11));
    removeDLL(r,3);
    removeDLL(r,2);
    insertDLL(r,5,newInteger(37));
    insertDLL(r,0,newInteger(15));
    insertDLL(r,2,newInteger(26));
    insertDLL(r,9,newInteger(56));
    insertDLL(r,6,newInteger(70));
    insertDLL(r,13,newInteger(5));
    insertDLL(r,11,newInteger(27));
    insertDLL(r,1,newInteger(46));
    insertDLL(r,11,newInteger(57));
    removeDLL(r,14);
    removeDLL(r,14);
    removeDLL(r,14);
    insertDLL(r,5,newInteger(43));
    insertDLL(r,12,newInteger(8));
	printf("Your output:\n");
    displayDLL(stdout,r);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");
	
	printf("Your output reversed:\n");
    displayDLLreverse(stdout,r);
	printf("\n");

	printf("TEST #18\n");
    DLL *s = newDLL(displayInteger);
    insertDLL(s,0,newInteger(86));
    insertDLL(s,1,newInteger(93));
    insertDLL(s,0,newInteger(92));
    insertDLL(s,3,newInteger(62));
    insertDLL(s,3,newInteger(59));
    insertDLL(s,0,newInteger(40));
    insertDLL(s,3,newInteger(36));
    insertDLL(s,5,newInteger(67));
    insertDLL(s,8,newInteger(30));
    insertDLL(s,5,newInteger(67));
    insertDLL(s,10,newInteger(2));
    removeDLL(s,7);
    removeDLL(s,3);
    insertDLL(s,2,newInteger(11));
    removeDLL(s,3);
    removeDLL(s,2);
    insertDLL(s,5,newInteger(37));
    insertDLL(s,0,newInteger(15));
    insertDLL(s,2,newInteger(26));
    insertDLL(s,9,newInteger(56));
    insertDLL(s,6,newInteger(70));
    insertDLL(s,13,newInteger(5));
    insertDLL(s,11,newInteger(27));
    insertDLL(s,1,newInteger(46));
    insertDLL(s,11,newInteger(57));
    removeDLL(s,14);
    removeDLL(s,14);
    removeDLL(s,14);
    insertDLL(s,5,newInteger(43));
    insertDLL(s,12,newInteger(8));
	printf("Your output:\n");
    displayDLL(stdout,s);
	printf("\n");
	
	printf("Your output reversed:\n");
    displayDLLreverse(stdout,s);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");

	printf("TEST #19\n");
    DLL *t = newDLL(displayInteger);
    insertDLL(t,0,newInteger(86));
    insertDLL(t,1,newInteger(93));
    insertDLL(t,0,newInteger(92));
    insertDLL(t,3,newInteger(62));
    insertDLL(t,3,newInteger(59));
    insertDLL(t,0,newInteger(40));
    insertDLL(t,3,newInteger(36));
    insertDLL(t,5,newInteger(67));
    insertDLL(t,8,newInteger(30));
    insertDLL(t,5,newInteger(67));
    insertDLL(t,10,newInteger(2));
    removeDLL(t,7);
    removeDLL(t,3);
    insertDLL(t,2,newInteger(11));
    removeDLL(t,3);
    removeDLL(t,2);
    insertDLL(t,5,newInteger(37));
    insertDLL(t,0,newInteger(15));
    insertDLL(t,2,newInteger(26));
    insertDLL(t,9,newInteger(56));
    insertDLL(t,6,newInteger(70));
    insertDLL(t,13,newInteger(5));
    insertDLL(t,11,newInteger(27));
    insertDLL(t,1,newInteger(46));
    insertDLL(t,11,newInteger(57));
    removeDLL(t,14);
    removeDLL(t,14);
    removeDLL(t,14);
    insertDLL(t,5,newInteger(43));
    insertDLL(t,12,newInteger(8));
	printf("Your output:\n");
    displayDLL(stdout,t);
	printf("\n");

	printf("Expected output:\n");
	printf("[15,46,40,26,92,43,93,67,70,67,37,62,8,57,56,27]\n");
	printf("\n");
	
	printf("Your output reversed:\n");
    displayDLLreverse(stdout,t);
	printf("\n");

	printf("TEST #20\n");
    DLL *u = newDLL(displayInteger);
    DLL *v = newDLL(displayInteger);
    printf("(inserting 100 random integers into list a at random locations)\n");
    printf("(inserting 100 random integers into list b at random locations)\n");
    printf("(unioning list a and list b, 10000 times)\n");
	printf("Expected output:\n");
	//printf("[");
	for (count = 0; count < 100; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		//printf("%d,", random);
		insertDLL(u,0,newInteger(random));
	}
	for (count = 0; count < 100; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		//printf("%d,", random);
		insertDLL(v,0,newInteger(random));
	}
	displayDLL(stdout, u);
	displayDLL(stdout, v);
	printf("\n");
	//printf("]\n");
	for (count = 1; count < 10000; count++) {
		if ((count % 2) == 0) {
			unionDLL(v,u);
		} else {
			unionDLL(u,v);
		}
	}
	printf("Your output:\n");
    displayDLL(stdout,u);
    displayDLL(stdout,v);
	printf("\n");

//Expected output:
//[62,96,34,22,37,96,3,40,84,86,21,46,32,40,70,13,35,11,88,59,97,40,84,46,27,86,69,64,67,28,65,62,14,76,95,6,49,56,32,83,34,26,1,21,54,76,82,90,72,9,31,82,43,93,11,39,34,29,36,67,52,67,5,24,97,28,43,93,58,97,43,32,24,79,94,19,87,63,81,74,41,67,75,15,18,98,8,29,77,29,13,93,62,17,18,91,87,3,86,44,32,5,2,22,28,21,54,19,82,69,50,79,22,87,5,60,20,98,9,73,90,97,24,24,60,84,26,44,93,62,36,6,21,73,30,8,27,39,81,52,0,61,61,79,90,21,84,55,40,20,76,79,13,26,70,25,45,42,22,11,24,99,68,72,48,59,44,36,42,44,22,99,43,48,79,72,6,33,13,94,46,42,17,4,84,76,59,19,78,99,96,40,5,98,90,4,69,92,40,13][]

	printf("TEST #21\n");
    DLL *w = newDLL(displayInteger);
    insertDLL(w,0,newInteger(86));
    insertDLL(w,0,newInteger(35));
    removeDLL(w,1);
    insertDLL(w,1,newInteger(27));
    insertDLL(w,0,newInteger(26));
    insertDLL(w,0,newInteger(36));
    removeDLL(w,1);
    insertDLL(w,3,newInteger(30));
    insertDLL(w,2,newInteger(35));
    removeDLL(w,3);
    insertDLL(w,1,newInteger(67));
    insertDLL(w,3,newInteger(42));
    removeDLL(w,5);
    insertDLL(w,2,newInteger(37));
    insertDLL(w,5,newInteger(70));
    insertDLL(w,1,newInteger(80));
    insertDLL(w,4,newInteger(70));
    removeDLL(w,0);
    insertDLL(w,8,newInteger(27));
    insertDLL(w,7,newInteger(29));
    removeDLL(w,5);
    removeDLL(w,0);
    insertDLL(w,5,newInteger(67));
    removeDLL(w,5);
    insertDLL(w,8,newInteger(8));
    insertDLL(w,1,newInteger(84));
    insertDLL(w,8,newInteger(99));
    insertDLL(w,4,newInteger(68));
    insertDLL(w,1,newInteger(86));
    removeDLL(w,7);
	printf("Your output:\n");
    displayDLL(stdout,w);
	printf("\n");
	
	printf("Expected output:\n");
	printf("[67,86,84,37,70,68,35,29,35,99,27,8]\n");
	printf("\n");

	printf("TEST #22\n");
    DLL *x = newDLL(displayInteger);
    insertDLL(x,0,newInteger(83));
    insertDLL(x,0,newInteger(86));
    insertDLL(x,0,newInteger(77));
    insertDLL(x,0,newInteger(15));
    insertDLL(x,0,newInteger(93));
    insertDLL(x,0,newInteger(35));
    insertDLL(x,0,newInteger(86));
    printf("repeated 9993 times: insertDLL(x,0,newInteger(X))\n");
    printf("repeated 10000 times: insertDLL(x,sizeDLL(a),newInteger(X))\n");
    printf("repeated 19980 times: removeDLL(x,0)\n");
	for (count = 0; count < 9993; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		insertDLL(x,0,newInteger(random));
	}
	for (count = 0; count < 10000; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		insertDLL(x,sizeDLL(x),newInteger(random));
	}
	for (count = 0; count < 19980; count++) {
		removeDLL(x,0);
	}
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
    removeDLL(x,0);
	printf("Your output:\n");
    displayDLL(stdout,x);
	printf("\n");

	printf("Expected output:\n");
	printf("[]\n");
	printf("\n");

	printf("STACK TEST:\n");
	printf("TEST #23\n");
    stack *y = newStack(displayInteger);
    push(y,newInteger(83));
    push(y,newInteger(86));
    push(y,newInteger(77));
    push(y,newInteger(15));
    push(y,newInteger(93));
    push(y,newInteger(35));
    push(y,newInteger(86));
    push(y,newInteger(92));
    push(y,newInteger(49));
    push(y,newInteger(21));
	printf("Your output:\n");
    displayStack(stdout,y);
	printf("\n");

	printf("Expected output:\n");
	printf("[21,49,92,86,35,93,15,77,86,83]\n");
	printf("\n");

	printf("TEST #24\n");
    stack *z = newStack(displayInteger);
    push(z,newInteger(86));
    pop(z);
    push(z,newInteger(35));
    push(z,newInteger(92));
    pop(z);
    push(z,newInteger(27));
    push(z,newInteger(59));
    push(z,newInteger(26));
    pop(z);
    push(z,newInteger(36));
    push(z,newInteger(68));
    pop(z);
    push(z,newInteger(30));
    push(z,newInteger(23));
    push(z,newInteger(35));
    push(z,newInteger(2));
    pop(z);
    push(z,newInteger(67));
    push(z,newInteger(56));
    push(z,newInteger(42));
    pop(z);
    pop(z);
    push(z,newInteger(37));
    push(z,newInteger(24));
    push(z,newInteger(70));
    push(z,newInteger(26));
    push(z,newInteger(80));
    push(z,newInteger(73));
    push(z,newInteger(70));
    push(z,newInteger(81));
	printf("Your output:\n");
    displayStack(stdout,z);
	printf("\n");

	printf("Expected output:\n");
	printf("[81,70,73,80,26,70,24,37,67,35,23,30,36,59,27,35]\n");
	printf("\n");

	printf("TEST #25\n");
    stack *aa = newStack(displayInteger);
    push(aa,newInteger(86));
    pop(aa);
    push(aa,newInteger(35));
    push(aa,newInteger(92));
    pop(aa);
    push(aa,newInteger(27));
    push(aa,newInteger(59));
    push(aa,newInteger(26));
    pop(aa);
    push(aa,newInteger(36));
    push(aa,newInteger(68));
    pop(aa);
    push(aa,newInteger(30));
    push(aa,newInteger(23));
    push(aa,newInteger(35));
    push(aa,newInteger(2));
    pop(aa);
    push(aa,newInteger(67));
    push(aa,newInteger(56));
    push(aa,newInteger(42));
    pop(aa);
    pop(aa);
    push(aa,newInteger(37));
    push(aa,newInteger(24));
    push(aa,newInteger(70));
    push(aa,newInteger(26));
    push(aa,newInteger(80));
    push(aa,newInteger(73));
    push(aa,newInteger(70));
    push(aa,newInteger(81));
	printf("Your output:\n");
    displayStack(stdout,aa);
	printf("\n");
	
	printf("Expected output:\n");
	printf("[81,70,73,80,26,70,24,37,67,35,23,30,36,59,27,35]\n");
	printf("\n");

	printf("TEST #26\n");
    stack *ab = newStack(displayInteger);
    push(ab,newInteger(86));
    pop(ab);
    push(ab,newInteger(35));
    push(ab,newInteger(92));
    pop(ab);
    push(ab,newInteger(27));
    push(ab,newInteger(59));
    push(ab,newInteger(26));
    pop(ab);
    push(ab,newInteger(36));
    push(ab,newInteger(68));
    pop(ab);
    push(ab,newInteger(30));
    push(ab,newInteger(23));
    push(ab,newInteger(35));
    push(ab,newInteger(2));
    pop(ab);
    push(ab,newInteger(67));
    push(ab,newInteger(56));
    push(ab,newInteger(42));
    pop(ab);
    pop(ab);
    push(ab,newInteger(37));
    push(ab,newInteger(24));
    push(ab,newInteger(70));
    push(ab,newInteger(26));
    push(ab,newInteger(80));
    push(ab,newInteger(73));
    push(ab,newInteger(70));
    push(ab,newInteger(81));
	printf("Your output:\n");
    displayStack(stdout,ab);
	printf("\n");

	printf("Expected output:\n");
	printf("[81,70,73,80,26,70,24,37,67,35,23,30,36,59,27,35]\n");
	printf("\n");

	printf("TEST #27\n");
    stack *ac = newStack(displayInteger);
    push(ac,newInteger(86));
    pop(ac);
    push(ac,newInteger(35));
    push(ac,newInteger(92));
    pop(ac);
    push(ac,newInteger(27));
    push(ac,newInteger(59));
    push(ac,newInteger(26));
    pop(ac);
    push(ac,newInteger(36));
    push(ac,newInteger(68));
    pop(ac);
    push(ac,newInteger(30));
    push(ac,newInteger(23));
    push(ac,newInteger(35));
    push(ac,newInteger(2));
    pop(ac);
    push(ac,newInteger(67));
    push(ac,newInteger(56));
    push(ac,newInteger(42));
    pop(ac);
    pop(ac);
    push(ac,newInteger(37));
    push(ac,newInteger(24));
    push(ac,newInteger(70));
    push(ac,newInteger(26));
    push(ac,newInteger(80));
    push(ac,newInteger(73));
    push(ac,newInteger(70));
    push(ac,newInteger(81));
	printf("Your output:\n");
    displayStack(stdout,ac);
	printf("\n");

	printf("Expected output:\n");
	printf("[81,70,73,80,26,70,24,37,67,35,23,30,36,59,27,35]");
	printf("\n");

	printf("TEST #28\n");
    stack *ad = newStack(displayInteger);
    push(ad,newInteger(156));
    push(ad,newInteger(143));
    push(ad,newInteger(182));
    push(ad,newInteger(132));
    push(ad,newInteger(89));
    push(ad,newInteger(100));
    push(ad,newInteger(46));
    push(ad,newInteger(157));
    push(ad,newInteger(50));
    push(ad,newInteger(117));
    push(ad,newInteger(22));
    pop(ad);
    pop(ad);
    push(ad,newInteger(31));
    pop(ad);
    pop(ad);
    push(ad,newInteger(117));
    push(ad,newInteger(15));
    push(ad,newInteger(36));
    push(ad,newInteger(86));
    push(ad,newInteger(130));
    push(ad,newInteger(55));
    push(ad,newInteger(87));
    push(ad,newInteger(136));
    push(ad,newInteger(97));
    pop(ad);
    pop(ad);
    pop(ad);
    push(ad,newInteger(43));
    push(ad,newInteger(68));
	printf("Your output:\n");
    displayStack(stdout,ad);
	printf("\n");

	printf("Expected output:\n");
	printf("[68,43,55,130,86,36,15,117,157,46,100,89,132,182,143,156]\n");
	printf("\n");

	printf("TEST #29\n");
    stack *ae = newStack(displayInteger);
    printf("repeat 30000 times: push(ae,newInteger(X))\n");
	for (count = 0; count < 30000; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		push(ae, newInteger(random));
	}
	printf("Done 30000 pushes\n");
    printf("repeat 30000 times: pop(ae)\n");
	for (count = 0; count < 30000; count++) {
		pop(ae);
	}
	printf("Done 30000 pops\n");
	printf("Your output:\n");
    displayStack(stdout,ae);
	printf("\n");

	printf("Expected output:\n");
	printf("[]\n");
	printf("\n");

	printf("QUEUE TEST:\n");
	printf("TEST #30\n");
    queue *af = newQueue(displayInteger);
    enqueue(af,newInteger(83));
    enqueue(af,newInteger(86));
    enqueue(af,newInteger(77));
    enqueue(af,newInteger(15));
    enqueue(af,newInteger(93));
    enqueue(af,newInteger(35));
    enqueue(af,newInteger(86));
    enqueue(af,newInteger(92));
    enqueue(af,newInteger(49));
    enqueue(af,newInteger(21));
	printf("Your output:\n");
    displayQueue(stdout,af);
	printf("\n");

	printf("Expected output:\n");
	printf("[83,86,77,15,93,35,86,92,49,21]\n");
	printf("\n");

	printf("TEST #31\n");
    queue *ag = newQueue(displayInteger);
    enqueue(ag,newInteger(86));
    dequeue(ag);
    enqueue(ag,newInteger(35));
    enqueue(ag,newInteger(92));
    dequeue(ag);
    enqueue(ag,newInteger(27));
    enqueue(ag,newInteger(59));
    enqueue(ag,newInteger(26));
    dequeue(ag);
    enqueue(ag,newInteger(36));
    enqueue(ag,newInteger(68));
    dequeue(ag);
    enqueue(ag,newInteger(30));
    enqueue(ag,newInteger(23));
    enqueue(ag,newInteger(35));
    enqueue(ag,newInteger(2));
    dequeue(ag);
    enqueue(ag,newInteger(67));
    enqueue(ag,newInteger(56));
    enqueue(ag,newInteger(42));
    dequeue(ag);
    dequeue(ag);
    enqueue(ag,newInteger(37));
    enqueue(ag,newInteger(24));
    enqueue(ag,newInteger(70));
    enqueue(ag,newInteger(26));
    enqueue(ag,newInteger(80));
    enqueue(ag,newInteger(73));
    enqueue(ag,newInteger(70));
    enqueue(ag,newInteger(81));
	printf("Your output:\n");
    displayQueue(stdout,ag);
	printf("\n");

	printf("Expected output:\n");
	printf("[68,30,23,35,2,67,56,42,37,24,70,26,80,73,70,81]\n");
	printf("\n");

	printf("TEST #32\n");
    queue *ah = newQueue(displayInteger);
    enqueue(ah,newInteger(86));
    dequeue(ah);
    enqueue(ah,newInteger(35));
    enqueue(ah,newInteger(92));
    dequeue(ah);
    enqueue(ah,newInteger(27));
    enqueue(ah,newInteger(59));
    enqueue(ah,newInteger(26));
    dequeue(ah);
    enqueue(ah,newInteger(36));
    enqueue(ah,newInteger(68));
    dequeue(ah);
    enqueue(ah,newInteger(30));
    enqueue(ah,newInteger(23));
    enqueue(ah,newInteger(35));
    enqueue(ah,newInteger(2));
    dequeue(ah);
    enqueue(ah,newInteger(67));
    enqueue(ah,newInteger(56));
    enqueue(ah,newInteger(42));
    dequeue(ah);
    dequeue(ah);
    enqueue(ah,newInteger(37));
    enqueue(ah,newInteger(24));
    enqueue(ah,newInteger(70));
    enqueue(ah,newInteger(26));
    enqueue(ah,newInteger(80));
    enqueue(ah,newInteger(73));
    enqueue(ah,newInteger(70));
    enqueue(ah,newInteger(81));
	printf("Your output:\n");
    displayQueue(stdout,ah);
	printf("\n");

	printf("Expected output:\n");
	printf("[68,30,23,35,2,67,56,42,37,24,70,26,80,73,70,81]\n");
	printf("\n");

	printf("TEST #33\n");
    queue *ai = newQueue(displayInteger);
    enqueue(ai,newInteger(86));
    dequeue(ai);
    enqueue(ai,newInteger(35));
    enqueue(ai,newInteger(92));
    dequeue(ai);
    enqueue(ai,newInteger(27));
    enqueue(ai,newInteger(59));
    enqueue(ai,newInteger(26));
    dequeue(ai);
    enqueue(ai,newInteger(36));
    enqueue(ai,newInteger(68));
    dequeue(ai);
    enqueue(ai,newInteger(30));
    enqueue(ai,newInteger(23));
    enqueue(ai,newInteger(35));
    enqueue(ai,newInteger(2));
    dequeue(ai);
    enqueue(ai,newInteger(67));
    enqueue(ai,newInteger(56));
    enqueue(ai,newInteger(42));
    dequeue(ai);
    dequeue(ai);
    enqueue(ai,newInteger(37));
    enqueue(ai,newInteger(24));
    enqueue(ai,newInteger(70));
    enqueue(ai,newInteger(26));
    enqueue(ai,newInteger(80));
    enqueue(ai,newInteger(73));
    enqueue(ai,newInteger(70));
    enqueue(ai,newInteger(81));
	printf("Your output:\n");
    displayQueue(stdout,ai);
	printf("\n");

	printf("Expected output:\n");
	printf("[68,30,23,35,2,67,56,42,37,24,70,26,80,73,70,81]\n");
	printf("\n");

	printf("TEST #34\n");
    queue *aj = newQueue(displayInteger);
    enqueue(aj,newInteger(86));
    dequeue(aj);
    enqueue(aj,newInteger(35));
    enqueue(aj,newInteger(92));
    dequeue(aj);
    enqueue(aj,newInteger(27));
    enqueue(aj,newInteger(59));
    enqueue(aj,newInteger(26));
    dequeue(aj);
    enqueue(aj,newInteger(36));
    enqueue(aj,newInteger(68));
    dequeue(aj);
    enqueue(aj,newInteger(30));
    enqueue(aj,newInteger(23));
    enqueue(aj,newInteger(35));
    enqueue(aj,newInteger(2));
    dequeue(aj);
    enqueue(aj,newInteger(67));
    enqueue(aj,newInteger(56));
    enqueue(aj,newInteger(42));
    dequeue(aj);
    dequeue(aj);
    enqueue(aj,newInteger(37));
    enqueue(aj,newInteger(24));
    enqueue(aj,newInteger(70));
    enqueue(aj,newInteger(26));
    enqueue(aj,newInteger(80));
    enqueue(aj,newInteger(73));
    enqueue(aj,newInteger(70));
    enqueue(aj,newInteger(81));
	printf("Your output:\n");
    displayQueue(stdout,aj);
	printf("\n");

	printf("Expected output:\n");
	printf("[68,30,23,35,2,67,56,42,37,24,70,26,80,73,70,81]\n");
	printf("\n");

	printf("TEST #35\n");
    queue *ak = newQueue(displayInteger);
    enqueue(ak,newInteger(156));
    enqueue(ak,newInteger(143));
    enqueue(ak,newInteger(182));
    enqueue(ak,newInteger(132));
    enqueue(ak,newInteger(89));
    enqueue(ak,newInteger(100));
    enqueue(ak,newInteger(46));
    enqueue(ak,newInteger(157));
    enqueue(ak,newInteger(50));
    enqueue(ak,newInteger(117));
    enqueue(ak,newInteger(22));
    dequeue(ak);
    dequeue(ak);
    enqueue(ak,newInteger(31));
    dequeue(ak);
    dequeue(ak);
    enqueue(ak,newInteger(117));
    enqueue(ak,newInteger(15));
    enqueue(ak,newInteger(36));
    enqueue(ak,newInteger(86));
    enqueue(ak,newInteger(130));
    enqueue(ak,newInteger(55));
    enqueue(ak,newInteger(87));
    enqueue(ak,newInteger(136));
    enqueue(ak,newInteger(97));
    dequeue(ak);
    dequeue(ak);
    dequeue(ak);
    enqueue(ak,newInteger(43));
    enqueue(ak,newInteger(68));
	printf("Your output:\n");
    displayQueue(stdout,ak);
	printf("\n");

	printf("Expected output:\n");
	printf("[157,50,117,22,31,117,15,36,86,130,55,87,136,97,43,68]\n");
	printf("\n");

	printf("TEST #36\n");
    queue *ao = newQueue(displayInteger);
    printf("repeat 30000 times: enqueue(ao,newInteger(X))\n");
	for (count = 0; count < 30000; count++) {
		random = rand() % (100 + 1 - 1) + 1;
		enqueue(ao, newInteger(random));
	}
    printf("repeat 30000 times: dequeue(ao)\n");
	for (count = 0; count < 30000; count++) {
		dequeue(ao);
	}
	printf("Your output:\n");
    displayQueue(stdout,ao);
	printf("\n");

	printf("Expected output:\n");
	printf("[]\n");
	printf("\n");
	
	printf("TEST #37\n");
	DLL *bb = newDLL(displayInteger);
	insertDLL(bb, 0, newInteger(12));
	insertDLL(bb, 0, newInteger(24));
	insertDLL(bb, 0, newInteger(36));
	printf("Size: %d\n", sizeDLL(bb));
	printf("\n");
	displayDLL(stdout, bb);
	printf("\n");
	displayDLLreverse(stdout, bb);
	printf("\n");
	removeDLL(bb, 2);
	printf("Size: %d\n", sizeDLL(bb));
	printf("\n");
	displayDLL(stdout, bb);
	printf("\n");
	displayDLLreverse(stdout, bb);
	printf("\n");
	removeDLL(bb, 1);
	printf("Size: %d\n", sizeDLL(bb));
	printf("\n");
	displayDLL(stdout, bb);
	printf("\n");
	displayDLLreverse(stdout, bb);
	printf("\n");
	removeDLL(bb, 0);
	printf("Size: %d\n", sizeDLL(bb));
	printf("\n");
	displayDLL(stdout, bb);
	printf("\n");
	displayDLLreverse(stdout, bb);
	printf("\n");
	insertDLL(bb, sizeDLL(bb), newInteger(290));
	insertDLL(bb, sizeDLL(bb), newInteger(900));
	printf("Size: %d\n", sizeDLL(bb));
	printf("\n");
	displayDLL(stdout, bb);
	printf("\n");
	displayDLLreverse(stdout, bb);
	printf("\n");
	
	return 0;
}