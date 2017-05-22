// Generic Graph Type
#define GRAY 1 
#define BLACK -1 
#define WHITE 0 

#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"

//Type definition
typedef struct GraphType Graph;

struct GraphType{
	int **adjMatrix;
	AdjList **adjLists;
	int *color;
	int nVertices;
};

void makeEmptyGraph(Graph **graph, int nVertices);
void readGraph(Graph **map);
void insertEdge(Graph *graph, VertexValue a, VertexValue b, int weight);
/*int visitDFS(Graph *map, VertexValue s, int *minRes, VertexValue t);
int maximumFlow(Graph *map);
void graphDestroy(Graph **graph);*/