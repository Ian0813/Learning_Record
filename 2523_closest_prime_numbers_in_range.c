/*
 * =====================================================================================
 *
 *       Filename:  2523_closest_prime_numbers_in_range.c
 *
 *    Description:  closest prime numbers in range
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXIMUM_NUM (1000000)
#define RESULT_SIZE 2
#define RIGHT_INDEX 1
#define LEFT_INDEX 0

static void generate_prime_table(int *prime_table, int maximum) {

    int division = maximum/2; 

    for (int i = 2; i <= division; i++) {
        for (int j = i+i; j <= maximum; j += i) {
            if (prime_table[j])
                continue;
            prime_table[j] = 1; 
        }
    }
    return;
}

int* closestPrimes(int left, int right, int* returnSize) {

    int *result = NULL, temp = 0, interval = INT_MAX;
    int prime_table[MAXIMUM_NUM+1] = {-1};

    result = (int *) calloc(RESULT_SIZE, sizeof(int));
    memset(result, -1, sizeof(int)*RESULT_SIZE);

    generate_prime_table(prime_table, right);

    if (left < 2)
        left = 2;

    for (int i = left; i <= right; i++) {
        if (!prime_table[i]) {
            for (int j = i+1; j <= right; j++) {
                if (!prime_table[j]) {
                    if (interval >= (j-i)) {
                        result[RIGHT_INDEX] = j;
                        result[LEFT_INDEX] = i;
                        interval = (j-i);
                        i = j-1;
                        break;
                    }
                }
            }
        }
        if (interval <= 2)
            break;
    }
    *returnSize = RESULT_SIZE;
    return result;
}

int main(void) {

    closestPrimes(0, 0, NULL);

    return EXIT_SUCCESS;
}
