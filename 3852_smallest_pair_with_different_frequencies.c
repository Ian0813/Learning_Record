/*
 * =====================================================================================
 *
 *       Filename:  3852_smallest_pair_with_different_frequencies.c
 *
 *    Description:  smallest pair with different frequencies
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define TABLE_SIZE 101
#define PAIR_LEN 2 

static void count_frequencies(int *nums, int numsSize, int *table) {

    for (int i = 0; i < numsSize; i++) {
        table[nums[i]]++;
    }
    return;
}

int* minDistinctFreqPair(int* nums, int numsSize, int* returnSize) {

    int *pair = NULL, freq1 = 0, freq2 = 0;
    int table[TABLE_SIZE] = {0};

    pair = calloc(PAIR_LEN, sizeof(int));
    count_frequencies(nums, numsSize, table);

    for (int i = 1; i < TABLE_SIZE; i++) {
        if (table[i] && !freq1) {
            pair[0] = i;
            freq1 = table[i];
        } else if (table[i] && (table[i] != freq1)) {
            pair[1] = i;
            freq2 = table[i];
            break;
        }
    }

    if (!freq1 || !freq2) {
        pair[0] = pair[1] = -1;
    }
    *returnSize = PAIR_LEN;
    return pair;
}
