CC=gcc
CFLAGS= -g -fsanitize=address -Wall -Os
CLIBS= -lm -lpthread

.PHONY: all clean

all:
	$(CC) $(CFLAGS) -o $(notdir ${PWD}) $(wildcard *.c) $(CLIBS)

clean:
	@rm -rf $(notdir ${PWD})
