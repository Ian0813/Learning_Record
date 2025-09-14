/*
 * =====================================================================================
 *
 *       Filename:  3541_find_most_frequent_vowel_and_consonant.c
 *
 *    Description:  find most frequent vowel and consonant
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
#include <ctype.h>

#define CH_TO_INDEX(ch) ((ch) - 'a')
#define ALPHABET_SIZE 26
#define isvowel(ch) ((ch) == 'a' || (ch) == 'e' || (ch) == 'i' || (ch) == 'o' || (ch) == 'u')

typedef enum {
    LETTER_VOWEL = 0,
    LETTER_CONSONANT = 1,
    LETTER_TYPE_LEN = 2
} letter_type;

struct letter_class {
    int freq; 
    letter_type type; 
};

static void classify(char *s, struct letter_class *table) {

    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        table[CH_TO_INDEX(s[i])].freq++;
        table[CH_TO_INDEX(s[i])].type = isvowel(s[i]) ? LETTER_VOWEL : LETTER_CONSONANT;
    }

    return;
}

static int get_freq_bytype(struct letter_class *table, letter_type type) {

    int max = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (table[i].type == type) {
            max = max < table[i].freq ? table[i].freq : max;
        }
    }

    return max;
}

int maxFreqSum(char* s) {

    struct letter_class table[ALPHABET_SIZE] = {0};
    int max_vowel = 0, max_consonant = 0;  

    classify(s, table);
    max_vowel = get_freq_bytype(table, LETTER_VOWEL);
    max_consonant = get_freq_bytype(table, LETTER_CONSONANT);

    return max_vowel + max_consonant;
}
