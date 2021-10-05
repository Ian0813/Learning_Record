
SHELL := /bin/bash
CC=gcc
SOURCE=$(shell ls|grep -F .c)
CFLAGS += -g -fsanitize=address
CFILE=$(patsubst %.c, %, $(SOURCE))


.PHONY: all clean

all:$(CFILE)
	$(CC) -o a.out $(CFLAGS) *.o 	


$(CFILE): %: %.c
	$(CC)  $(CFLAGS) -c $<	


clean:
	@rm *.o a.out









