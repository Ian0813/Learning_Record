/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  A function named main is to implement the quick sorted numerically.
 *
 *        Version:  1.0
 *        Created:  2022年01月29日 01時56分05秒
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
#include "numeric_sort.h"


#define MAXLINES 5000 /* max #lines to be sorted. */
char *lineptr[MAXLINES]; /* pointers to text lines */


void quick_sort(char *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);


void main(int argc, char *argv[]){

	int nlines = 0; /*  number of input lines read */
	int numeric = 0; /*  if numeric sort */
	int reversing = 0; /* if sorting in reverse */

	if(argc > 1 && strcmp(argv[1], "-n") == 0){
		numeric = 1;
	}


	while(argc > 1){

		if(strcmp(argv[argc-1], "-n") == 0){
			numeric = 1;		
		}

		if(strcmp(argv[argc-1], "-r") == 0){
			reversing = 1;
		}
		argc--;
	}

	readlines(lineptr, &nlines);

	if(nlines <= 0){
		printf("Not any data could do sorted.\n");
	}

	quick_sort(lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric? (void *) numcmp: (void *)strcmp));
	
	if(reversing){
		char *k = NULL;	
		for(int i = 0, j = nlines - 1; i < j; i++, j--){
			k = lineptr[i];
			lineptr[i] = lineptr[j];
			lineptr[j] = k;	
		}
	}

	writelines(lineptr, nlines);
}	
