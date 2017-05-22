#include "VertexQueue.h"

void makeEmptyVertexQueue(VertexQueue **queue){
	(*queue) = (VertexQueue*) calloc(1,sizeof(VertexQueue));
	(*queue)->first = (QueueCell) calloc(1,sizeof(struct QueueCell));
	(*queue)->first->next = NULL;
	(*queue)->last = (*queue)->first;
}

void enqueue(VertexQueue *queue, int v){
	queue->last->next = (QueueCell) calloc(1,sizeof(struct QueueCell));
	queue->last->next->vertex = v;
	queue->last->next->next = NULL;
	queue->last =  queue->last->next;
}

void dequeue(VertexQueue *queue, int *v){
	QueueCell aux =  queue->first->next;
	*v = aux->vertex;
	queue->first->next = aux->next;
	if(aux==queue->last){
		queue->last = queue->first;
	}
	free(aux);
}

int emptyQueue(VertexQueue *queue){
	return queue->first == queue->last;
}