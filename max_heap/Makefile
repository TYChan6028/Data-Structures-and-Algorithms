main: main.c heap.o
	gcc -o main main.c heap.o

heap.o: heap.h heap.c
	gcc -c heap.c

clean:
	rm main *.o
