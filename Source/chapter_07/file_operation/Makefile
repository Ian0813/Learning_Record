CC=gcc
CFLAGS= -g -fsanitize=address
CLIBS= -lm -lpthread
COBJS=$(patsubst %.c, %.o, $(wildcard *.c))
CEXE=$(filter test%, $(COBJS))


.PHONY: all clean

all: $(COBJS)
	$(CC) $(CFLAGS) -o $(basename $(CEXE)) $(COBJS) $(CLIBS) 

clean:
	rm -rf $(COBJS) $(basename $(CEXE))


