/*
 * =====================================================================================
 *
 *       Filename:  5-16.c
 *
 *    Description:  A code example was a reference from the answer book.
 *
 *        Version:  1.0
 *        Created:  2022年02月12日 16時54分10秒
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
#include <stdbool.h>
#include <ctype.h>

#define NUMERIC 1 /* numeric sort */
#define DECR 2 /*  sort in decreasing order */
#define FOLD 4 /*  fold upper and lower cases */ 
#define DIR  8  /* directory order */
#define LINES 100 /* max of lines to be sorted */

int charcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void quick_sort(char *lineptr[], int, int, int (*comp)(char *, char *));
void writelines(char *lineptr[], int nlines, int decr);
void create_file(int);
void memfree(char *lineptr[], int  maxlines){

	for(int i = 0; i < maxlines; i++){
		free(lineptr[i]);
	}
	return;
}

static char option = 0;

/* sort input lines */
int main(int argc, char *argv[]){

	char *lineptr[LINES]; /* pointers to text lines */
	int nlines;          /* number of input lines read */
	int c = 0, rc = 0, break_mark = 0;

	if(argc < 2){
		printf("%s [line number] [options]\n", argv[0]);
		exit(EXIT_FAILURE);
	}else{
		argc--;
		argv++;
		nlines = atoi(*argv);
		if(nlines <= 0){
			printf("Invalid line number.\n");
			exit(EXIT_FAILURE);
		}	
	}

	while(--argc > 0 && *(++argv)[0] == '-'){
		while(c = *++argv[0]){
			switch(c){
				case 'd':   /*  directory order */
					option |= DIR;
					break;
            	case 'f':   /* fold upper and lower cases */
					option |= FOLD;
					break;
				case 'n':   /* numberic  sort */
					option |= NUMERIC;
					break;
				case 'r':   /* sorting in decreasing order */
					option |= DECR;
					break;
				default:
					printf("sort : illegal option %c, argc : %d\n", c, argc);
					argc = 1;
					rc = -1;
					break;
			}
		}
	}

	create_file(nlines);
	memset(lineptr, 0, sizeof(lineptr));

	if(argc){
		printf("Usage : sort -fnrd \n");
	}else{
		if((nlines = readlines(lineptr, nlines)) > 0) {
    		if(option & NUMERIC){
				quick_sort(lineptr, 0, nlines - 1, (int (*)(char *, char *)) numcmp);
			}else if (option & FOLD){
				quick_sort(lineptr, 0, nlines - 1, (int (*)(char *, char *)) charcmp);
			}else{
      			quick_sort(lineptr, 0, nlines - 1, (int (*)(char *, char *)) strcmp);	
			}
			writelines(lineptr, nlines, option & DECR);
		}else {
			printf("input too big to sort ! \n");
			rc = -1;
		}
	}

	memfree(lineptr, nlines);

	return rc;
}

/* writelines : write output lines  */
void writelines(char *lineptr[], int nlines, int decr){

	int i;

	if(decr){                  /* print in decreasing order */
		for(i = nlines -1; i >= 0; i--){
			printf("%s", lineptr[i]);
		}
	}else{                     /* print in increasing order */ 
		for(i = 0; i < nlines; i++){
			printf("%s", lineptr[i]);
		}
	}		
}

/* charcmp : return < 0 if s < t, 0 if s == t, > 0 if s > t */
int charcmp(char *s, char *t){

    char a, b;
	int fold = ( option & FOLD ) ? 1 : 0;
	int dir = ( option & DIR ) ? 1 : 0;

	do{
		if(dir){
			while(!isalnum(*s) && *s != ' ' && *s != '\0'){
				s++;
			}
			while(!isalnum(*t) && *t != ' ' && *t != '\0'){
				t++;
			}
		}
		a = fold ? tolower(*s) : *s;
		s++;
		b = fold ? tolower(*t) : *t;
		t++;
		if(a == b && a == '\0'){
			return 0;
		}
	}while(a == b);

	return a - b; 
}
