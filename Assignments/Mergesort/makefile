CC = gcc
CFLAGS = -c  -O2

all: mergesort.o
	gcc -c sort.c
	gcc -c mergesort.c
	gcc -o sort sort.o mergesort.o
	make clean

clean:
	rm *.o

