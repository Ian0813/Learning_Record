/*
 * =====================================================================================
 *
 *       Filename:  3324_find_the_sequence_of_strings_appeared_on_the_screen.c
 *
 *    Description:  find the sequence of strings appeared on the screen
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

#define ARR_SIZE 10500
#define ARR_LENGTH 401
#define INIT_CHAR 'a'

struct str_series {
    char **strs;
    int index;
    int size;
};

typedef enum {
    KEY_ONE = 0,
    KEY_TWO = 1,
} key_action_t;

static void traverse_sequence(struct str_series *result, char *target, int tindex, key_action_t action) {

    if (action == KEY_ONE) {
        result->strs[result->size][result->index] = INIT_CHAR;
    } else if (action == KEY_TWO) {
        result->strs[result->size][result->index]++;
    }

    if (!strcmp(result->strs[result->size++], target)) {
        return;
    }

    result->strs[result->size] = (char *) calloc(ARR_LENGTH, sizeof(char));
    strcpy(result->strs[result->size], result->strs[result->size-1]);

    if (result->strs[result->size-1][result->index] == target[tindex]) {
        result->index++;
        traverse_sequence(result, target, tindex+1, KEY_ONE);
    } else {
        traverse_sequence(result, target, tindex, KEY_TWO);
    }
    return;
}

static char **alloc_result(struct str_series *result) {

    char **final_result = NULL;

    if (result) {
        final_result = (char **) calloc(result->size, sizeof(char *));

        for (int i = 0; i < result->size; i++) {
            final_result[i] = strdup(result->strs[i]);
        }
    }
    return final_result;
}

char** stringSequence(char* target, int* returnSize) {

    struct str_series result = {.strs = NULL, .index = 0, .size = 0};
    char **final_result = NULL;

    if (target) {
        result.strs = (char **) calloc(ARR_SIZE, sizeof(char *));
        result.strs[result.size] = (char *) calloc(ARR_LENGTH, sizeof(char));
        traverse_sequence(&result, target, 0, KEY_ONE);
    }
    *returnSize = result.size;
    return result.strs;
}
