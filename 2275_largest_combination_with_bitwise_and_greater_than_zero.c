/*
 * =====================================================================================
 *
 *       Filename:  2275_largest_combination_with_bitwise_and_greater_than_zero.c
 *
 *    Description:  largest combination with bitwise and greater than zero
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

#define INT_BITS_LEN (sizeof(int) * CHAR_BIT)

static void table_bits_append(int *table, int table_size, int val, int *max_freq) {

    for (int i = table_size; i; i--) {
        if ((val >> (i-1)) & 1) {
            table[i-1]++;
            *max_freq = *max_freq > table[i-1] ? *max_freq : table[i-1]; 
        }
    }
    return;
}

int largestCombination(int* candidates, int candidatesSize) {

    int bits_table[INT_BITS_LEN] = {0};
    int result = INT_MIN; 

    for (int i = 0; i < candidatesSize; i++) {
        table_bits_append(bits_table, INT_BITS_LEN, candidates[i], &result);
    }
    return result;
}
