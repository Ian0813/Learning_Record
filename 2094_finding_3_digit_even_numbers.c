/*
 * =====================================================================================
 *
 *       Filename:  2094_finding_3_digit_even_numbers.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2025年05月14日 20時20分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum {false, true} bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define TABLE_SIZE 10
#define MAXIMUM_NUM 999
#define IS_EVEN_NUMBER(val) (!(val%2))

static void digit_counter(int *counts, int *digits, int digitsSize) {

    for (int i = 0; i < digitsSize; i++) {
        counts[digits[i]]++;
    }
    return;
}

static bool is_possible(int *counts, int value) {

    int temp = 0;
    int dup_counts[TABLE_SIZE] = {0};
    bool rc = true;

    memcpy(dup_counts, counts, sizeof(int)*TABLE_SIZE);

    while (value) {
        temp = value%10;

        if (!dup_counts[temp]) {
            rc = false;
            break;
        }

        if (dup_counts)
            dup_counts[temp]--;
        value /= 10;
    }
    return rc;
}

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {

    int counts[TABLE_SIZE] = {0};
    int *result = NULL, len = 0;

    if (digitsSize) {
        digit_counter(counts, digits, digitsSize);
    }

    for (int i = 100; i <= MAXIMUM_NUM; i++) {
        if (is_possible(counts, i) && IS_EVEN_NUMBER(i)) {
            len++;
            result = (int *) reallocarray(result, len, sizeof(int));
            result[len-1] = i;
        }
    }
    *returnSize = len;

    return result;
}
