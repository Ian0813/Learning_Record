/*
 * =====================================================================================
 *
 *       Filename:  500_keyboard_row.c
 *
 *    Description:  keyboard row
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define ROW_SIZE 3

enum ROW_NUMBER {
    ROW_ONE = 0,
    ROW_TWO = 1,
    ROW_THREE = 2
};

char *keyboard[ROW_SIZE] = { [ROW_ONE] = "qwertyuiop", [ROW_TWO] = "asdfghjkl", [ROW_THREE] = "zxcvbnm"};

bool check_word_in_row(char *word) {

    bool rc = true;
    int no_found = 0;

    for (int i = 0; i < ROW_SIZE; i++) {
        no_found = 0;
        for (int j = 0; j < strlen(word); j++) {
            if (!strchr(keyboard[i], tolower(word[j]))) {
                no_found = 1;
                break;
            }
        }
        if (!no_found)
            break;
    }

    if (no_found)
        rc = false;
    return rc;
}

char** findWords(char** words, int wordsSize, int* returnSize) {

    char **result = NULL;
    int index = 0;

    if (wordsSize) {
        result = (char **) calloc(wordsSize, sizeof(char *));

        for (int i = 0; i < wordsSize; i++) {
            if (check_word_in_row(words[i])) {
                result[index++] = words[i];
            }
        }
        *returnSize = index;
    }
    return result;
}
