/*
 * =====================================================================================
 *
 *       Filename:  2442_count_number_of_distinct_integers_after_reverse_operations.c
 *
 *    Description:  You are given an array nums consisting of positive integers.  
 *                  You have to take each integer in the array, reverse its digits, and add it to the end of the array. 
 *                  You should apply this operation to the original integers in nums.  
 *                  Return the number of distinct integers in the final array.
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

#define TABLE_SIZE 1000001

int get_reversenum(int num) {

    int val = 0;

    while (num) {
        val = (val*10) + (num%10);
        num /= 10;
    }
    return val;
}

int *get_reverse_arr(int *nums, int numsSize) {

    int *dup_reverse = NULL;

    if (numsSize) {

        dup_reverse = (int *) calloc(numsSize, sizeof(int));

        for (int i = 0; i < numsSize; i++) {
            dup_reverse[i] = get_reversenum(nums[i]);
        }
    }
    return dup_reverse;
}

int countDistinctIntegers(int* nums, int numsSize) {

    int count_table[TABLE_SIZE] = {0};
    int *reverse_nums = NULL, count = 0;

    reverse_nums = get_reverse_arr(nums, numsSize);

    if (reverse_nums) {

        for (int i = 0; i < numsSize; i++) {
            count_table[nums[i]] = 1;
            count_table[reverse_nums[i]] = 1;
        }

        for (int i = 0; i < TABLE_SIZE; i++) {
            if (count_table[i]) {
                count++;
            }
        }
    }
    return count;
}

