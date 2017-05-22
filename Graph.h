// Generic Graph Type
#define GRAY 1 
#define BLACK -1 
#define WHITE 0 

#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"
#include "VertexQueue.h"

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
void insertEdge(Graph *graph, int a, int b, int weight);
int BFS(Graph *map, int s, int *minRes, int t);
int maximumFlow(Graph *map);
/*void graphDestroy(Graph **graph);*/