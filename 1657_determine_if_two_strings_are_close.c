/*
 * =====================================================================================
 *
 *       Filename:  1657_determine_if_two_strings_are_close.c
 *
 *    Description:  determine if two strings are close
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

typedef enum {false, true} bool;

#define TABLE_SIZE 26
#define CH_TO_INDEX(ch) ((ch) - 'a')

static void count_occurrence(char *s, int slen, int *table) {

    for (int i = 0; i < slen; i++) {
        table[CH_TO_INDEX(s[i])]++;
    }
    return;
}

static int compar(const void *v1, const void *v2) {
    return *(int *) v1 > *(int *) v2;
}

static bool check_close(int *w1_count, int *w2_count) {

    int *w1_set = NULL, w1_size = 0; 
    int *w2_set = NULL, w2_size = 0; 
    bool rc = true; 

    w1_set = (int *) calloc(TABLE_SIZE, sizeof(int));
    w2_set = (int *) calloc(TABLE_SIZE, sizeof(int));

    for (int i = 0; i < TABLE_SIZE; i++) {

        if (w1_count[i]) {
            w1_set[w1_size++] = w1_count[i];
        }

        if (w2_count[i]) {
            w2_set[w2_size++] = w2_count[i];
        }

        if (w1_count[i] && !w2_count[i]) {
            rc = false;
            goto EXIT;
        }

        if (!w1_count[i] && w2_count[i]) {
            rc = false;
            goto EXIT;
        }
    }

    qsort(w1_set, w1_size, sizeof(int), compar);
    qsort(w2_set, w2_size, sizeof(int), compar);

    for (int i = 0; i < w1_size; i++) {
        if (w1_set[i] != w2_set[i]) {
            rc = false;
            goto EXIT;
        }
    }

EXIT:;
    free(w1_set);
    free(w2_set);
    return rc;
}    

bool closeStrings(char* word1, char* word2) {

    int w1_count[TABLE_SIZE] = {0}, w2_count[TABLE_SIZE] = {0}; 
    int w1_len = 0, w2_len = 0;

    w1_len = strlen(word1);
    w2_len = strlen(word2);

    count_occurrence(word1, w1_len, w1_count);
    count_occurrence(word2, w2_len, w2_count);

    return strlen(word1) == strlen(word2) && check_close(w1_count, w2_count);
}

