/*
 * =====================================================================================
 *
 *       Filename:  1513_number_of_substrings_with_only_1s.c
 *
 *    Description:  number of substrings with only 1s
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

#define GET_CUMULATIVE(val) (((val)*(val+1))/2)
#define MODULO_BOUND 1000000007

typedef enum {
    CH_ZERO = '0',
    CH_ONE = '1',
} ch_type;

int numSub(char* s) {

    int slen = 0;
    long long total_count = 0LL, ones_len = 0LL;

    slen = strlen(s);

    for (int i = 0; i < slen; i++) {
        if (s[i] == CH_ONE) {
            ones_len++;
        } else {
            total_count = (total_count + GET_CUMULATIVE(ones_len)) % MODULO_BOUND;
            ones_len = 0LL;
        }
    }

    if (ones_len)
        total_count = (total_count + GET_CUMULATIVE(ones_len)) % MODULO_BOUND;

    return (int) total_count;
}
