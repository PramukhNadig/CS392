CC = gcc
CFLAGS = -c -O3 -Werror -Wall -pedantic

all: pfind.o
	${CC} $(CFLAGS) -o pfind.out pfind.c
	rm *.o

clean:
	rm *.o
	rm *.out

