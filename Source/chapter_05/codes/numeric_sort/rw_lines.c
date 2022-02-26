/*
 * =====================================================================================
 *
 *       Filename:  rw_lines.c
 *
 *    Description:  read or write lines 
 *
 *        Version:  1.0
 *        Created:  2022年01月29日 08時50分58秒
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

#define FILE_NAME "data.txt"


void readlines(char *lineptr[], int *c){

	printf("%s entered.\n", __func__);	
	FILE *fp = NULL;

	//for(int i = 0; *lineptr[i] == NULL; i++){
	//	printf("%d\n", i);
	//}

	fp = fopen(FILE_NAME, "r");
	if(fp == NULL){
		perror("fopen ");
		exit(EXIT_FAILURE);
	}

	size_t count = 0;

	for(int i = 0; getline(&lineptr[i], &count, fp) != -1 ; count = 0, i++){
		(*c)++;
	}

	fclose(fp);	

	return;
}

void writelines(char *lineptr[], int nlines){

	for(int i = 0; i < nlines; i++){
		printf("[%02d] %s", i + 1, lineptr[i]);
	}
	return;	
}

#if 0

void main(void){

	char *lineptr[5000];
	int c = 0;

	memset(&lineptr, 0L, sizeof(lineptr));

	readlines(lineptr, &c);
		
	for(int i = 0; i < columns; i++){
		printf("[%d] %s", i + 1, lineptr[i]);
		printf("Conversion : %f\n", atof(lineptr[i]));
	}

	for(int i = 0; lineptr[i] != NULL; i++){
		free(lineptr[i]);
	}
	
	return;
}

#endif
