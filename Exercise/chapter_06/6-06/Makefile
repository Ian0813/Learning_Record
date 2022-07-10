CC=gcc
CFLAGS= -g -fsanitize=address
CLIBS= -lm -lpthread
COBJS=$(patsubst %.c, %.o, $(wildcard *.c))
EXE_NAME=$(shell basename `pwd`)

.PHONY: all clean

all: clean $(COBJS)
	$(CC) $(CFLAGS) -o $(EXE_NAME) $(wildcard *.o) $(CLIBS)

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $(basename $<).o -c $< $(CFLIBS) 

clean:
	rm -rf $(EXE_NAME) $(wildcard *.o)
