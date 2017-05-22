TP1: Graph.o AdjList.o main.o
	gcc Graph.o AdjList.o main.o -o TP1 -Wall -Wextra -Werror -std=c99 -pedantic
main.o: main.c Graph.h
	gcc -g -c main.c -Wall -Wextra -Werror -std=c99 -pedantic
Graph.o: Graph.c Graph.h AdjList.h 
		gcc -g -c Graph.c -Wall -Wextra -Werror -std=c99 -pedantic
AdjList.o: AdjList.h AdjList.c
	    	gcc -g -c AdjList.c -Wall -Wextra -Werror -std=c99 -pedantic		
clean:
	$(RM) *.o TP1