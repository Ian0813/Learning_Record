/*
 * =====================================================================================
 *
 *       Filename:  1456_maximum_number_of_vowels_in_a_substring_of_given_length.c
 *
 *    Description:  maximum number of vowels in a substring of given length
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

#define ALPHA_SIZE 26
#define VOWELS_LEN 5
#define ALPHA_TO_INDEX(ch) ((ch) - 'a')
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int get_vowels_count(int *table) {

    char vowels[] = "aeiou";
    int count = 0, vlen = 0;

    if (!table)
        return count;

    for (int i = 0; i < VOWELS_LEN; i++) {
        count += table[ALPHA_TO_INDEX(vowels[i])];
    }
    return count;
}

int maxVowels(char* s, int k) {

    int table[ALPHA_SIZE] = {0}; 
    int len = 0, curlen = 0, max = INT_MIN;

    len = strlen(s);

    for (int i = 0; i < len; i++) {

        if (curlen < k) {
            table[ALPHA_TO_INDEX(s[i])]++; 
            curlen++;
        }

        if (curlen == k) {
            max = MAX(max, get_vowels_count(table));
            table[ALPHA_TO_INDEX(s[(i+1)-k])]--;
            curlen--;
        }
    }
    return max;
}
