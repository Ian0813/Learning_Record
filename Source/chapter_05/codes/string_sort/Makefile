CC=gcc
COPTIONS= -g -fsanitize=address,leak
CLIBS= -lm -lpthread
CFILES=$(patsubst %.c, %, $(shell find ./ -name "*.c";))
CHEADER_PATH=$(shell find ./ -name "*.h" -exec dirname {} \;)
$(shell if [ ! -d "objects" ] ; then mkdir objects; fi)
$(shell if [ ! -d "exe" ] ; then mkdir exe; fi)

.PHONY: clean all

all:$(CFILES)
	$(CC) $(COPTIONS) -I$(CHEADER_PATH) -o exe/execute  objects/*.o $(CLIBS)


$(CFILES): %: %.c 
	$(CC) $(COPTIONS) -I$(CHEADER_PATH) -o objects/$(notdir $@).o -c $< $(CLIBS)


clean:
	rm -rf objects exe
