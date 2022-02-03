/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  The main function for testing the getfloat().
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

#define SIZE 2 

int main(void){

	int n, getfloat(float *);

	float array[SIZE];
	memset(array, 0, sizeof(array));


	for(n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
			;
	
	for(int i = 0; i < SIZE; i++){
		if(array[i] == 0){
			array[i] = 0.0;
		}
		printf("%03.5f ", array[i]);
	}

	printf("\n");

	return 0;
	
}

