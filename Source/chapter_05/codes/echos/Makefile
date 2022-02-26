CC=gcc
CFILES=$(patsubst %.c, %, $(shell find ./ -name "*.c"))


.PHONY: all clean


all:clean $(CFILES)

$(CFILES): %: %.c
	$(CC) -o $(notdir $(basename $<)) $<


clean:
	rm -f echo1 echo2 
