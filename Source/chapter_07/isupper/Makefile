CC=gcc
CFLAGS= -g -fsanitize=address
CLIBS= -lm -lpthread
COBJS=$(patsubst %.c, %.o, $(wildcard *.c))

ifdef SAVE_TIME
    CFLAGS += -DSAVE_TIME
endif

.PHONY: all clean

all: isupper.o 
	$(CC) $(CFLAGS) -o $(basename $(COBJS)) $(COBJS) $(CLIBS)

isupper.o:
	$(CC) $(CFLAGS) -c $(basename $(COBJS)).c $(CLIBS) 

clean:
	@rm -rf $(basename $(COBJS)) $(COBJS)

help:
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'
