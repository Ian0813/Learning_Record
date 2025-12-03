/*
 * =====================================================================================
 *
 *       Filename:  1009_complement_of_base_10_integer.c
 *
 *    Description:  1009 complement of base 10 integer
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
#include <limits.h>

#define INT_BITLEN (CHAR_BIT * sizeof(int))

static void to_binary(int value, int *bit_table, int *len) {

    int bit = 0;

    do {
        bit_table[*len] = !(value % 2);
        *len += 1;
        value /= 2;
    } while (value);
    return;
}

static int bin_to_value(int *bit_table, int len) {

    int value = 0;

    for (int i = len-1; i >= 0; i--) {
        value = 2 * value + bit_table[i];
    }

    return value;
}

int bitwiseComplement(int n) {

    int bit_table[INT_BITLEN] = {0};
    int complement_val = 0, bitlen = 0;

    to_binary(n, bit_table, &bitlen);
    complement_val = bin_to_value(bit_table, bitlen);

    return complement_val;
}
