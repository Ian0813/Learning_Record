/*
 * =====================================================================================
 *
 *       Filename:  3309_maximum_possible_number_by_binary_concatenation.c
 *
 *    Description:  maximum possible number by binary concatenation
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX_INT_BITLEN (sizeof(int) * CHAR_BIT)
#define CH_TO_INT(ch) ((ch)-'0')
#define INT_TO_CH(val) ((val)+'0')

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;
    return;
}

static int get_number(int *nums, int numsSize) {

    char str[(CHAR_BIT * numsSize)+1];
    int index = 0, slen = 0, value = 0;

    memset(str, 0, (CHAR_BIT * numsSize) + 1);

    for (int i = 0, flag = 0; i < numsSize; i++, flag = 0) {
        for (int j = MAX_INT_BITLEN-1; j >= 0; j--) {
            if (flag) {
                str[slen++] = INT_TO_CH((nums[i] >> j) & 1); 
            } else if (!flag && ((nums[i] >> j) & 1)) {
                str[slen++] = INT_TO_CH((nums[i] >> j) & 1); 
                flag = 1;
            }
        }
    }

    for (int i = 0; i < slen; i++) {
        value *= 2;
        value += CH_TO_INT(str[i]); 
    }
    return value;
}

static void get_max_permutation(int *nums, int numsSize, int index, int *max) {

    int value = 0;

    if (index < numsSize) {
        for (int i = index; i < numsSize; i++) {
            swap(&nums[i], &nums[index]); 
            get_max_permutation(nums, numsSize, index+1, max);
            swap(&nums[i], &nums[index]); 
        }
    } else {
        value = get_number(nums, numsSize);

        if (value > *max)
            *max = value;
    }
    return;
}

int maxGoodNumber(int* nums, int numsSize) {

    int max = 0;

    get_max_permutation(nums, numsSize, 0, &max);

    return max;
}
