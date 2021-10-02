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

/* getline2 : get line into s, return length */

int getline2(char s[], int lim){

	int c, i = 0;

	while(lim-- > 0 && ((c = getchar()) != EOF) && c != '\n'){
		s[i++] = c;
	}

	if(c == '\n'){
		s[i++] = '\n';
	}
	s[i] = '\0';

	return i;
}

/*  strindex : return index of t in s, -1 if none */

int strindex(char s[], char t[]){
	//printf("%s called, pattern : %s\n", __func__, t);
	int i, j, k;

	for(i = 0; s[i] != '\0'; i++){
		
		for(j = i, k = 0; t[k] != '\0' && t[k] == s[j]; j++, k++)
			;

		if(k > 0 && t[k] == '\0'){
			return i;
		}
	}
	
	return -1;
}







