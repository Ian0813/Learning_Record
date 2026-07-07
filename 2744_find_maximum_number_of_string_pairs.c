/*
 * =====================================================================================
 *
 *       Filename:  2744_find_maximum_number_of_string_pairs.c
 *
 *    Description:  find maximum number of string pairs
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

#define PAIR_LEN 2
#define IS_EQUAL(w1, w2) ((w1[0] == w2[1]) && (w1[1] == w2[0])) 

int maximumNumberOfStringPairs(char** words, int wordsSize) {

    int count_pair = 0;

    for (int i = 0; i < wordsSize-1; i++) {
        for (int j = i+1; j < wordsSize; j++) {
            if (i != j && IS_EQUAL(words[i], words[j])) {
                count_pair++;
            }
        }
    }
    return count_pair;
}
