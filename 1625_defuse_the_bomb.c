/*
 * =====================================================================================
 *
 *       Filename:  1625_defuse_the_bomb.c
 *
 *    Description:  Defuse the bomb  
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

#define NEGATIVE_TO_INDEX(val, codeSize) (val < 0 ? (codeSize+val) : (val%codeSize))

int get_decode(int *code, int codeSize, int k, int cur) {

    int decode = 0;

    if (k > 0) {
        for (int i = 1; i <= k; i++) {
            decode += code[(cur+i)%codeSize];
        }
    } else {
        k = -k;
        for (int i = 1; i <= k; i++) {
            decode += code[NEGATIVE_TO_INDEX((cur-i), codeSize)];
        }
    }
    return decode;
}

int* decrypt(int* code, int codeSize, int k, int* returnSize) {

    int *result = (int *) calloc(codeSize, sizeof(int));
    int index = 0;

    *returnSize = codeSize;
    result[index] = get_decode(code, codeSize, k, index);
    index++;

    if (k > 0) {
        for (index; index < codeSize; index++) {
            //fprintf(stdout, "[%s] %d, %d, %d\n", __func__, result[index-1], code[index-1], code[((index)+k)%codeSize]);
            result[index] = result[index-1] - code[index] + code[((index)+k)%codeSize];
        }
        
    } else if (k < 0) {
        for (index; index < codeSize; index++) {
            //fprintf(stdout, "[%s] %d, %d, %d\n", __func__, result[index-1], code[NEGATIVE_TO_INDEX(((index-1)-(-k)), codeSize)], code[index-1]);
            result[index] = result[index-1] - code[NEGATIVE_TO_INDEX(((index-1)-(-k)), codeSize)] + code[index-1];
        }
    }
    return result;
}

int main(void) {

    int code[] = {2, 4, 9, 3}, k = -2;
    int size = 0;

    int *result = decrypt(code, 4, -2, &size);

    for (int i = 0; i < size; i++) {
        fprintf(stdout, "%d ", result[i]);
    }
    printf("\n");

    free(result);

    return EXIT_SUCCESS;
}
