CC=gcc
CFLAGS= -g -fsanitize=address
CLIBS= -lm -lpthread
CFILES=$(wildcard *.c)
COBJS=$(patsubst %.c, %.o, $(CFILES))

.PHONY: all clean


all: $(COBJS)


$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(CLIBS)


clean:
	rm $(basename $(wildcard *.o))





