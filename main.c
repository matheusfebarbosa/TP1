#include "Graph.h"

int main(){
	Graph *map;

	readGraph(&map);
	
	printf("%d\n",maximumFlow(map));

	graphDestroy(&map);

	return 0;
}