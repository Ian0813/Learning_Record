/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  The main function for testing a set of a string handling function.
 *
 *        Version:  1.0
 *        Created:  2021年11月21日 15時38分56秒
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

char *strncpy_p(char *, char *, int);
int strncmp_p(char *, char *, int);
char *strncat_p(char *, char *, int);

int main(int argc, char *argv[]){


	char str[100];
	memset(str, 0, sizeof(str));

	if(argc > 1){
		strncpy(str, argv[1], 3);	
	}

	if(!strncmp_p(str, argv[1], 3)){
		printf("These strings are identical.\n");
	}else{
		printf("Not identical, %d\n", strncmp_p(str, argv[1], 3));
	}

	strncat_p(str, argv[1], 3);

	printf("%s\n", str);

	return 0;
}

