/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  alloc and afree
 *
 *        Version:  1.0
 *        Created:  2021年11月28日 15時28分15秒
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

char *alloc(int);
void afree(char *ptr);

int main(void){


	char *ptr = NULL;

	printf("Before allocate...\n");
	printf("ptr : %p\n", ptr);
	ptr = alloc(20);
	puts("After allocated...\n");
	printf("ptr : %p\n", ptr);


	return 0;
}

