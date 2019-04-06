#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"
#include "scanner.h"
#include "darray.h"
#include "binomial.h"
#include "integer.h"
#include "string.h"
#include "graph.h"

//int vertexExists(Graph*, int);
static void dijkstra(Graph*, Vertex*);
static void displayDijkstra(FILE*, DArray*, int);

int main(int argc, char** argv) {
	
	FILE *in;
	char* str;
	int vertex_one;
	int vertex_two;
	int weight;
	int part = 0;
	//int max = INT_MIN;
	//int min = INT_MAX;
	Graph *g = newGraph(); //Will need to update!
	//Vertex *v = NULL;
	
	if (argc < 2) {
		fprintf(stderr, "Insufficient input\n");
		fprintf(stderr, "Syntax: dijkstra input_file\n");
		exit(-1);
	}
	
	in = fopen(argv[1], "r");
	if (!in) {
		fprintf(stderr, "Unable to open file: %s\n", argv[1]);
		exit(-1);
	}
	
	//Read shit in.
	while(!feof(in)) {
		
		str = readToken(in);
		//printf("Read in: %s\n", str);
		
		if (feof(in)) {
			//printf("End of file, ending\n");
			continue;
		}
		
		if (part == 0) {
			vertex_one = atoi(str);
			part++;
		} else if (part == 1) {
			vertex_two = atoi(str);
			part++;
		} else if (part == 2) {
			if (strcmp(str, ";") == 0) {
				weight = 1;
				part = 0;
			} else {
				weight = atoi(str);
				part++;
			}
			
			//If the edge is connecting the vertex to itself, skip
			if (vertex_one == vertex_two) {
				continue;
			}
			
			//Check if vertices exist or not.
			if (vertexExist(g, vertex_one) == 0) {
				addVertex(g, vertex_one);
			}
			
			if (vertexExist(g, vertex_two) == 0) {
				addVertex(g, vertex_two);
			}
			
			//Add the edge, you edgelord. Undirected graph so make it both ways.
			addEdge(g, vertex_one, vertex_two, weight);
			addEdge(g, vertex_two, vertex_one, weight);
			
		} else {
			if (strcmp(str, ";") == 0) {
				part = 0;
			}
		}
	}
	
	fclose(in);
	
	dijkstra(g, g->min);
	
	return 0;
}

static void dijkstra(Graph *g, Vertex *root) {

	//Variables we'll need
	int i;
	int j;
	int maxstep = 0;
	int first = 1;
	Vertex* working;
	Vertex* u;
	Vertex* v;
	Edge* e;
	BinomialNode* adding;

	//Read through file and find max vertex value "max"
	//Create array of that size max plus 1
	//Read in data from file and store in adj list array (find the min vertex value during process)
	//Use the minimum as the root vertex
	//Create a queue to hold visited vertices
	//queue* visited = newQueue(displayVertex);
	DArray* visited = newDArray(displayVertex);

	//Dijkstra's Algorithm

	//Set the root's key to 0
	root->key = 0;

	//Add all vertices to a new binomial heap
	Binomial* VertexHeap = newBinomial(displayVertex, compareVertex, updateVertex);
	for (i = 0; i < sizeDArray(g->Vertices); i++) {
		working = getDArray(g->Vertices, i);
		if (working == root) {
			continue;
		}
		adding = insertBinomial(VertexHeap, working);
		working->bnode = adding;
	}

	//while (the heap is not empty)
	while(sizeBinomial(VertexHeap) != 0) {
		//Extract from heap vertex u
		
		if (first == 1) {
			u = root;
			first = 0;
		} else {
			u = extractBinomial(VertexHeap);
		}
		//if (u has no predecessor) //Checking for disjoint vertex
		if (u->parent == NULL) {
			//Set u's key to 0
			u->key = 0;
			//Display the visited vertices queue if there's stuff in it
			displayDijkstra(stdout, visited, maxstep);
			//Clear visited vertices queue (or maybe this already happens when you display I guess)
			while (sizeDArray(visited) > 0) {
				removeDArray(visited);
			}
			maxstep = 0;
		}
			
		//Add vertex u to visited vertices queue
		insertDArray(visited, u);
		//Mark u as visited
		u->visited = 1;
		//for (each vertex adjacent with u)
		for (j = 0; j < sizeDArray(u->edges); j++) {
			//Let v be the vertex adjacent with u
			e = getDArray(u->edges, j);
			v = e->destination;
			//if (v has not been visited)
			if (v->visited == 0) {
				//if (v does not have a parent or u.key + e.weight < v.key)
				if ((v->parent == NULL) || ((u->key + e->weight) < v->key)) {
					//Set v's parent to u
					v->parent = u;
					//Update v's key to the new lower distance
					v->key = u->key + e->weight;
					//Update the number of steps for v to be its parent's + 1
					v->steps = u->steps + 1;
					if (v->steps > maxstep) {
						maxstep = v->steps;
					}
					//Call decreaseKey on v's binomial node pointer "position"
					decreaseKeyBinomial(VertexHeap,v->bnode,v);
				}
			}
		}
	}
	//Display the visited vertices queue (guaranteed to have stuff in it)
	displayDijkstra(stdout, visited, maxstep);
}

static void displayDijkstra(FILE* fp, DArray* a, int maxstep) {
	
	if (sizeDArray(a) == 0) {
		return;
	}
	
	int i;
	Binomial* working = newBinomial(displayVertex, compareVertex, NULL);
	queue **lv = malloc(sizeof(queue) * (maxstep+1));
	if (lv == 0) {
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
	
	for (i = 0; i < sizeDArray(a); i++) {
		insertBinomial(working, getDArray(a, i));
	}
	
	for (i = 0; i <= maxstep; i++) {
		lv[i] = newQueue(displayVertex);
	}
	
	while (sizeBinomial(working) > 0) {
		Vertex* v = extractBinomial(working);
		if (v != NULL) {
			enqueue(lv[v->steps], v);
		}
	}
	
	for (i = 0; i <= maxstep; i++) {
		fprintf(fp, "%d :", i);
		while(sizeQueue(lv[i]) != 0) {
			fprintf(fp, " ");
			displayVertex(fp, dequeue(lv[i]));
		}
		fprintf(fp, "\n");
	}
	
	fprintf(fp, "----\n");
	
	/*
	Vertex* working = NULL;
	//int steps = 0;
	int i;
	int j;
	
	if (sizeDArray(a) == 0) {
		fprintf(fp, "0 :");
		fprintf(fp, "\n----\n");
		return;
	}
	
		
	for (i = 0; i <= maxstep; i++) {
		fprintf(fp, "%d :", i);
		for (j = 0; j < sizeDArray(a); j++) {
			working = getDArray(a, j);
			if (working->steps == i) {
				fprintf(fp, " ");
				displayVertex(fp, working);
			}
		}
		fprintf(fp, "\n");

	}
	fprintf(fp, "----\n");
	*/
	return;
}