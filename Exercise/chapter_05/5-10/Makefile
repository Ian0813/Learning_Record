CC=gcc
SOURCES=$(filter-out %test, $(patsubst %.c, %, $(shell find ./ -name "*.c")))
TEST_SOURCES=$(filter %test, $(patsubst %.c, %, $(shell find ./ -name "*.c")))
CFLAGS= -g -fsanitize=address
CLIBS= -lm -lpthread
EXE_NAME=$(shell pwd)


.PHONY: all clean

all:$(SOURCES)
	$(CC) $(CFLAGS) -o $(notdir $(EXE_NAME)) $(patsubst %, %.o, $(notdir $(SOURCES))) $(CLIBS)


# All prerequisites could run in parallel
test: $(TEST_SOURCES) $(SOURCES)
	$(CC) $(CFLAGS) -o $(basename $(notdir $<)) $(patsubst %, %.o, $(notdir $?)) $(CLIBS)

$(SOURCES): %: %.c
	$(CC) $(CFLAGS) -o $(basename $(notdir $<)).o -c $< $(CLIBS) 

$(TEST_SOURCES): %: %.c
	$(CC) $(CFLAGS) -o $(basename $(notdir $<)).o -c $< $(CLIBS) 

clean:
	rm -f test $(notdir $(patsubst %, %.o, $(SOURCES) $(TEST_SOURCES))) $(notdir $(EXE_NAME))
