/*
 * =====================================================================================
 *
 *       Filename:  17_letter_combinations_of_a_phone_number.c
 *
 *    Description:  Letter combination of a phone number  
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

#define DIGIT_TO_INDEX(digit) (digit-'2')

#define GET_ROW_SIZE(digits, combo, size) \
    for (int i = 0; i < strlen(digits); i++) size *= strlen(combo[DIGIT_TO_INDEX(digits[i])]);\

enum {
    BUTTON_TWO = 0,
    BUTTON_THREE = 1,
    BUTTON_FOUR,
    BUTTON_FIVE,
    BUTTON_SIX,
    BUTTON_SEVEN,
    BUTTON_EIGHT,
    BUTTON_NINE,
};
const char *combo[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 

static char **alloc_result(char **result, int row_size, int length) {

    result = (char **) calloc(row_size, sizeof(char *));

    for (int i = 0; i < row_size; i++) {
        result[i] = (char *) calloc(length+1, sizeof(char));
    }
    return result;
}

static void append(const char *pattern, int units, char **result, int row_index, int row_size) {

    if (strlen(pattern)) {
        for (int i = 0; i < strlen(pattern); i++) {
            for (int j = 0; j < units; j++) {
                result[row_index][strlen(result[row_index])] = pattern[i]; 
                row_index++;
            }
        }
        if (row_index < row_size) {
            append(pattern, units, result, row_index, row_size); 
        }
    }
    return;
}

static void collect(char *digits, int digit_index, char **result, int row_size, int units) {


    if (strlen(digits)) {
        units *= ((int) strlen(combo[DIGIT_TO_INDEX(digits[digit_index])]));
        append(combo[DIGIT_TO_INDEX(digits[digit_index])], row_size/units, result, 0, row_size);
        digit_index += 1;

        if (digit_index < strlen(digits)) {
            collect(digits, digit_index, result, row_size, units);
        }
    }
    return;
}    

char** letterCombinations(char* digits, int* returnSize) {

    char **result = NULL;
    int row_size = 1;

    if (strlen(digits)) {
        GET_ROW_SIZE(digits, combo, row_size);
        result = alloc_result(result, row_size, strlen(digits));
        collect(digits, 0, result, row_size, 1);
    } else {
        row_size = 0;
    }    
    *returnSize = row_size;

    return result;
}

int main(void) {

    char **result = NULL;
    char digits[] = "9387";
    int size = 0;

    result = letterCombinations(digits, &size);
    if (result) {
        printf("result allocated.\n");

        for (int i = 0; i < size; i++) {
            printf("[%d] %s ", i, result[i]);
        }

        for (int i = 0; i < size; i++) 
            free(result[i]);
        free(result);
    }
    return EXIT_SUCCESS;
}
