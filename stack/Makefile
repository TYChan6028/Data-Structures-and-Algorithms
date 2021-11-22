INCLUDE_DIRS = ../unity/ unity/
VPATH = $(INCLUDE_DIRS)

CC = gcc
CFLAGS += $(addprefix -I , $(INCLUDE_DIRS))

all: tests

tests: tests.c stack.o unity.o
	$(CC) $(CFLAGS) $^ -o $@

stack.o: stack.c stack.h
	$(CC) -c $<

unity.o: unity.c unity.h unity_internals.h 
	$(CC) -c $<

clean:
	rm tests *.o
