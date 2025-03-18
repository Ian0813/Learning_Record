/*
 * =====================================================================================
 *
 *       Filename:  2062_count_vowel_substrings_of_a_string.c
 *
 *    Description:  count vowel substrings of a string
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

#define VOWEL_LEN 5
#define IS_VOWELS(table) (table[VOWEL_A]&&table[VOWEL_E]&&table[VOWEL_I]&&table[VOWEL_O]&&table[VOWEL_U])
#define IS_VOWEL(ch) ((ch) == 'a' || (ch) == 'e' || (ch) == 'i' || (ch) == 'o' || (ch) == 'u')

typedef enum {
    VOWEL_A = 0,
    VOWEL_E = 1,
    VOWEL_I = 2,
    VOWEL_O = 3,
    VOWEL_U = 4
} vowel_type_t;

static inline void table_control(int *table, unsigned int ch, int count) {
    switch (ch) {
        case 'a': {
            table[VOWEL_A] += count;
            break;
        };
        case 'e': {
            table[VOWEL_E] += count;
            break;
        };
        case 'i': {
            table[VOWEL_I] += count;
            break;
        };
        case 'o': {
            table[VOWEL_O] += count;
            break;
        };
        case 'u': {
            table[VOWEL_U] += count;
            break;
        };
        default:
            break;
    }
    return;
}

static void check_vowels(char *word, int start, int *table, int *count) {

    memset(table, 0, VOWEL_LEN*sizeof(int));

    for (int i = start; i < strlen(word); i++) {

        table_control(table, word[i], 1);

        if (!IS_VOWEL(word[i])) {
            break;
        }

        if (IS_VOWELS(table) && IS_VOWEL(word[i])) {
            *count += 1;
        }
    }
    return;
}

int countVowelSubstrings(char* word) {

    int table[VOWEL_LEN] = {0};
    int count = 0;

    for (int i = 0; i < strlen(word); i++) {
        if (!IS_VOWEL(word[i]))
            continue;
        check_vowels(word, i, table, &count);
        table_control(table, word[i], -1);
    }
    return count;
}
