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

void insertEdge(Graph *graph, VertexValue a, VertexValue b, int weight){
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

int visitDFS(Graph *map, VertexValue s, int *minRes, VertexValue t){
	if(s==t){
    	return 1;
    }

 	int foi=0;
 	int back;
    map->color[s] = GRAY;
    AdjCell nextV = map->adjLists[s]->first->next;
    VertexValue v;
    while(nextV!=NULL){
        v = nextV->vertex;
        if(map->color[v] == WHITE && map->adjMatrix[s][v]>0){
        	if(map->adjMatrix[s][v]<(*minRes)){
        		back = *minRes;
            	*minRes = map->adjMatrix[s][v];
            }
            foi = visitDFS(map, v, minRes, t);
            if(foi){
            	map->adjMatrix[s][v] -= *minRes;
            	map->adjMatrix[v][s] += *minRes;
            	map->color[s] = WHITE;
            	return 1;
            }
            *minRes = back;
        }
        nextV = nextV->next;
    }
    map->color[s] = BLACK;
    return 0;
}


int maximumFlow(Graph *map){
	int minRes=12312312; 
	int sum = 0;
	while(visitDFS(map,map->nVertices-2,&minRes,map->nVertices-1)){
		sum += minRes;
		minRes=12312312;
	}
	
	return sum;
}

/*void graphDestroy(Graph **graph){
	int i;

	free((*graph)->verticesType);
	free((*graph)->color);
	for(i=0;i<(*graph)->nVertices;i++){
		killList(&(*graph)->adj[i]);
	}
	free(*graph);
}*/