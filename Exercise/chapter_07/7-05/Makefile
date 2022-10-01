CC=gcc
CLIBS= -lm -lpthread
CFLAGS= -g -fsanitize=address
CEXE=$(shell basename `pwd`)
COBJS=$(patsubst %.c, %.o, $(wildcard *.c))

.PHONY: all clean

all: $(COBJS)
	$(CC) $(CFLAGS) -o $(CEXE) $(COBJS) $(CLIBS)

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< $(CLIBS) 

clean:
	rm -rfv $(CEXE) $(wildcard *.o)
