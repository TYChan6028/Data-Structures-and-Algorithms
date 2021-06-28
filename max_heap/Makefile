main: main.c max_heap.o
	gcc -o main main.c max_heap.o

max_heap.o: max_heap.h max_heap.c
	gcc -c max_heap.c

clean:
	rm main *.o
