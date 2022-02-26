
SHELL := /bin/bash
CC=gcc
SOURCE=$(shell ls|grep -F .c)
CFLAGS += -g -fsanitize=address
CFILE=$(patsubst %.c, %, $(SOURCE))
$(shell if [ ! -d obj ] ; then mkdir obj ; fi)
$(shell if [ ! -d exe ] ; then mkdir exe ; fi)


.PHONY: all clean

all:clean $(CFILE)
	$(CC) -o exe/printd $(CFLAGS) obj/*.o 	


$(CFILE): %: %.c
	$(CC)  -o obj/$@.o $(CFLAGS) -c $<	


clean:
	@rm -rf *.o a.out $(wildcard obj/*.o) $(wildcard exe/*)  









