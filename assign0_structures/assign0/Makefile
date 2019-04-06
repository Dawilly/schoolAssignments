OBJS = da_test.o integer.o da.o
OPTS = -Wall -Wextra -g -std=c99

assign0 : $(OBJS)
	gcc $(OPTS) $(OBJS) -o assign0 -lm

da_test.o : da_test.c da.h integer.h
	gcc $(OPTS) -c da_test.c

da.o : da.c da.h
	gcc $(OPTS) -c da.c

integer.o : integer.c integer.h
	gcc $(OPTS) -c integer.c
	
clean :
	rm -f $(OBJS) assign0 

test :
	assign0