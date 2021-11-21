/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  the main function for testing the getint()
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

#define SIZE 5

int main(void){

	int n, array[SIZE], getint(int *);
	memset(array, 0, sizeof(array));


	for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
			;
	
	for(int i = 0; i < SIZE; i++){
		printf("%d ", array[i]);
	}

	printf("\n");

	return 0;
	
}

