/*
 * =====================================================================================
 *
 *       Filename:  1409_queries_on_a_permutation_with_key.c
 *
 *    Description:  queries on a permutation with key
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

static void fill_permutation(int **permutation, int m) {

    *permutation = (int *) calloc(m, sizeof(int));

    for (int i = 0; i < m; i++) {
        (*permutation)[i] = i+1; 
    }
    return;
}

static int get_index(int *permutation, int m, int query) {

    int index = 0; 

    for (int i = 0; i < m; i++) {
        if (permutation[i] == query) {
            index = i;
            break;
        }
    }

    memmove(permutation+1, permutation, index*sizeof(int));
    permutation[0] = query;
    return index;
}

int* processQueries(int* queries, int queriesSize, int m, int* returnSize) {

    int *ans = NULL, index = 0;
    int *permutation = NULL;

    if (queriesSize) {
        fill_permutation(&permutation, m);
        ans = (int *) calloc(queriesSize, sizeof(int));

        for (int i = 0; i < queriesSize; i++) {
            ans[index++] = get_index(permutation, m, queries[i]);
        }
    }

    *returnSize = queriesSize;
    return ans;
}
