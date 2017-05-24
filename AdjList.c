#include "AdjList.h"

void makeEmptyAdjList(AdjList **list){
	(*list) = (AdjList*) calloc(1,sizeof(AdjList));
	(*list)->first = (AdjCell) calloc(1,sizeof(AdjCell));
	(*list)->first->next = NULL;
	(*list)->last = (*list)->first;
}

void insertVertex(AdjList *list, int v){
	list->last->next = (AdjCell) calloc(1,sizeof(struct AdjCell));
	list->last->next->vertex = v;
	list->last->next->next = NULL;
	list->last =  list->last->next;
}

void killList(AdjList **list){
	AdjCell aux = (*list)->first;
	while(aux!=NULL){
		(*list)->first = aux->next;
		free(aux);
		aux = (*list)->first;
	}
	free(*list);
}