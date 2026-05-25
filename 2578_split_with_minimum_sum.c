/*
 * =====================================================================================
 *
 *       Filename:  2578 split with minimum sum.c
 *
 *    Description:  split with minimum sum
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

#define MAX_LEN 16
#define INT_TO_CH(val) ((val)+'0')
#define CH_TO_INT(ch) ((ch)-'0')

static void num_to_digits(int num, char *digits, int *size) {

    int value = 0;
    char ch = '\0';

    while (num) {
        value = (num%10);
        num /= 10;
        digits[*size] = INT_TO_CH(value); 
        *size += 1;
    }

    for (int i = 0, j = *size - 1; i < j; i++, j--) {
        ch = digits[i];
        digits[i] = digits[j];
        digits[j] = ch;
    }
    return; 
}

static int get_mini_value(char *digits, int dlen) {

    int mindex = 0, temp = INT_MAX;

    for (int i = 0; i < dlen; i++) {

        if (digits[i] == '\0') 
            continue; 

        if (temp > CH_TO_INT(digits[i])) {
            temp = CH_TO_INT(digits[i]); 
            mindex = i;
        }
    }

    digits[mindex] = '\0';
    return temp;
}

int splitNum(int num) {

    char *digits = NULL;
    int dlen = 0, v1 = 0, v2 = 0, count = 0; 

    digits = (char *) calloc(MAX_LEN, sizeof(char));

    num_to_digits(num, digits, &dlen);

    while (count < dlen) {

        if (count < dlen)
            v1 = v1 ? ((v1 * 10) + get_mini_value(digits, dlen)) : get_mini_value(digits, dlen);
        count++;

        if (count < dlen) {
            v2 = v2 ? ((v2 * 10) + get_mini_value(digits, dlen)) : get_mini_value(digits, dlen);
            count++;
        }
    }

    free(digits);

    return v1 + v2;
}
