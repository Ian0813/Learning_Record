CC:=gcc
CFILES=$(patsubst %.c, %, $(shell ls|grep -F .c))
COPTIONS= -g -fsanitize=address
CLIBS= -lm -lpthread
$(shell if [ ! -d obj ]; then mkdir obj ; fi)
$(shell if [ ! -d exe ]; then mkdir exe ; fi)


.PHONY: all clean

all:$(CFILES)
	$(CC) $(COPTIONS) -o exe/$< obj/*.o $(CLIBS)

$(CFILES): %: %.c
	$(CC) -o obj/$@.o $(COPTIONS)  -c $< $(CLIBS)


clean:
	rm -rf exe obj
