/*
 * =====================================================================================
 *
 *       Filename:  2348_number_of_zero_filled_subarrays.c
 *
 *    Description:  number of zero filled subarrays
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

#define TABLE_SIZE 100001 

struct zero_sequence {
    int length;
    int count;
};

static int count_zeroseq(int *nums, int numsSize) {

    int count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (!nums[i]) {
            count++;
            continue;
        }
        break;
    }

    return count;
}

static long long calculate(int length, int *table) {

    long long accumlate = 0LL;

    if (!length)
        return accumlate;

    if (table[length]) {
        accumlate = table[length];
    } else {
        for (int i = length; i >= 1; i--) {
            accumlate += ((length-i) + 1); 
        }
        table[length] = accumlate;
    }
    return accumlate;
}

long long zeroFilledSubarray(int* nums, int numsSize) {

    struct zero_sequence zeros = {0};
    int count = 0, table[TABLE_SIZE] = {0};
    long long result = 0LL, total = 0LL, length = 0LL;

    for (int i = 0; i < numsSize; i++) {
        if (!nums[i]) {
            length = count_zeroseq(nums+i, numsSize-i);
            i += (length - 1);
            result += (length * (length+1LL)) / 2LL; 
        }
    }

    return result;
}
