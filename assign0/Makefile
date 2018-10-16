OBJS = assign0.o integer.o sll.o dll.o stack.o queue.o
OPTS = -Wall -Wextra -g -std=c99

assign0 : $(OBJS)
	gcc $(OPTS) $(OBJS) -o assign0 -lm

assign0.o : assign0.c sll.h integer.h dll.h stack.h queue.h
	gcc $(OPTS) -c assign0.c

sll.o : sll.c sll.h
	gcc $(OPTS) -c sll.c
	
dll.o : dll.c dll.h
	gcc $(OPTS) -c dll.c
	
stack.o : stack.c stack.h dll.h
	gcc $(OPTS) -c stack.c
	
queue.o : queue.c queue.h sll.h
	gcc $(OPTS) -c queue.c

integer.o : integer.c integer.h
	gcc $(OPTS) -c integer.c
	
string.o : string.c string.h
	gcc $(OPTS) -c string.c
	
real.o : real.c real.h
	gcc $(OPTS) -c real.c

clean :
	rm -f $(OBJS) assign0 

test :
	assign0
