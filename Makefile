TP1: Graph.o AdjList.o VertexQueue.o main.o
	gcc Graph.o AdjList.o VertexQueue.o main.o -o TP1 -Wall -Wextra -Werror -std=c99 -pedantic
main.o: main.c Graph.h
	gcc -g -c main.c -Wall -Wextra -Werror -std=c99 -pedantic
Graph.o: Graph.c Graph.h AdjList.h VertexQueue.h
		gcc -g -c Graph.c -Wall -Wextra -Werror -std=c99 -pedantic
AdjList.o: AdjList.h AdjList.c
	    	gcc -g -c AdjList.c -Wall -Wextra -Werror -std=c99 -pedantic	
VertexQueue.o: VertexQueue.h VertexQueue.c
	    	gcc -g -c VertexQueue.c -Wall -Wextra -Werror -std=c99 -pedantic	
clean:
	$(RM) *.o TP1