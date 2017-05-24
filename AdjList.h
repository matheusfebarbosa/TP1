#include <stdio.h>
#include <stdlib.h>

typedef struct AdjCell *AdjCell;
typedef struct List AdjList;

struct AdjCell{
	int vertex;
	AdjCell next;
};

struct List{
	AdjCell first, last;
};

void makeEmptyAdjList(AdjList **list);
void insertVertex(AdjList *list, int v);
void killList(AdjList **list);