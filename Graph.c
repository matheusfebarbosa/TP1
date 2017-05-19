#include "Graph.h"

void makeEmptyGraph(Graph **graph, int nVertices){
	int i,j;
	*graph = (Graph*) calloc(1,sizeof(Graph));
	(*graph)->nVertices = nVertices;
	(*graph)->color = (int*) calloc(nVertices,sizeof(int));
	(*graph)->adjLists = (AdjList**) calloc(nVertices,sizeof(AdjList*));
	(*graph)->adjMatrix = (int**) calloc(nVertices,sizeof(int*));
	(*graph)->d = (int*) calloc(nVertices,sizeof(int));
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


int BFS(Graph *map, int s, int t){
	int i,cur;
	VertexQueue* queue;
	AdjCell adj = NULL;

	makeEmptyVertexQueue(&queue);

	for(i=0; i<map->nVertices;i++){
		map->d[i] = -1;
		map->color[i] =  WHITE;
	}

	enqueue(queue,s);

	while(!emptyQueue(queue)){
		dequeue(queue,&cur);
		adj = map->adjLists[cur]->first->next;
		while(adj!=NULL){
			if(map->color[adj->vertex]==WHITE && map->adjMatrix[cur][adj->vertex]>0){
				enqueue(queue,adj->vertex);
				map->d[adj->vertex]=cur;
				map->color[adj->vertex] = GRAY;	
			}
			if(adj->vertex == t){
				return 1;
			}
			adj =  adj->next;
		}
		map->color[cur]=BLACK;
	}

	return 0;
}


int maximumFlow(Graph *map){
	int minRes; 
	int sum = 0;
	int cur;
	int s = map->nVertices-2, t = map->nVertices-1;
	while(BFS(map, s, t)){
		minRes=12312312;
		cur = t; 
		while(map->d[cur]!=-1){
			if(map->adjMatrix[map->d[cur]][cur]<minRes){
				minRes = map->adjMatrix[map->d[cur]][cur];
			}
			cur = map->d[cur];
		}
		cur = t;
		while(map->d[cur]!=-1){
			map->adjMatrix[map->d[cur]][cur] -= minRes;
			map->adjMatrix[cur][map->d[cur]] += minRes;
			cur = map->d[cur];
		}
		sum += minRes;
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