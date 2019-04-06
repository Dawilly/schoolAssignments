#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

Graph* newGraph() {
	Graph* g = malloc(sizeof(Graph));
	if (g == 0) {
		fprintf(stderr, "newGraph: out of memory\n");
		exit(-1);
	}
	
	g->Vertices = newDArray(NULL); //May need to change.
	g->min = NULL;
	g->max = NULL;
	g->size_v = 0;
	g->size_e = 0;
	
	return g;
}

void addVertex(Graph* g, int value) {
	Vertex* newVertex = malloc(sizeof(Vertex));
	if (newVertex == 0) {
		fprintf(stderr, "newVertex: out of memory\n");
		exit(-1);
	}
	
	newVertex->value = value;
	newVertex->key = INT_MIN; //May need to change
	newVertex->steps = 0;
	newVertex->edges = newDArray(NULL); //May need to change
	newVertex->visited = 0;
	newVertex->parent = NULL;
	newVertex->bnode = NULL;
	insertDArray(g->Vertices, newVertex);
	
	g->size_v++;
	
	//Check to see if new min
	if (g->min == NULL) {
		g->min = newVertex;
	} else {
		if (g->min->value > newVertex->value) {
			g->min = newVertex;
		}
	}
	
	return;	
}

void addEdge(Graph* g, int src, int dest, int weight) {
	
	Vertex* node;
	Vertex* endpoint;
	Edge* existing = NULL;
	Edge* newEdge = malloc(sizeof(Edge));
	
	if (newEdge == 0) {
		fprintf(stderr, "addEdge: out of memory\n");
		exit(-1);
	}
	
	node = findVertex(g, src);
	endpoint = findVertex(g, dest);
	
	if (node == NULL || endpoint == NULL) {
		fprintf(stderr, "Error: addEdge. Vertex not found\n");
		exit(-1);
	}
	
	//Check to see if edge already exists. If it does, just update.
	
	existing = findEdge(node, dest);
	if (existing != NULL && existing->weight > weight) {
		existing->weight = weight;
		return;
	}
	
	newEdge->source = node;
	newEdge->destination = endpoint;
	newEdge->weight = weight;
	
	insertDArray(node->edges, newEdge);
	
	g->size_e++;
	
	return;
}

int vertexExist(Graph* g, int value) {
	int i;
	Vertex* working;
	
	for (i = 0; i < sizeDArray(g->Vertices); i++) {
		working = getDArray(g->Vertices, i);
		
		if (working == NULL) {
			continue;
		}
		
		if (working->value == value) {
			return 1;
		}
	}
	
	return 0;
}

Vertex* findVertex(Graph* g, int value) {
	int i;
	Vertex* working = NULL;
	
	for (i = 0; i < sizeDArray(g->Vertices); i++) {
		working = getDArray(g->Vertices, i);
		
		if (working == NULL) {
			continue;
		}
		
		if (working->value == value) {
			return working;
		}
	}
	
	return 0;
}

Edge* findEdge(Vertex* src, int dest) {
	int i;
	Edge* working;
	
	for (i = 0; i < sizeDArray(src->edges); i++) {
		working = getDArray(src->edges, i);
		if (working->destination->value == dest) {
			return working;
		}
	}
	
	return 0;
}

int compareVertex(void* v, void* w) {
	Vertex* a = (Vertex*) v;
	Vertex* b = (Vertex*) w;
	int x = a->key;
	int y = b->key;
	
	if (x == y) {
		x = a->value;
		y = b->value;
	}
	
	return x - y;
}

void displayVertex(FILE *fp, void *v) {
	Vertex* u = (Vertex*)v;
	if (u != NULL) {
		fprintf(fp, "%d", u->value);
	}
	if (u->parent != NULL) {
		fprintf(fp, "(");
		fprintf(fp,"%d", u->parent->value);
		fprintf(fp, ")");
		fprintf(fp,"%d", u->key);
	}
}

void updateVertex(void* v, BinomialNode *bn) {
	Vertex* u = (Vertex*) v;
	u->bnode = bn;
}