CC=gcc
CFLAGS= -g -fsanitize=address
CLIBS= -lm
CMAIN=5-16.c
CFILES=$(patsubst %.c, %, $(shell ls|grep -F .c ))
$(shell if [ ! -d obj ]; then mkdir obj ; fi )

.PHONY: all clean

all:$(CFILES)
	$(CC) $(CFLAGS) -o $(basename $(CMAIN)) obj/*.o $(CLIBS)

$(CFILES): %: %.c
	$(CC) $(CFLAGS) -c $< -o obj/$@.o

clean:
	rm -rf obj $(basename $(CMAIN))
