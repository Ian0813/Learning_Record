/*
 * =====================================================================================
 *
 *       Filename:  3775_reverse_words_with_same_vowel_count.c
 *
 *    Description:  reverse words with same vowel count
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

static int count_vowel(char *s, int slen) {

    int table[ALPHABET_SIZE] = {0}, vlen = 5, count = 0;
    char *vowels = "aeiou";

    for (int i = 0; i < slen; i++) {
        table[CH_TO_INDEX(s[i])]++;
    }

    for (int i = 0; i < vlen; i++) {
        count += table[CH_TO_INDEX(vowels[i])];
    }

    return count;
}

static void reverse(char *s, int len) {

    char temp = '\0';

    for (int i = 0, j = len-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    return;
}

char* reverseWords(char* s) {

    char *ptr = NULL, *save = strdup(s);
    int std_count = 0, count = 0, len = 0; 

    memset(save, 0, strlen(s)+1);
    ptr = strtok(s, " ");
    strcat(save, ptr);
    std_count = count_vowel(ptr, strlen(ptr));

    while ((ptr = strtok(NULL, " "))) {

        len = strlen(ptr);

        if (std_count == count_vowel(ptr, len)) {
            reverse(ptr, len); 
        }

        strcat(save, " ");
        strcat(save, ptr);
    }

    return save;
}
