/*
 * =====================================================================================
 *
 *       Filename:  1324_print_words_vertically.c
 *
 *    Description:  print words vertically
 *
 *       Compiler:  gcc
 *
 *         Author:  Ian
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef enum {false, true} bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static void get_matrix_size(char *dup, int *rsize, int *csize) {

    char *ptr = NULL;
    int len = 0;

    ptr = strtok(dup, " ");

    if (ptr) {

        do {
            *rsize += 1;
            len = strlen(ptr);
            *csize = *csize > len ? *csize : len;
            ptr = strtok(NULL, " ");
        } while (ptr);
        free(dup);
    }
    return;
}

static char **matrix_allocate(int rsize, int csize) {

    if (!rsize || !csize)
        return NULL;

    char **ptr = NULL;

    ptr = calloc(rsize, sizeof(char *));

    for (int i = 0; ptr && i < rsize; i++) {
        ptr[i] = calloc(csize+1, sizeof(char));
    }
    return ptr;
}

static void matrix_show(char **matrix, int rsize, int csize) {

    if (!matrix || !rsize || !csize)
        return;

    for (int i = 0; i < rsize; i++) {
        printf("%s\n", matrix[i]);
    }
    return;
}

static void matrix_free(char **matrix, int rsize) {

    if (!matrix || !rsize)
        return;

    for (int i = 0; i < rsize; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return;
}

static bool matrix_to_vertical(char **matrix, int rsize, int csize, char **result, int *rrsize, int *rcsize) {

    if (!matrix || !result || !rsize || !csize)
        return false;

    int last_pos = 0; 

    for (int i = 0; i < csize; i++) {
        *rcsize = 0; 
        for (int j = 0; j < rsize; j++) {

            if (!isspace(matrix[j][i])) {
                last_pos = j; 
            }
            result[*rrsize][*rcsize] = matrix[j][i];
            *rcsize += 1;
        }
        result[*rrsize][last_pos+1] = '\0';
        *rrsize += 1;
    }
     
    return true;
}

static bool get_content(char **matrix, char *content, int rsize, int csize) {

    char *ptr = NULL;
    int slen = 0, index = 0;

    if (!matrix || !content || !rsize || !csize)
        return false;

    ptr = strtok(content, " ");

    if (ptr) {
        do {
            slen = strlen(ptr);
            for (int i = 0; i < csize; i++) {
                if (i < slen) {
                    matrix[index][i] = ptr[i];
                } else {
                    matrix[index][i] = ' '; 
                }
            }
            index++;
            ptr = strtok(NULL, " ");
        } while (ptr);
    }

    return true;
}

char ** printVertically(char * s, int* returnSize){

    int rsize = 0, csize = 0, rrsize = 0, rcsize = 0;
    char **matrix = NULL, **result = NULL;

    if (s) {

        get_matrix_size(strdup(s), &rsize, &csize);

        if (rsize && csize) {
            matrix = matrix_allocate(rsize, csize);
            get_content(matrix, s, rsize, csize);

            result = matrix_allocate(csize, rsize);
            matrix_to_vertical(matrix, rsize, csize, result, &rrsize, &rcsize);
            matrix_free(matrix, rsize);
        }
    }

    *returnSize = rrsize;
    return result;
}
