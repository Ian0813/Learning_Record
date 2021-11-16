
SHELL := /bin/bash
CC=gcc
SOURCE=$(shell ls|grep -F .c)
CFLAGS += -g -fsanitize=address
CFILE=$(patsubst %.c, %, $(SOURCE))
$(shell if [ ! -d exe ] ; then mkdir exe ; fi)
$(shell if [ ! -d obj ] ; then mkdir obj ; fi)
EXE_NAME=$(shell basename `pwd`)

.PHONY: all clean

all:$(CFILE)
	$(CC) -o exe/$(EXE_NAME) $(CFLAGS) obj/*.o 	


$(CFILE): %: %.c
	$(CC) -o obj/$@.o $(CFLAGS) -c $<	


clean:
	@rm -rf obj/*.o exe/* 









