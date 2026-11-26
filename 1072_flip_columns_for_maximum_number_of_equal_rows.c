/*
 * =====================================================================================
 *
 *       Filename:  1072_flip_columns_for_maximum_number_of_equal_rows.c
 *
 *    Description:  1072 flip columns for maximum number of equal rows
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
#include <stdbool.h>
#include <stdint.h>
#include <uthash.h>
#include <sys/param.h>

#define BUFLEN 1024

typedef struct {
    char **patterns;
    uint32_t *pattern_count; 
    uint32_t pattern_size;
} pattern_storage;

typedef struct pattern_rec {
    char str[BUFLEN];
    UT_hash_handle hh;
} pattern_rec;

static bool patterns_storage_init(pattern_storage *obj, uint32_t size) {

    if (size <= 0 || !obj)
        return false;

    obj->patterns = calloc(size, sizeof(char *));
    obj->pattern_count = calloc(size, sizeof(uint32_t));
    obj->pattern_size = size;

    return true;
}

static bool patterns_storage_inc(pattern_storage *obj, char *pattern) {

    int index = 0;

    if (!obj || !pattern)
        return false;

    for (index = 0; index < obj->pattern_size; index++) {
        if (!obj->patterns[index])
            break; 

        if (!strcmp(obj->patterns[index], pattern))
            break;
    }

    if (!obj->patterns[index]) {
        obj->patterns[index] = strdup(pattern);    
    }
    obj->pattern_count[index]++;

    return true;
}

static int patterns_storage_get_maxcount(pattern_storage *obj) {

    int max_count = 0;    

    for (int i = 0; i < obj->pattern_size; i++) {
        if (!obj->patterns[i])   
            break; 
        max_count = MAX(obj->pattern_count[i], max_count);
    }
    return max_count;
}

static void patterns_storage_free(pattern_storage *obj) {

    for (int i = 0; i < obj->pattern_size; i++) {
        if (!obj->patterns[i])   
            break; 
        free(obj->patterns[i]);        
        obj->patterns[i] = NULL;
    }
    return; 
}

int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize) {

    pattern_storage plist = {0};
    char pattern[BUFSIZ] = {0}, last = '\0';
    int pindex = 0, max_equal_row = 0;

    patterns_storage_init(&plist, matrixSize);

    for (int i = 0; i < matrixSize; i++) {

        pattern[pindex++] = '*';
        last = matrix[i][0];

        for (int j = 1; j < matrixColSize[i]; j++) {
            if (matrix[i][j] != last) {
                last = matrix[i][j];
                pattern[pindex++] = '|';
            }
            pattern[pindex++] = '*';
        }

        patterns_storage_inc(&plist, pattern);
        memset(pattern, 0, pindex);
        pindex = 0;
    }

    max_equal_row = patterns_storage_get_maxcount(&plist);
    patterns_storage_free(&plist);

    return max_equal_row;
}
