OBJS = genMem.o 
OPTS = -Wall -Wextra -g -std=c99

genMem : $(OBJS)
	gcc $(OPTS) $(OBJS) -o genMem -lm

genMem.o : genMem.c 
	gcc $(OPTS) -c genMem.c

clean :
	rm -f $(OBJS) genMem 

test :
	assign0
