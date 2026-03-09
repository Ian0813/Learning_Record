/*
 * =====================================================================================
 *
 *       Filename:  2544_alternating_digit_sum.c
 *
 *    Description:  alternating digit sum
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
#include <ctype.h>

#define MAXLEN 128
#define GET_VALUE(value, index) (((index) % 2) ? (-(value)) : (value))

static int do_operation(int value, int *varray, int *size) {

    int result = 0, temp = 0;

    while (value) {
        varray[*size] = value % 10;
        *size += 1;
        value /= 10;
    }

    for (int i = 0, j = *size - 1; i < j; i++, j--) {
        temp = varray[i];
        varray[i] = varray[j];
        varray[j] = temp;
    }

    for (int i = 0; i < *size; i++) {
        result += GET_VALUE(varray[i], i);
    }

    return result;
}

int alternateDigitSum(int n) {

    int *varray = NULL, vsize = 0;
    int result = 0;

    varray = (int *) calloc(MAXLEN, sizeof(int));

    result = do_operation(n, varray, &vsize);
    free(varray);
    
    return result; 
}
