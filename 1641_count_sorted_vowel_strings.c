/*
 * =====================================================================================
 *
 *       Filename:  1641_count_sorted_vowel_strings.c
 *
 *    Description:  count sorted vowel strings
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

#define VOWELS_STR "aeiou"
#define VOWELS_STR_LEN  5 
#define AMOUNT_ARR_SIZE 5

static int get_vowel_index(char vowel) {

    switch (vowel) {
        case 'a':
            return 0;
        case 'e':
            return 1;
        case 'i':
            return 2;
        case 'o':
            return 3;
        case 'u':
            return 4;
        default:
            break;
    }
    return -1;
}

static void recursive_count(int start, int n, int *count, int index, int *amount_arr) {

    if (start < n) {
        for (int i = index; i < VOWELS_STR_LEN; i++) {
            recursive_count(start+1, n, count, get_vowel_index(VOWELS_STR[i]), amount_arr);
        }
    } else if (start == n) {
        for (int i = index; i < VOWELS_STR_LEN; i++)
            *count += amount_arr[i];
    }
    return;
}

int countVowelStrings(int n) {

    int amount_arr[AMOUNT_ARR_SIZE] = {5, 4, 3, 2, 1};
    int count = 0;

    if (n == 1)
        return VOWELS_STR_LEN;

    recursive_count(2, n, &count, 0, amount_arr);

    return count;
}
