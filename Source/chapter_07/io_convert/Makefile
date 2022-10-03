CC=gcc
CFLAG= -g -fsanitize=address
EXE_NAME=$(shell basename "$(PWD)")


.PHONY: all clean

all:
	$(CC) $(CFLAG) -o $(EXE_NAME) $(EXE_NAME).c

clean:
	rm -rf $(EXE_NAME) *.txt

