/*
 * =====================================================================================
 *
 *       Filename:  2231 largest number after digit swaps by parity.c
 *
 *    Description:  largest number after digit swaps by parity
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

#define DIGIT_SIZE 10

typedef enum {
    DIGIT_EVEN = 'E',
    DIGIT_ODD = 'O'
} digit_type;

static int fill_digit_type(char *ptr, int num, int *table) {

    int index = 0, value = 0;
    char temp = '\0'; 

    if (!ptr || !table)
        return index;

    while (num) {
        value = num%10;
        table[value]++; 

        if (value%2)
            ptr[index] = DIGIT_ODD;
        else
            ptr[index] = DIGIT_EVEN;
        num /= 10; 
        index++;
    }

    for (int i = 0, j = index-1; i < j; i++, j--) {
        temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
    }

    return index;
}

int largestInteger(int num) {

    char *digit_type = NULL;        
    int digit_count[DIGIT_SIZE] = {0}, dlen = 0, value = 0;

    digit_type = (char *) calloc(MB_LEN_MAX, sizeof(char));

    dlen = fill_digit_type(digit_type, num, digit_count);

    for (int i = 0; i < dlen; i++) {

        value *= 10;

        for (int j = DIGIT_SIZE-1; j > 0; j--) {
            if (!(j%2) && digit_count[j] && digit_type[i] == DIGIT_EVEN) {
                value += j;
                digit_count[j]--;
                break;
            } else if ((j%2) && digit_count[j] && digit_type[i] == DIGIT_ODD) {
                value += j;
                digit_count[j]--;
                break;
            }
        }
    }

    free(digit_type);
    return value; 
}
