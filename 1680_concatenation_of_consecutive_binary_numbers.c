/*
 * =====================================================================================
 *
 *       Filename:  1680_concatenation_of_consecutive_binary_numbers.c
 *
 *    Description:  concatenation of consecutive binary numbers
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

#define INT_BITS_LEN (CHAR_BIT * sizeof(int))
#define VAL_TO_CH(val) ((val) ? '1' : '0')
#define MODULO_VAL (1000000007) 

int concatenatedBinary(int n) {

    long long result = 0LL;
    int offset = INT_BITS_LEN-1;

    for (int i = 1; i <= n; i++) {
        while (!((i >> offset) & 1) && offset >= 0)
            offset--;

        while (offset >= 0) {
            result = (result * 2LL) % MODULO_VAL;
            result = (result + (((i >> offset) & 1) ? 1LL : 0LL)) % MODULO_VAL;
            offset--;
        }
        offset = INT_BITS_LEN-1;
    }
    return (int) result;  
}
