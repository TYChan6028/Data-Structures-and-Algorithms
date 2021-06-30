CC=gcc

all: main

main: main.c max_heap.o
	$(CC) -o main main.c max_heap.o

max_heap.o: max_heap.h max_heap.c
	$(CC) -c max_heap.c

clean:
	rm main *.o
