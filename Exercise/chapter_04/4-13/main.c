/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This function is to represent a number by character.  
 *
 *        Version:  1.0
 *        Created:  2021年11月09日 00時46分20秒
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

void reverse(char *, int, int);

int main(int argc, char *argv[]){

	char str[100] = {0};
	if(argc > 1){
		printf("Reverse the string you entered.\n");
		reverse(argv[1], 0, strlen(argv[1]) - 1);
		printf("str : %s\n", argv[1]);
	}else{
		printf("Please enter the argument.\n");
	}

	return 0;
}

