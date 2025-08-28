/*
 * =====================================================================================
 *
 *       Filename:  3158_find_the_xor_of_numbers_which_appear_twice.c
 *
 *    Description:  find the xor of numbers which appear twice
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

#define TABLE_SIZE (51)

enum {
    NUMBER_ZERO = 0, 
    NUMBER_TWICE = 2 
};

static void count_occurrences(int *counter, int *nums, int numsSize) {

    for (int i = 0; i < numsSize; i++) {
        counter[nums[i]]++; 
    }

    return;
}

static int calculate_xor_values(int *arr, int size, int *counter) {

    int value = 0;

    for (int i = 0; i < size; i++) {
        if (counter[arr[i]] == NUMBER_TWICE) {
            counter[arr[i]] = NUMBER_ZERO; 
            value = !value ? arr[i] : (value ^ arr[i]); 
        }
    }

    return value;
}

int duplicateNumbersXOR(int* nums, int numsSize) {

    int counter[TABLE_SIZE] = {0}, calculated[TABLE_SIZE] = {0};

    count_occurrences(counter, nums, numsSize);
    
    return calculate_xor_values(nums, numsSize, counter);
}
