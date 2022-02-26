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
#include <time.h>



void QuickSort(int*, int, int);

int main(void){

	int arr[20];

	srand(time(NULL));

	for(int i = 0; i < 20; i++){
		arr[i] = rand() % 1000;
		printf("arr[%02d] : %d\n", i, arr[i]);
	}

	QuickSort(arr, 0, 19);

	putchar(10);
	for(int i = 0; i < 20; i++){
		printf("arr[%02d] : %d\n", i, arr[i]);
	}

	return 0;
}
