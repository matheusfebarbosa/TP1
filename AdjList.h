#include <stdio.h>
#include <stdlib.h>

typedef int VertexValue;
typedef struct Cell *AdjCell;
typedef struct List AdjList;

struct Cell{
	VertexValue vertex;
	AdjCell next;
};

struct List{
	AdjCell first, last;
};

void makeEmptyAdjList(AdjList **list);
void insertVertex(AdjList *list, VertexValue v);