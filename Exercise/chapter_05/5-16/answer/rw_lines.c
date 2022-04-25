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
#include <errno.h>
#include <stdbool.h>
#define FILE_NAME "data.txt"


void errorSystemMessage(char *fun, int error, int columns){
	fprintf(stderr, "%s return error : %d, message : %s, at lines %d\n", fun, error, strerror(error), columns);
	exit(EXIT_FAILURE);
}

void create_file(int lines){

	FILE *fp = fopen(FILE_NAME, "w");

	if(fp == NULL){
		errorSystemMessage("fopen", errno, __LINE__);
	}

	char ch;

	for(int i = 0; i < lines; i++){

		for(int j = 0; j < 29; j++){
			if(rand() % 2){
				ch = rand() % 26 + 97;
				fwrite(&ch, 1, sizeof(char), fp);
			}else{
				ch = rand() % 26 + 65;
				fwrite(&ch, 1, sizeof(char), fp);
			}
		}
		ch = '\n';
		fwrite(&ch, 1, sizeof(char), fp);
	}

	fclose(fp);
	
	return;
}

int readlines(char *lineptr[], int maxlines){

	printf("%s entered.\n", __func__);	
	FILE *fp = NULL;
	int ret;

	//for(int i = 0; *lineptr[i] == NULL; i++){
	//	printf("%d\n", i);
	//}

	fp = fopen(FILE_NAME, "r");
	if(fp == NULL){
		perror("fopen ");
		exit(EXIT_FAILURE);
	}

	size_t word_count = 0;

	for(int i = 0; i < maxlines; i++, word_count = 0) {
	    ret = getline(&lineptr[i], &word_count, fp);
		if(ret == -1){
			errorSystemMessage("getline", errno, __LINE__);
			fclose(fp);
		}
	}

	fclose(fp);	

	return maxlines;
}

#if 0
void writelines(char *lineptr[], int nlines){

	for(int i = 0; i < nlines; i++){
		printf("[%02d] %s", i + 1, lineptr[i]);
	}
	return;	
}
#endif

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
