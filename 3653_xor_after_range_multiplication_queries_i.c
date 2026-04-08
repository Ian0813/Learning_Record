/*
 * =====================================================================================
 *
 *       Filename:  3653_xor_after_range_multiplication_queries_i.c
 *
 *    Description:  xor after range multiplication queries i
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

#define MODULAR_VAL (1000000000 + 7)

enum {
    L_INDEX = 0,
    R_INDEX = 1,
    K_INDEX = 2,
    V_INDEX = 3
};

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {

    int result = 0, offset = 0, index = 0;
    unsigned long long value = 0LL;

    while (offset < queriesSize) {

        index = queries[offset][L_INDEX];

        while (index <= queries[offset][R_INDEX]) {
            value = (((unsigned long long) nums[index]) * queries[offset][V_INDEX]) % MODULAR_VAL; 
            nums[index] = value;
            index += queries[offset][K_INDEX];
        }

        offset++;
    }

    result = nums[0]; 

    for (int i = 1; i < numsSize; i++) {
        result ^= nums[i];
    }
    return result; 
}
