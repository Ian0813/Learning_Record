
SHELL := /bin/bash
CC=gcc
LIB += -lm -lpthread 
FLAG += -g -fsanitize=address
SOURCES += $(shell ls|grep -F .c) 
CFILES += $(patsubst %.c, %, $(SOURCES))
$(shell if [ ! -d exe ] ; then mkdir exe ; fi)


.PHONY: all clean

all:$(CFILES)

$(CFILES): %: %.c 
	$(CC) -o exe/$@ $(FLAG) $< $(LIB) 


clean:
	rm -f $(wildcard exe/*)

