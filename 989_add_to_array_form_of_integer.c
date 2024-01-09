/*
 * =====================================================================================
 *
 *       Filename:  989_add_to_array_form_of_integer.c
 *
 *    Description:  Add to array form of integer  
 *
 *       Compiler:  gcc (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX 10001
int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {

    int *array = (int *) calloc(MAX, sizeof(int));
    int index = 0, carryin = 0, temp = 0;

    for (int i = numSize - 1; i >= 0; i--) {

        array[index++] = num[i] + (k%10) + carryin;

        if (array[index-1] > 9) {
            carryin = array[index-1] / 10;   
            array[index-1] %= 10;    
        } else {
            carryin = 0; 
        }
        k/=10;        
    }

    while (k>0) {
        array[index++] = (k%10) + carryin;
        if (array[index-1] > 9) {
            carryin = array[index-1] / 10;   
            array[index-1] %= 10;    
        } else {
            carryin = 0; 
        }
        k/=10;
    }

    if (carryin > 0) {
        array[index++] = carryin;
    }

    for (int i = 0, j = index - 1; i < j; i++, j--) {
        temp = array[i]; 
        array[i] = array[j];
        array[j] = temp;
    }
	*returnSize = index;
    return array;
}


