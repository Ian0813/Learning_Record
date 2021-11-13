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

void itoa(int, char *);

int main(int argc, char *argv[]){

	char str[100] = {0};
	if(argc > 1){
		itoa(atoi(argv[1]), str);
		printf("str : %s\n", str);
	}else{
		printf("Please enter the argument.\n");
	}

	return 0;
}

