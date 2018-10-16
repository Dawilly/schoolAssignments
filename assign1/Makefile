OBJS = sqsort.o integer.o sll.o dll.o stack.o queue.o real.o str.o scanner.o comparator.o
OPTS = -Wall -Wextra -g -std=c99

sqsort : $(OBJS)
	gcc $(OPTS) $(OBJS) -o sqsort -lm

sqsort.o : sqsort.c sll.h integer.h dll.h stack.h queue.h
	gcc $(OPTS) -c sqsort.c

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
	
str.o : str.c str.h
	gcc $(OPTS) -c str.c
	
real.o : real.c real.h
	gcc $(OPTS) -c real.c
	
scanner.o : scanner.c scanner.h
	gcc $(OPTS) -c scanner.c scanner.h
	
comparator.o : comparator.c comparator.h
	gcc $(OPTS) -c comparator.c comparator.h

clean :
	rm -f $(OBJS) sqsort 

test : ./sqsort 
	./sqsort -d test
	./sqsort -d test2
	./sqsort -r testReal
	./sqsort -r testReal3
	./sqsort -s testStr2
	./sqsort -s testStr3
	echo running sqsort on random integers with no repeats
	./sqsort -d testInteger1.txt
	echo running sqsort on random integers with repeats
	./sqsort -d testInteger2.txt
	echo running sqsort on homogenized integer list with two non-homogeneous embedded sequential integer
	./sqsort -d testInteger3.txt
	echo running sqsort on homogenized integer list
	./sqsort -d testInteger4.txt
	echo running sqsort on reals with no repeats
	./sqsort -r testReal1.txt
	echo running sqsort on reals with repeats
	./sqsort -r testReal2.txt
	echo running sqsort on strings with no repeats
	./sqsort -s testString1.txt
	echo running sqsort on strings with repeats
	./sqsort -s testString2.txt
	echo running sqsort on integer ex 1 from assigment instructions
	./sqsort -d t-int1.txt
	echo running sqsort on integer ex 2 from ass instructions
	./sqsort -d t-int2.txt
	echo running sqsort on random integers some reapeats
	./sqsort -d t-int3.txt
	echo running sqsort on all but one integer the same
	./sqsort -d t-int4.txt
	echo running sqsort on mostly the same integers
	./sqsort -d t-int5.txt
	echo running sqsort on real ex
	./sqsort -r t-real1.txt
	echo running sqsort on real all similar
	./sqsort -r t-real2.txt
	echo running sqsort on real all but 1 similar
	./sqsort -r t-real3.txt
	echo running sqsort on string ex
	./sqsort -s t-str1.txt
	echo running sqsort on string similar
	./sqsort -s t-str2.txt
	echo running sqsort on string all but 1 similar
	./sqsort -s t-str3.txt
	
