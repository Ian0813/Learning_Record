CC=gcc
CFLAG= -g -fsanitize=address
OBJS=$(patsubst *.c, *.o, $(wildcard *.c))


.PHONY: all clean


all:clean
	$(CC) $(CFLAG) -o exe $(OBJS) 

clean:
	rm -rf exe $(wildcard *.o)

