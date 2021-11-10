/*
 * =====================================================================================
 *
 *       Filename:  QuickSort.c
 *
 *    Description:  Quick sort algorithm  
 *
 *        Version:  1.0
 *        Created:  2021年11月09日 00時53分42秒
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


void Swap(int *arr, int pos1, int pos2){

	int temp;

	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;

}


void QuickSort(int *arr, int left, int right){

	int last, index;

	if(left >= right){
		return ;
	}
	
	last = left;
	Swap(arr, left, (left+right)/2);

	for(index = left + 1; index <= right; index++){
		if(arr[index] < arr[left]){
			Swap(arr, ++last, index);
		}	
	}

	Swap(arr, left, last);
	QuickSort(arr, left, last - 1);
	QuickSort(arr, last + 1, right);	

}

