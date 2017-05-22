#include "Graph.h"

void makeEmptyGraph(Graph **graph, int nVertices){
	int i;
	*graph = (Graph*) calloc(1,sizeof(Graph));
	(*graph)->nVertices = nVertices;
	(*graph)->color = (int*) calloc(nVertices,sizeof(int));
	(*graph)->adjLists = (AdjList**) calloc(nVertices,sizeof(AdjList*));
	(*graph)->adjMatrix = (int**) calloc(nVertices,sizeof(int*));
	for(i=0;i<nVertices;i++){
		(*graph)->adjMatrix[i] = (int*) calloc(nVertices,sizeof(int));
		makeEmptyAdjList((*graph)->adjLists+i);
	}
}

void insertEdge(Graph *graph, VertexValue a, VertexValue b, int weight){
	graph->adjMatrix[a][b] = weight;
	graph->adjMatrix[a][b] = 0;
	insertVertex(graph->adjLists[a],b);
	insertVertex(graph->adjLists[b],a);
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
int visitDFS(Graph *map, VertexValue s, int *minRes, VertexValue t){
	 if(s==t){
    	return 1;
    }

 	int foi=0;
 	int back;
    map->color[s] = GRAY;
    EdgeCell next = map->adj[s]->first->next;
    printf("%d", next->edge.weight);
    while(next!=NULL){
        if(map->color[next->edge.destiny] == WHITE && next->edge.weight>0){
        	if(next->edge.weight<(*minRes)){
        		back = *minRes;
            	*minRes = next->edge.weight;
            }
            foi = visitDFS(map, next->edge.destiny, minRes, t);
            if(foi){
            	next->edge.weight -= *minRes;
            	next->edge.revert->edge.weight += *minRes;
            	map->color[s] = WHITE;
            	return 1;
            }
            *minRes = back;
        }
        next = next->next;
    }
    map->color[s] = BLACK;
    return 0;
}

int maximumFlow(Graph *map){
	int minRes=12312312; 
	int sum = 0;
	while(visitDFS(map,map->nVertices-2,&minRes,map->nVertices-1)){
		printf("Oi\n");
		sum += minRes;
		minRes=12312312;
	}
	
	return sum;;
}

void graphDestroy(Graph **graph){
	int i;

	free((*graph)->verticesType);
	free((*graph)->color);
	for(i=0;i<(*graph)->nVertices;i++){
		killList(&(*graph)->adj[i]);
	}
	free(*graph);
}*/