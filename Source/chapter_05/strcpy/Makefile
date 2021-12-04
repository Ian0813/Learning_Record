CC:=gcc
CFILES=$(patsubst %.c, %, $(shell find ./ -name "*.c"))
COPTIONS= -g -fsanitize=address
CLIBS= -lm -lpthread
EXENAME=$(shell basename `pwd`)
$(shell if [ ! -d obj ]; then mkdir obj ; fi)
$(shell if [ ! -d exe ]; then mkdir exe ; fi)



.PHONY: all clean

all:$(CFILES)
	$(CC) $(COPTIONS) -o exe/$(EXENAME) obj/*.o $(CLIBS)

$(CFILES): %: %.c
	$(CC) -o obj/$@.o $(COPTIONS)  -c $< $(CLIBS)


clean:
	rm -rf exe obj
