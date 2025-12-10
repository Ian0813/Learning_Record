/*
 * =====================================================================================
 *
 *       Filename:  3750_minimum_number_of_flips_to_reverse_binary_string.c
 *
 *    Description:  minimum number of flips to reverse binary string
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <limits.h>

#define INT_BITS (CHAR_BIT * sizeof(int))

int minimumFlips(int n) {

    int diff = 0, msb_pos = 0;

    for (int i = INT_BITS-1; i >= 0; i--) {
        if ((n >> i) & 1) {
            msb_pos = i;
            break;
        }
    }

    for (int i = 0, j = msb_pos; i <= msb_pos; i++, j--) {
        if (((n >> i) & 1) != ((n >> j) & 1)) {
            diff++; 
        }
    }

    return diff;
}

int main(void) {

    minimumFlips(10);

    return EXIT_SUCCESS;
}
