/*
 * =====================================================================================
 *
 *       Filename:  821_shortest_distance_to_a_character.c
 *
 *    Description:  Shortest distance to a character  
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
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define GET_ABS(val) (val < 0 ? -val : val)

int count_distance(int *target_indices, int size, int ch_index) {

    int minimum = INT_BUFSIZ;

    for (int i = 0; i < size; i++) {
        if (minimum > GET_ABS((target_indices[i]-ch_index))) {
            minimum = GET_ABS((target_indices[i]-ch_index));
        }
    }

    return minimum;
}

int* shortestToChar(char* s, char c, int* returnSize) {

    int target_indices[BUFSIZ], tindex = 0, index = 0;
    int *result = (int *) malloc(strlen(s) * sizeof(int));

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c) {
            target_indices[tindex++] = i;
        }
    }

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == c) {
            result[index++] = 0;
        } else {
            result[index++] = count_distance(target_indices, tindex, i);
        }
    }

    *returnSize = index;
    return result;
}

