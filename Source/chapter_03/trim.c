/*
 * =====================================================================================
 *
 *       Filename:  trim.c
 *
 *    Description:  The function trim(char *s) will removes trailing blanks, tabs, and
 *    				newline from the end of a string, using a break to exit from a loop
 *    				when the rightnost non-blank, non-tab, non-newline is found.
 *
 *        Version:  1.0
 *        Created:  2021年09月19日 11時49分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int trim(char *s){

	int n;

	for(n = strlen(s) - 1; n >= 0; n--){
		if(s[n] != 32 && s[n] != '\t' && s[n] != '\n'){
			break;
		}
	}
	memset((s+(n+1)), 0, (strlen(s) - 1) - n);

	return n;
}




int main(int argc, char *argv[]){
	
	int position;

	if(argc > 1){
		printf("trim...\n");
		printf("Before trim : %s\n", argv[1]);
		position = trim(argv[1]);
		printf("After trim : %s\n", argv[1]);
		printf("position : %d\n", position);
	}else{
		printf("Please enter the correct argument.\n");
	}

	return 0;
}

