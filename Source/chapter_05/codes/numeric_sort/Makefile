CC=gcc
CFLAGS= -g -fsanitize=address
CLIBS= -lm
MAINS= main.c data_generator.c sample.c
CFILES=$(patsubst %.c, %, $(filter-out $(MAINS), $(shell ls *.c)))
$(shell if [ !  -d "exe" ];then mkdir exe ; fi)
$(shell if [ ! -d "objs" ]; then mkdir objs ; fi)


.PHONY: all clean



all:$(CFILES)
	$(CC) $(CFLAGS) -o exe/$(shell basename `pwd`) main.c objs/*.o $(CLIB)


$(CFILES): %: %.c
	$(CC) $(CFLAGS) -o objs/$(basename $<).o -c $< $(CLIBS)

DATA:
	$(CC) $(CFLAGS) -o exe/data_generator data_generator.c $(CLIBS) 


clean:
	rm -rf objs exe
