DATA_STRUCTURE = queue
INCLUDE_DIRS = ../unity/ unity/
VPATH = $(INCLUDE_DIRS)

CC = gcc
CFLAGS += $(addprefix -I , $(INCLUDE_DIRS))

all: tests

tests: tests.c $(DATA_STRUCTURE).o unity.o
	$(CC) $(CFLAGS) $^ -o $@

$(DATA_STRUCTURE).o: $(DATA_STRUCTURE).c $(DATA_STRUCTURE).h
	$(CC) -c $<

unity.o: unity.c unity.h unity_internals.h 
	$(CC) -c $<

clean:
	rm tests *.o
