/*
 * =====================================================================================
 *
 *       Filename:  3314_construct_the_minimum_bitwise_array_i.c
 *
 *    Description:  construct the minimum bitwise array i
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int get_answer(int number) {

    int value = -1, first_zero = 0;
    int bit_length = sizeof(int) * CHAR_BIT; 

    if (number == 2) {
        return value;
    }

    for (int i = 0; i < bit_length; i++) {
        if (!(number & (1 << i))) {
            first_zero = i;
            break;
        }
    }

    value = number & ~(1 << (first_zero - 1));
    return value;
}

int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {

    int *result = NULL, index = 0;

    result = (int *) calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        result[index++] = get_answer(nums[i]); 
    }

    *returnSize = index;
    return result;
}

int main(void) {

    int *ptr = NULL, nums[] = {2, 3, 5, 7};
    int length = 0;

    ptr = minBitwiseArray(nums, sizeof(nums)/sizeof(int), &length);
    free(ptr);

    return EXIT_SUCCESS;
}
