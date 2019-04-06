#include <stdio.h>
#include "darray.h"
#include "binomial.h"

#ifndef __GRAPH_INCLUDED__
#define __GRAPH_INCLUDED__

typedef struct Vertex Vertex;

typedef struct Vertex {
	int value;
	int key;
	int steps;
	int visited;
	Vertex* parent;
	DArray* edges;
	BinomialNode* bnode;
} Vertex;

typedef struct Edge {
	Vertex* source;
	Vertex* destination;
	int weight;
} Edge;

typedef struct Graph {
	DArray* Vertices;
	Vertex* min;
	Vertex* max;
	int size_v;
	int size_e;
} Graph;

Graph* newGraph();
void addVertex(Graph*, int);
void addEdge(Graph*, int, int, int);
int vertexExist(Graph*, int);
Vertex* findVertex(Graph*, int);
Edge* findEdge(Vertex*, int);

int compareVertex(void*, void*);
void displayVertex(FILE*, void*);
void updateVertex(void*, BinomialNode*);

#endif