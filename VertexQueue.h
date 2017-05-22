#include <stdio.h>
#include <stdlib.h>

typedef struct QueueCell *QueueCell;
typedef struct Queue VertexQueue;

struct QueueCell{
	int vertex;
	QueueCell next;
};

struct Queue{
	QueueCell first, last;
};

void makeEmptyVertexQueue(VertexQueue **queue);
void enqueue(VertexQueue *queue, int v);
void dequeue(VertexQueue *queue, int *v);
int emptyQueue(VertexQueue *queue);