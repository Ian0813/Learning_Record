/*
 * =====================================================================================
 *
 *       Filename:  shellsort.c
 *
 *    Description:  shell sort algorithm
 *
 *        Version:  1.0
 *        Created:  2021年09月13日 22時26分34秒
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


void shellsort(int *arr, int n){

	int gap, temp, j, k;

	for(gap = n/2; gap > 0; gap /= 2){
		for(j = gap; j < n; j++){
			for(k = j-gap; k >= 0 && arr[k] > arr[k+gap];  k-=gap){
				temp = arr[k + gap];
				arr[k + gap] = arr[k];	
				arr[k] = temp;
			}
		}
	}
}




int main(int argc, char *argv[]){

	int *arr, number; 
	srand(time(NULL));

	if(argc > 1){
		number = atoi(argv[1]);
		arr = (int *) malloc(sizeof(int) * number);
		for(int i = 0; i < number; i++){
			arr[i] = rand() % 1000;
			printf("arr[%d] = %d\n", i, arr[i]);
		}
		shellsort(arr, number);
		putchar(10);
		for(int i = 0; i < number; i++){
			printf("arr[%d] = %d\n", i, arr[i]);
		}
	}else{
		printf("Please enter the correct argument.");
	}

	if(arr){
		free(arr);
	}

	return 0;
}


