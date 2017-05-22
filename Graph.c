#include "Graph.h"

void makeEmptyGraph(Graph **graph, int nVertices){
	int i,j;
	*graph = (Graph*) calloc(1,sizeof(Graph));
	(*graph)->nVertices = nVertices;
	(*graph)->color = (int*) calloc(nVertices,sizeof(int));
	(*graph)->adjLists = (AdjList**) calloc(nVertices,sizeof(AdjList*));
	(*graph)->adjMatrix = (int**) calloc(nVertices,sizeof(int*));
	for(i=0;i<nVertices;i++){
		(*graph)->adjMatrix[i] = (int*) calloc(nVertices,sizeof(int));
		for(j=0;j<nVertices;j++){
			(*graph)->adjMatrix[i][j] = -1;
		}
		makeEmptyAdjList((*graph)->adjLists+i);
	}
}

void insertEdge(Graph *graph, int a, int b, int weight){
	if(graph->adjMatrix[a][b] == -1){
		insertVertex(graph->adjLists[a],b);	
	}
	graph->adjMatrix[a][b] = weight;
	
	if(graph->adjMatrix[b][a] == -1){
		graph->adjMatrix[b][a] = 0;
		insertVertex(graph->adjLists[b],a);
	}
}


void readGraph(Graph **map){
	int v,e,f,c,i,w,va,vb;
	scanf("%d %d %d %d",&v,&e,&f,&c);

	makeEmptyGraph(map,v+2);

	for(i=0; i<e; i++){
		scanf("%d %d %d",&va,&vb,&w);
		insertEdge(*map,va,vb,w);
	}
	va = (*map)->nVertices-2;
	for(i=0; i<f; i++){
		scanf("%d",&vb);
		insertEdge(*map,va,vb,1232131);
	}
	vb = (*map)->nVertices-1;
	for(i=0; i<c; i++){
		scanf("%d",&va);
		insertEdge(*map,va,vb,1232131);
	}
}

/*
int BFS(Graph *map, int s, int *minRes, int t){

}


int maximumFlow(Graph *map){
	int minRes=12312312; 
	int sum = 0;
	while(BFS(map,map->nVertices-2,&minRes,map->nVertices-1)){
		sum += minRes;
		minRes=12312312;
	}
	
	return sum;
}*/

/*void graphDestroy(Graph **graph){
	int i;

	free((*graph)->verticesType);
	free((*graph)->color);
	for(i=0;i<(*graph)->nVertices;i++){
		killList(&(*graph)->adj[i]);
	}
	free(*graph);
}*/