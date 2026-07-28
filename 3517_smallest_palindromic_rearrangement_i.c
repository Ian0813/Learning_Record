/*
 * =====================================================================================
 *
 *       Filename:  3517_smallest_palindromic_rearrangement_i.c
 *
 *    Description:  smallest palindromic rearrangement i
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

#define ALPHABET_SIZE 26
#define CH_TO_INDEX(ch) ((ch)-'a')
#define VAL_TO_CH(val) ((val)+'a')

static void count_occurrence(char *s, int slen, int *table) {

    for (int i = 0; i < slen; i++) {
        table[CH_TO_INDEX(s[i])]++; 
    }
    return;
}

char* smallestPalindrome(char* s) {

    int count_table[ALPHABET_SIZE] = {0};
    int slen = strlen(s), front = 0, tail = 0; 
    char *result = NULL, single_ch = '\0';

    result = calloc(slen + 1, sizeof(*s));
    count_occurrence(s, slen, count_table);
    tail = slen-1;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        while (count_table[i] >= 2) {
            result[front++] = VAL_TO_CH(i); 
            result[tail--] = VAL_TO_CH(i); 
            count_table[i] -= 2;
        }

        if (count_table[i] == 1) {
            single_ch = VAL_TO_CH(i);
            count_table[i] -= 1;
        }
    }

    if (slen%2) {
        result[slen/2] = single_ch;
    }
    return result;
}
