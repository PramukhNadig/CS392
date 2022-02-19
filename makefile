CC = gcc
CFLAGS = -c  -O2

all: mergesort.o
	gcc -c sort.c
	gcc -c mergesort.c
	gcc -o sort sort.o mergesort.o
	make clean

wow: wow.o
	gcc -c sort.c
	gcc -c mergesort.c
	gcc sort.o mergesort.o -o sort 

clean:
	rm *.o

