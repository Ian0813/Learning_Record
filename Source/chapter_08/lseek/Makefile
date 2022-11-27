CC=gcc
CFLAGS= -g -fsanitize=address
CLIB= -lm -lpthread
EXE=$(notdir ${PWD})
$(file > text.txt,Hello world, my name is super man)

.PHONY: all clean

all:
	$(CC) $(CFLAGS) -o $(EXE) $(wildcard *.c) $(CLIB)

clean:
	rm -rf $(EXE) text.txt
