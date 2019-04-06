OBJS = dijkstra.o binomial.o darray.o integer.o scanner.o queue.o sll.o graph.o
OPTS = -Wall -Wextra -g -std=c99

dijkstra : $(OBJS)
	gcc $(OPTS) $(OBJS) -o dijkstra -lm

dijkstra.o : dijkstra.c darray.h integer.h scanner.h
	gcc $(OPTS) -c dijkstra.c
	
binomial.o : binomial.c binomial.h
	gcc $(OPTS) -c binomial.c binomial.h

darray.o : darray.c darray.h
	gcc $(OPTS) -c darray.c darray.h
	
integer.o : integer.c integer.h
	gcc $(OPTS) -c integer.c integer.h

scanner.o : scanner.c scanner.h
	gcc $(OPTS) -c scanner.c scanner.h
	
queue.o : queue.c queue.h sll.h
	gcc $(OPTS) -c queue.c queue.h
	
sll.o : sll.c sll.h
	gcc $(OPTS) -c sll.c sll.h
	
graph.o : graph.c graph.h
	gcc $(OPTS) -c graph.c graph.h

clean :
	rm -f $(OBJS) dijkstra 

test : 
	./dijkstra single.0 > myOutSingle.txt
	./dijkstra two.0 > myOutTwo.txt
	./dijkstra unweighted.0 > myOutUnweighted.txt
	./dijkstra g6.0 > myOutG6.txt
	./dijkstra g7.0 > myOutG7.txt
	./dijkstra g8.0 > myOutG8.txt
	./dijkstra g9.0 > myOutG9.txt
	./dijkstra g10.0 > myOutG10.txt
	./dijkstra g11.0 > myOutG11.txt
	./dijkstra g12.0 > myOutG12.txt
	./dijkstra g13.0 > myOutG13.txt
	./dijkstra g14.0 > myOutG14.txt
	./dijkstra g15.0 > myOutG15.txt
	diff outSingle.txt myOutSingle.txt
	diff outTwo.txt myOutTwo.txt
	diff outUnweighted.txt myOutUnweighted.txt
	diff outG6.txt myOutG6.txt
	diff outG7.txt myOutG7.txt
	diff outG8.txt myOutG8.txt
	diff outG9.txt myOutG9.txt
	diff outG10.txt myOutG10.txt
	diff outG11.txt myOutG11.txt
	diff outG12.txt myOutG12.txt
	diff outG13.txt myOutG13.txt
	diff outG14.txt myOutG14.txt
	diff outG15.txt myOutG15.txt
