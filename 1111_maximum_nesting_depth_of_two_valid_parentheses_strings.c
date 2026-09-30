/*
 * =====================================================================================
 *
 *       Filename:  1111_maximum_nesting_depth_of_two_valid_parentheses_strings.c
 *
 *    Description:  maximum nesting depth of two valid parentheses strings
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char* seq, int* returnSize) {

    int *result = NULL, seqlen = 0, depth = 0, index = 0;

    if (seq) {

        seqlen = strlen(seq);
        *returnSize = seqlen;
        result = calloc(seqlen, sizeof(int));

        for (int i = 0; i < seqlen; i++) {

            if (seq[i] == '(') {
                depth++;
            }

            result[index++] = (depth % 2);

            if (seq[i] == ')') {
                depth--;
            }
        }
    }
    return result;
}
