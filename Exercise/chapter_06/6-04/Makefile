CC=gcc
CFLAGS= -g -fsanitize=address -Wall
CLIBS= -lpthread -lm
COBJECTS=$(patsubst %.c, %, $(shell ls | grep -F .c))
EXE=$(notdir $(shell pwd))

.PHONY: all clean


all: clean $(COBJECTS) GENERATE_TAGS 
	$(CC) $(CFLAGS) -o $(EXE) *.o $(CLIBS)


$(COBJECTS): %: %.c
	$(CC) $(CFLAGS) -o $@.o  -c $< $(CLIBS)

GENERATE_TAGS:
	@ctags -R * 

clean:
	rm -rf $(EXE) *.o tags


