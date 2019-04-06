OBJS = bstrees.o bst.o str.o scanner.o vbst.o rbt.o queue.o sll.o avl.o
OPTS = -Wall -Wextra -g -std=c99

bstrees : $(OBJS)
	gcc $(OPTS) $(OBJS) -o bstrees -lm

bstrees.o : bstrees.c str.h bst.h rbt.h vbst.h scanner.h
	gcc $(OPTS) -c bstrees.c

bst.o : bst.c bst.h str.h
	@gcc $(OPTS) -c bst.c bst.h
	
vbst.o : vbst.c vbst.h str.h
	@gcc $(OPTS) -c vbst.c vbst.h
	
rbt.o : rbt.c rbt.h str.h
	@gcc $(OPTS) -c rbt.c rbt.h
	
avl.o : avl.c avl.h
	gcc $(OPTS) -c avl.c avl.h

str.o : str.c str.h
	gcc $(OPTS) -c str.c str.h
	
queue.o : queue.c queue.h sll.h
	gcc $(OPTS) -c queue.c queue.h
	
sll.o : sll.c sll.h
	gcc $(OPTS) -c sll.c sll.h

scanner.o : scanner.c scanner.h
	gcc $(OPTS) -c scanner.c scanner.h

clean :
	rm -f $(OBJS) bstrees 

test :
	./bstrees -v corpus commands
	./bstrees -r corpus commands
 
