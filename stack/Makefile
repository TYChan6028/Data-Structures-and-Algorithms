CC=gcc

all: tests

tests: tests.c ../unity/unity.c stack.c stack.h
	$(CC) stack.c tests.c ../unity/unity.c -o main -I ../unity/

clean:
	rm stack *.o
