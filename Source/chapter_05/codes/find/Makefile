CC=gcc
SOURCES=$(patsubst %.c, %, $(shell ls| grep -F .c))
CFLAGS= -g -fsanitize=address,leak
CLIBS= -lm -lpthread


.PHONY:all clean

all:clean $(SOURCES)

$(SOURCES): %: %.c
	$(CC) $(CFLAGS) -o $(basename $<) $< $(CLIBS)

clean:
	rm -f $(SOURCES)
