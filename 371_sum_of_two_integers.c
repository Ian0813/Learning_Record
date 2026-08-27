/*
 * =====================================================================================
 *
 *       Filename:  371_sum_of_two_integers.c
 *
 *    Description:  Sum of two integers 
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

#define INT_BITS_LEN ((CHAR_BIT * sizeof(int)))

static int decrease_by(int value) {

    int bit_unit = 1;

    if (!value)
        value |= (1 << 31);
    else if (!(value%2)) {
        while (!(value & (bit_unit))) {
            value |= bit_unit;
            bit_unit <<= 1;
        }
        value ^= bit_unit;
    } else {
        value ^= bit_unit;
    }
    return value;
}

static int increase_by(int value) {

    int bit_unit = 1;

    if (!(value%2)) {
        value |= bit_unit;
    } else {
        while (value & bit_unit) {
            value ^= bit_unit;
            bit_unit <<= 1;
        }
        value |= bit_unit;
    }

    return value;
}

static int add_two_integers(int a, int b) {

    int sum = 0, carryin = 0;
    int maxbit = INT_BITS_LEN, offset = 0;

    while (offset < maxbit) {
        if ((a & (1U << offset)) && (b & (1U << offset))) {
            if (carryin) {
                sum |= (1U << offset); 
            }
            carryin = 1U;
        } else if ((a & (1U << offset)) || (b & (1U << offset))) {
            if (!carryin)
                sum |= (1U << offset);
        } else {
            if (carryin) {
                sum |= (1U << offset); 
                carryin = 0;
            }
        }
        offset = increase_by(offset);
    }
    return sum;
}

int getSum(int a, int b) {
    return add_two_integers(a, b);
}

