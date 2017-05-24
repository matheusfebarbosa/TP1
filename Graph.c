#include "Graph.h"

void makeEmptyGraph(Graph **graph, int nVertices){
	int i,j;
	*graph = (Graph*) calloc(1,sizeof(Graph));
	(*graph)->nVertices = nVertices;
	(*graph)->adjMatrix = (int**) calloc(nVertices,sizeof(int*));
	(*graph)->d = (int*) calloc(nVertices,sizeof(int));
	for(i=0;i<nVertices;i++){
		(*graph)->adjMatrix[i] = (int*) calloc(nVertices,sizeof(int));
		for(j=0;j<nVertices;j++){
			(*graph)->adjMatrix[i][j] = -1;
		}
	}
}

void insertEdge(Graph *graph, int a, int b, int weight){
	graph->adjMatrix[a][b] = weight;
	
	if(graph->adjMatrix[b][a] == -1){
		graph->adjMatrix[b][a] = 0;
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


int BFS(Graph *map, int s, int t, int *min){
	int i,cur;
	VertexQueue* queue;

	makeEmptyVertexQueue(&queue);

	for(i=0; i<map->nVertices;i++){
		map->d[i] = -1;
	}

	enqueue(queue,s);
	min[s]=-1;
	map->d[s]=-2;

	while(!emptyQueue(queue)){
		dequeue(queue,&cur);

		for(i=0;i<map->nVertices;i++){
			if(map->d[i]==-1 && map->adjMatrix[cur][i]>0){
				if(min[cur]!=-1 && min[cur]<map->adjMatrix[cur][i]){
					min[i]=min[cur];
				}else{
					min[i]=map->adjMatrix[cur][i];
				}
				enqueue(queue,i);
				map->d[i]=cur;
			}
			if(map->d[t]!=-1){
				return min[t];
			}
		}
		
	}

	return 0;
}


int maximumFlow(Graph *map){
	int minRes; 
	int sum = 0;
	int cur;
	int s = map->nVertices-2, t = map->nVertices-1;
	int *min =  (int*) calloc(map->nVertices,sizeof(int));
	while(1){
		minRes=BFS(map, s, t, min);

		if(minRes==0)
			break;

		cur = t;
		while(cur!=s){
			map->adjMatrix[map->d[cur]][cur] -= minRes;
			map->adjMatrix[cur][map->d[cur]] += minRes;
			cur = map->d[cur];
		}
		sum += minRes;
	}
	return sum;
}

void graphDestroy(Graph **graph){
	int i;

	free((*graph)->d);

	for(i=0;i<(*graph)->nVertices;i++){
		//killList(&(*graph)->adjLists[i]);
		free((*graph)->adjMatrix[i]);
	}
	//free((*graph)->adjLists);
	free((*graph)->adjMatrix);
	free(*graph);
}