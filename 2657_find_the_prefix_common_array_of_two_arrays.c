/*
 * =====================================================================================
 *
 *       Filename:  2657_find_the_prefix_common_array_of_two_arrays.c
 *
 *    Description:  Find the prefix common array of two arrays  
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
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

#define TABLE_SIZE 51

static void fill_table(int *arr, int size, int *table) {

    for (int i = 0; i < size; i++) {
        table[arr[i]] = i;
    }
    return;
}

int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize){

    int *C = NULL;
    int csize = 0;
    int a_table[TABLE_SIZE] = {0}, b_table[TABLE_SIZE] = {0};
    int count = 0;

    if (ASize && BSize) {

        csize = ASize;
        C = (int *) calloc(csize, sizeof(int));
        fill_table(A, ASize, a_table);
        fill_table(B, BSize, b_table);

        for (int i = 0; i < ASize; i++) {
        
            if (b_table[A[i]] <= i) {
                count++; 
            }

            if (b_table[B[i]] > a_table[B[i]]) {
                count++;
            }
            C[i] = count;
        }
    }
    *returnSize = csize;
    return C;
}
