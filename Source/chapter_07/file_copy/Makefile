CC=gcc
CFLAGS= -g -fsanitize=address
CLIBS= -lm -lpthread
CFILES=$(wildcard *.c)
COBJS=$(patsubst %.c, %.o, $(CFILES))

.PHONY: all clean

all: clean $(COBJS) cat_v1 cat_v2 
	
cat_v1:
	$(CC) $(CFLAGS) -o $@ $(filter file% %v1.o, $(COBJS)) $(CLIBS) 

cat_v2:
	$(CC) $(CFLAGS) -o $@ $(filter file% %v1.o, $(COBJS)) $(CLIBS) 

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(CLIBS)

clean:
	rm -rf $(wildcard *.o) cat_v1 cat_v2





