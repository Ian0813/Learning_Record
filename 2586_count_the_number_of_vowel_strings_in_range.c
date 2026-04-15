/*
 * =====================================================================================
 *
 *       Filename:  2586_count_the_number_of_vowel_strings_in_range.c
 *
 *    Description:  count the number of vowel strings in range
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

#define IS_VOWEL(ch, vowels, size, rc) for (int i = 0; i < size; i++) if (ch == vowels[i]) rc = true;

typedef enum {false, true} bool;

static bool is_vowel_string(char *s) {

    int slen = 0;
    char vowels[] = "aeiou";
    bool r1 = false, r2 = false;

    slen = strlen(s);

    if (!slen)
        return false;

    IS_VOWEL(s[0], vowels, strlen(vowels), r1);
    IS_VOWEL(s[slen-1], vowels, strlen(vowels), r2);

    return r1 && r2;
}

int vowelStrings(char** words, int wordsSize, int left, int right) {

    int count = 0;

    for (int i = left; i < wordsSize && i <= right; i++) {
        count += (is_vowel_string(words[i]) ? 1 : 0); 
    }

    return count;
}
