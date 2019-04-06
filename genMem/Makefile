OBJS = genMem.o 
OPTS = -Wall -Wextra -g -std=c99

genMem : $(OBJS)
	gcc $(OPTS) $(OBJS) -o genMem -lm

genMem.o : genMem.c sll.h integer.h dll.h stack.h queue.h
	gcc $(OPTS) -c genMem.c

clean :
	rm -f $(OBJS) genMem 

test :
	assign0
