/*
 * =====================================================================================
 *
 *       Filename:  3950_exactly_one_consecutive_set_bits_pair.c
 *
 *    Description:  exactly one consecutive set bits pair
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

typedef enum {false, true} bool;

#define PAIR_LEN 2
#define INT_BITS (CHAR_BIT * sizeof(int))

bool consecutiveSetBits(int n) {

    int pairs_count = 0, one_count = 0;

    for (int i = INT_BITS-1; i >= 0; i--) {
        if ((n >> i) & 1) {
            one_count++;
        }

        if (!((n >> i) & 1)) {
            if (one_count > PAIR_LEN)
                pairs_count += ((one_count/2) + 1); 
            else if (one_count == PAIR_LEN) 
                pairs_count += 1; 
            one_count = 0;
        }
    }

    if (one_count > PAIR_LEN)
        pairs_count += ((one_count/2) + 1); 
    else if (one_count == PAIR_LEN) 
        pairs_count += 1; 

    return pairs_count == 1 ? true : false;
}
