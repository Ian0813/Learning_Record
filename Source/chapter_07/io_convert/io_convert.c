/*
 * =====================================================================================
 *
 *       Filename:  io_convert.c
 *
 *    Description:  Convert the input to lowercase. 
 *
 *        Version:  1.0
 *        Created:  2022年08月13日 21時54分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>

#define FILE_NAME "random_text.txt"

/* text_generator: Generate a file containing 100 letters of uppercase. */
void text_generator(int num) {

    FILE *fp = NULL;
	int *val = (int *) malloc(sizeof(int)); 

	fp = fopen(FILE_NAME, "w");	

	if (fp == NULL) {
		perror("fopen ");
		exit(EXIT_FAILURE);
	}

	for (int count = 1; count <= num; count++) {

		*val = rand() % 26 + 65;
		if (fwrite(val, 1, 1, fp) < 1) {
			perror("fwrite ");
			exit(EXIT_FAILURE);
		}	
	}

	assert(fwrite("\n", 1, 1, fp) != 0);

	if (fclose(fp) != 0) {
		perror("fclose ");
		exit(EXIT_FAILURE);
	}

	free(val);
	return; 
}


void main(int argc, char *argv[]) {

    int c;

	if (system("test -f random_text.txt") != 0 && strcmp(argv[1], "write") != 0) {
		printf("Please generate a text file first.\n");
		printf("Usage: %s \"write\"\n", argv[0]);
		exit(EXIT_FAILURE);
	}

    if (argc > 1 && strcmp(argv[1], "write") == 0) {

	    srand(time(NULL));
	    text_generator(100);

	} else {
	    while ((c = getchar()) != EOF) {
	    	putchar(tolower(c));
	    }
	}
	
	return;
}
