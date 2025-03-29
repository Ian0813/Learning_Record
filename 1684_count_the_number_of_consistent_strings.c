/*
 * =====================================================================================
 *
 *       Filename:  1684_count_the_number_of_consistent_strings.c
 *
 *    Description:  count the number of consistent strings
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

#define ALPHABET_SIZE 26

#define CH_TO_INDEX(ch) ((ch)-'a')

int countConsistentStrings(char * allowed, char ** words, int wordsSize){

    int alphabet_table[ALPHABET_SIZE] = {0};
    int count = 0;

    for (int i = 0; i < strlen(allowed); i++) {
        alphabet_table[CH_TO_INDEX(allowed[i])] = 1;
    }

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            if (!alphabet_table[CH_TO_INDEX(words[i][j])]) {
                goto SKIP_COUNT;
            }
        }
        count++;
SKIP_COUNT:;
    }
    return count;
}
