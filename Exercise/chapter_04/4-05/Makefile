SHELL := /bin/bash
CC=gcc
HEADER_LOC=$(shell find ./ -name "*.h"|xargs dirname)
REFER_LOC=$(patsubst %, -I%, $(HEADER_LOC))
SOURCE=$(shell find ./ -name "*.c")
CFLAGS += $(REFER_LOC) -g -fsanitize=address
CFILE=$(patsubst %.c, %, $(SOURCE))
$(shell if [ ! -d exe ] ; then mkdir exe ;fi)
$(shell if [ ! -d objs ] ; then mkdir objs ;fi)


.PHONY: all clean

all:$(CFILE)
	$(CC) -o exe/calculator $(CFLAGS) objs/*.o -lm 	


$(CFILE): %: %.c
	$(CC) -o objs/$(shell basename $@).o $(CFLAGS) -c $<	


clean:
	rm $(wildcard objs/*.o exe/*) 
