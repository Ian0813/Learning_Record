/*
 * =====================================================================================
 *
 *       Filename:  769_max_chunks_to_make_sorted.c
 *
 *    Description:  max chunks to make sorted
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
#include <limits.h>

int maxChunksToSorted(int* arr, int arrSize) {

    int chunks = 0, index = 0, max = INT_MIN;

    while (index < arrSize) {

        if (arr[index] > max) {
            max = arr[index];
        }

        if (max == index) {
            chunks++; 
        }
        index++;
    }
    return chunks;
}

int main(void) {

    int chunks = 0;
    int arr[] = {2, 0, 1};

    printf("%d\n", maxChunksToSorted(arr, sizeof(arr)/sizeof(int)));

    return EXIT_SUCCESS;
}
