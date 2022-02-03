/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  invoke strcmp
 *
 *        Version:  1.0
 *        Created:  2021年12月02日 22時24分41秒
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

int strcmp_v1(char *, char *);

int main(int argc, char *argv[]){


	if(argc > 2){
		printf("Compariosn two strings :　%d\n", strcmp_v1(argv[1], argv[2]));
	}else{
		printf("A number of the arguments not enough.\n");
	}

	return 0;
}

