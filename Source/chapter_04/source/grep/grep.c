/*
 * =====================================================================================
 *
 *       Filename:  grep.c
 *
 *    Description:  Print a line of its input that contains a particular pattern.
 *
 *        Version:  1.0
 *        Created:  2021年09月24日 00時39分05秒
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

#define MAXLINE 1000 /*  maximum input line length */

int getline2(char line[], int max);
int strindex(char source[], char searchfor[]);


char pattern[] = "ould";


/*  find all lines matching pattern */
int main(){

	char line[MAXLINE] = {0};
	int found = 0;


	while(getline2(line, MAXLINE) > 0){
		if(strindex(line, pattern) >= 0){
			printf("The line contain the pattern.\n");
			printf("%s", line);
			found++;
		}
	}

	return 0;
}
