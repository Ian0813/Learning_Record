/*
 * =====================================================================================
 *
 *       Filename:  1002_find_common_characters.c
 *
 *    Description:  find common characters
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
#include <stdint.h>
#include <limits.h>

typedef enum {false, true} bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define CH_TO_INT(ch) ((ch) - 'a')
#define INT_TO_CH(val) ((val) + 'a')
#define ALPHABET_SIZE 26

static void count_occurrence(char **words, int wordsSize, uint8_t **table) {

    int len = 0;

    for (int i = 0; i < wordsSize; i++) {

        len = strlen(words[i]);

        while (len--) {
            table[i][CH_TO_INT(words[i][len])]++;
        }
    }

    return;
}

static uint8_t **table_allocate(int row, int column) {

    uint8_t **ptr = NULL;

    ptr = (uint8_t **) calloc(row, sizeof(uint8_t *));

    if (!ptr)
        return ptr;

    for (int i = 0; i < row; i++) {
        ptr[i] = (uint8_t *) calloc(column, sizeof(uint8_t));    
    }

    return ptr;
}

static void table_free(uint8_t **ptr, int row) {

    if (!ptr)
        return;

    for (int i = 0; i < row; i++) {
        free(ptr[i]);
    }

    free(ptr); 
    return;
}

char** commonChars(char** words, int wordsSize, int* returnSize) {

    uint8_t **counter = NULL, temp[2] = {0};
    int minimum = INT_MAX, index = 0, rlen = 0;
    bool is_common = true;
    char **result = NULL;

    counter = table_allocate(wordsSize, ALPHABET_SIZE);
    count_occurrence(words, wordsSize, counter);
    result = (char **) calloc(BUFSIZ, sizeof(char *));

    for (int i = 0; i < ALPHABET_SIZE; i++) {

        for (int j = 0; j < wordsSize; j++) {
            if (!counter[j][i]) {
                is_common = false; 
                break;
            } else {
                minimum = minimum > counter[j][i] ? counter[j][i] : minimum;    
            }
        }

        if (is_common) {
            temp[0] = INT_TO_CH(i);
            for (int k = 0; k < minimum; k++)
                result[rlen++] = strdup((char *) temp);
        }

        is_common = true;
        minimum = INT_MAX;
    }

    *returnSize = rlen;
    table_free(counter, wordsSize);

    return result;
}

