CC=gcc
CFLAGS= -g -fsanitize=address -Wall
CLIBS= -lpthread -lm
COBJECTS=$(patsubst %.c, %, $(shell ls | grep -F .c))
EXE=$(notdir $(shell pwd))


.PHONY: all clean


all: clean $(COBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) *.o $(CLIBS)


$(COBJECTS): %: %.c
	$(CC) $(CFLAGS) -o $@.o  -c $< $(CLIBS)


clean:
	rm -rf $(EXE) *.o


