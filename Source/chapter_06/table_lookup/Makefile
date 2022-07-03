CC=gcc
CFLAGS= -g -fsanitize=address
CLIBS= -lm -lpthread
CFILES=$(wildcard *.c)
EXE_NAME=$(shell basename `pwd`)

.PHONY: all clean

all: clean
	$(CC) $(CFLAGS) -o $(EXE_NAME) $(CFILES) $(CLIBS)

clean:
	rm -rf $(EXE_NAME)
