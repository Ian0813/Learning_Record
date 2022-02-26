CC:=gcc
#CFILES=$(patsubst %.c, %, $(shell find ./ -name "*.c"))
CFILES=$(patsubst ./%.c, %.c, $(shell find ./ -name "*.c"))
COPTIONS= -g -fsanitize=address
CLIBS:= -lm -lpthread
EXENAME=$(shell basename `pwd`)
$(shell if [ ! -d obj ]; then mkdir obj ; fi)
$(shell if [ ! -d exe ]; then mkdir exe ; fi)

.PHONY: all clean

all:
	$(CC) $(COPTIONS) -o exe/$(strip $(patsubst %.c, %, $(word 1, $(CFILES)))) $(word 1, $(CFILES))
	$(CC) $(COPTIONS) -o exe/$(strip $(patsubst %.c, %, $(word 2, $(CFILES)))) $(word 2, $(CFILES))


#$(CFILES): %: %.c
	#$(CC) -o obj/$@.o $(COPTIONS) $< $(CLIBS)


clean:
	rm -rf exe obj
