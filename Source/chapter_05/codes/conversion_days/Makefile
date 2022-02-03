CC=gcc
CFILES=$(patsubst %.c, %, $(shell find ./ -type f -name "*.c"))
CLIBS= -lm -lpthread
COPTIONS= -g -fsanitize=address
$(shell if [ ! -d "objs" ] ; then mkdir objs ; fi)
$(shell if [ ! -d "exe" ] ; then mkdir exe; fi)



.PHONY: all clean

all:$(CFILES)
	$(CC) $(COPTIONS) -o exe/$(notdir $(shell pwd)) objs/* $(CLIBS)



$(CFILES): %: %.c
	$(CC)  $(COPTIONS) -o objs/$@.o -c $< $(CLIBS)

clean:
	rm -rf exe objs
