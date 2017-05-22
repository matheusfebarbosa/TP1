#include "AdjList.h"

void makeEmptyAdjList(AdjList **list){
	(*list) = (AdjList*) calloc(1,sizeof(AdjList));
	(*list)->first = (AdjCell) calloc(1,sizeof(AdjList));
	(*list)->first->next = NULL;
	(*list)->last = (*list)->first;
}

void insertVertex(AdjList *list, int v){
	AdjCell aux = list->first;
	aux->vertex = v;
	list->first = (AdjCell) calloc(1,sizeof(struct AdjCell));
	list->first->next = aux;
}