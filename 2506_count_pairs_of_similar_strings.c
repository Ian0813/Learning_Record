/*
 * =====================================================================================
 *
 *       Filename:  2506_count_pairs_of_similar_strings.c
 *
 *    Description:  count pairs of similar strings
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

#define TABLE_SIZE 26
#define CH_TO_INDEX(ch) ((ch)-'a')

struct collection {
    int **counting;
    int *pairs_count;
    int length;
};

static int **allocate_array(int row, int column) {

    int **arr = NULL;

    arr = (int **) calloc(row, sizeof(int *));

    for (int i = 0; i < row; i++) {
        arr[i] = (int *) calloc(column, sizeof(int));
    }

    return arr;
}

static void get_occurrence(int **counting, char **words, int wordsSize) {

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            counting[i][CH_TO_INDEX(words[i][j])] = 1;
        }
    }
    return;
}

static void count_similar(struct collection *info) {

    for (int i = info->length-1; i >= 0; i--) {
        for (int j = i+1; j < info->length; j++) {
            if (!memcmp(info->counting[i], info->counting[j], sizeof(int) * TABLE_SIZE)) {
                info->pairs_count[i]++;
            }
        }
    }

    return;
}

int similarPairs(char** words, int wordsSize) {

    struct collection info = {NULL, .length = 0};
    int count = 0;

    if (wordsSize) {
        info.counting = allocate_array(wordsSize, TABLE_SIZE);
        info.pairs_count = (int *) calloc(wordsSize, sizeof(int));
        info.length = wordsSize;
        get_occurrence(info.counting, words, wordsSize);
        count_similar(&info);

        for (int i = 0; i < wordsSize; i++) {
            count += info.pairs_count[i];
        }
    }
    return count;
}
