CC = gcc

all: test.o

	gcc test.c -o main.o -c
	gcc std392io.c -o module.o -c
	gcc -o a.out main.o module.o
	rm *.o

check: checker.o

	gcc checker.c -o main.o -c
	gcc std392io.c -o module.o -c
	gcc -o a.out main.o module.o
	rm *.o
	./a.out


clean:
	rm *.out
	rm *.o

