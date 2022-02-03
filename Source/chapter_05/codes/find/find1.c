/*
 * =====================================================================================
 *
 *       Filename:  find1.c
 *
 *    Description:  print lines that match pattern from 1st argument.
 *
 *        Version:  1.0
 *        Created:  2021年12月31日 21時23分20秒
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

#define MAXLINE 1000


int GetString(char *line){

	char ch;
	int len = 0;
	
	while((ch = getchar()) != EOF && ch != '\n' && len < MAXLINE){
		*line++ = ch;
		len++;
	}

	if(len > 0){
		*line++ = '\n';
		*line = '\0';
	}
	
	return len;		
}

void main(int argc, char *argv[]){

	char line[MAXLINE] = {0};
	int found = 0;

	if(argc == 1){
		printf("Usage : %s \"pattern\"\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while(GetString(line) > 0){
		if(strstr(line, argv[1]) != NULL){
			printf("Find pattern %s in the line.\n", argv[1]);
			found++;
		}		
	}
}
