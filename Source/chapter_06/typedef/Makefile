CC=gcc
CFLAGS= -fsanitize=address
CLIBS= -lpthread -lm
EXE_FILE=$(wildcard *.c)

.PHONY: all clean

all:
	$(CC) $(CFLAGS) -o $(basename $(EXE_FILE)) $(wildcard *.c) $(CLIBS)


clean:
	rm -rf $(basename $(EXE_FILE))


