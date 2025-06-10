/*
 * =====================================================================================
 *
 *       Filename:  3442_maximum_difference_between_even_and_odd_frequency_i.c
 *
 *    Description:  maximum difference between even and odd frequency i
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

#define TABLE_SIZE 26
#define CH_TO_INDEX(ch) ((ch)-'a')

static void count_occurrences(char *s, int *count_table) {

    for (int i = 0; i < strlen(s); i++) {
        count_table[CH_TO_INDEX(s[i])]++;
    }
    return;
}

int maxDifference(char* s) {

    int max_odd = 0, min_even = INT_MAX;
    int count_table[TABLE_SIZE] = {0}, diff = 0;

    count_occurrences(s, count_table);

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!count_table[i])
            continue;

        if (count_table[i]%2) {
            max_odd = max_odd > count_table[i] ? max_odd : count_table[i];
        } else {
            min_even = min_even > count_table[i] ? count_table[i] : min_even;
        }
    }

    diff = max_odd - min_even;
    return diff;
}
