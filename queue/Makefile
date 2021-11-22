INCLUDE_DIRS = ../unity/ unity/
VPATH = $(INCLUDE_DIRS)

CC = gcc
CFLAGS += $(addprefix -I , $(INCLUDE_DIRS))

all: tests

tests: tests.c queue.o unity.o
	$(CC) $(CFLAGS) $^ -o $@

queue.o: queue.c queue.h
	$(CC) -c $<

unity.o: unity.c unity.h unity_internals.h 
	$(CC) -c $<

clean:
	rm tests *.o
