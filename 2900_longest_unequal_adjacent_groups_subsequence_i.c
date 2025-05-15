/*
 * =====================================================================================
 *
 *       Filename:  2900_longest_unequal_adjacent_groups_subsequence_i.c
 *
 *    Description:  longest unequal adjacent groups subsequence i
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
struct subsequence {
    char **strs;
    int len;
};

static void greedy_counter(int *count, int *groups, int groupsSize) {

    int max = 0;

    if (!count)
        return;

    for (int i = 1; i < groupsSize; i++) {
        if (groups[i] != groups[i-1]) {
            count[i] = max + 1;
            if (count[i] > max) {
                max = count[i];
            }
        }
    }
    return;
}

static int get_max_index(int *count, int size) {

    int max = 0, mindex = 0;

    for (int i = 0; i < size; i++) {
        if (max < count[i]) {
            max = count[i];
            mindex = i;
        }
    }
    return mindex;
}

static void reverse(char **strs, int size) {

    char *temp = NULL;

    for (int i = 0, j = size-1; i < j; i++, j--) {
        temp = strs[i];
        strs[i] = strs[j];
        strs[j] = temp;
    }
    return;
}

static void reform_subsequence(struct subsequence *result, int mindex, char **words, int *count, int size) {

    int i = mindex;

    for (i = mindex; i > 0; i--) {
        if (count[i]) {
            result->strs[result->len] = strdup(words[i]);
            result->len++;
        }
    }

    result->strs[result->len] = strdup(words[i]);
    result->len++;
    reverse(result->strs, result->len);
    return;
}

char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {

    int *count = NULL, size = 0, mindex = 0;
    struct subsequence result = {.strs = NULL, .len = 0};

    result.strs = (char **) calloc(groupsSize, sizeof(char *));

    if (groupsSize > 1) {

        count = (int *) calloc(groupsSize, sizeof(int));
        memset(count, 0, sizeof(int));

        greedy_counter(count, groups, groupsSize);
        mindex = get_max_index(count, groupsSize);
        reform_subsequence(&result, mindex, words, count, groupsSize);
    } else {
        result.strs[0] = strdup(words[0]);
        result.len++;
    }

    free(count);
    *returnSize = result.len;
    return result.strs;
}
