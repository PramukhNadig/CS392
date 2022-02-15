CC = gcc
CFLAGS = -c -Werror -pedantic -Wextra -O2

debug: DEBUG = -DDEBUG


all: mergesort.o
	$(CC) $(DEBUG) mergesort.o -o a.out
	./a.out
	make clean


mergesort.o: mergesort.c
	$(CC) mergesort.c $(CFLAGS)

test: test.o
	gcc -Wall -c test.c
	gcc -Wall -c mergesort.c
	gcc -o a.out test.o mergesort.o
	./a.out
	make clean

clean:
	rm *.o
	rm *.out

