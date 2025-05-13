/*
 * =====================================================================================
 *
 *       Filename:  2451_odd_string_difference.c
 *
 *    Description:  odd string difference
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

typedef enum {false, true} bool;

#define MAX_WORDLEN 100

typedef struct interval_recorder {
    int *intervals;
    int *indices;
    int len, index_len;
} recorder_t;

static bool retrieve_interval(recorder_t *record, char *word) {

    bool flag = true;

    if (!record->len) {
        for (int i = 0; i < strlen(word)-1; i++) {
            record->intervals[record->len++] = (word[i+1]-word[i]);
        }
    } else {
        for (int i = 0; i < strlen(word)-1; i++) {
           if (record->intervals[i] != (word[i+1]-word[i])) {
               flag = false;
               break;
           }
        }
    }
    return flag;
}

static int get_diffindex(recorder_t *record, int wordsSize) {

    int diff = 0;

    if (record->index_len == 1) {
        diff = record->indices[0];
    } else {
        for (int i = 0; i < wordsSize; i++) {
            if (record->indices[i] != i) {
                diff = i;
                break;
            }
        }
    }
    return diff;
}

char* oddString(char** words, int wordsSize) {

    recorder_t record = {0};
    int diff_index = 0;

    if (wordsSize) {

        record.intervals = (int *) calloc(MAX_WORDLEN, sizeof(int));
        record.indices = (int *) calloc(wordsSize, sizeof(int));

        for (int i = 0; i < wordsSize; i++) {
            if (retrieve_interval(&record, words[i])) {
                record.indices[record.index_len++] = i;
            }
        }

        diff_index = get_diffindex(&record, wordsSize);
        printf("[%s] diff index: %d\n", __func__, diff_index);

        for (int i = 0; i < record.index_len; i++) {
            printf("%d ", record.indices[i]);
        }

        putchar('\n');
        free(record.intervals);
        free(record.indices);
    }
    return words[diff_index];
}
