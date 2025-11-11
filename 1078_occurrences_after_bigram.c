/*
 * =====================================================================================
 *
 *       Filename:  1078 occurrences after bigram.c
 *
 *    Description:  occurrences after bigram
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

typedef enum {false, true} bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define PRE_WORDS_LEN 2

typedef enum {
    F_INDEX = 0,
    S_INDEX = 1,
} WORDS_INDEX;

typedef struct words_prefix {
    char *first;
    char *second;
} word_prefix;

static void collect_third(char *text, char **result, int *len, word_prefix *prefix) {

    char *ptr = NULL, temp[PRE_WORDS_LEN][BUFSIZ] = {0};

    ptr = strtok(text, " ");
    memcpy(temp[F_INDEX], ptr, strlen(ptr));
    ptr = strtok(NULL, " ");

    while (ptr) {

        memset(temp[S_INDEX], 0, strlen(temp[S_INDEX])); 
        memcpy(temp[S_INDEX], ptr, strlen(ptr));

        ptr = strtok(NULL, " ");

        if (!ptr)  
            break;

        if (!strcmp(temp[F_INDEX], prefix->first) && !strcmp(temp[S_INDEX], prefix->second)) {
            result[*len] = strdup(ptr); 
            *len += 1;
        }

        memset(temp[F_INDEX], 0, strlen(temp[F_INDEX])); 
        memcpy(temp[F_INDEX], temp[S_INDEX], strlen(temp[S_INDEX]));
    }

    return;
}

char** findOcurrences(char* text, char* first, char* second, int* returnSize) {

    char **result = NULL;
    word_prefix prefix = {.first = first, .second = second};
    int len = 0;

    result = (char **) calloc(BUFSIZ, sizeof(char *));

    collect_third(text, result, &len, &prefix);

    *returnSize = len;
    
    return result;
}
