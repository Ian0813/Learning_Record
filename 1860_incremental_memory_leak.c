/*
 * =====================================================================================
 *
 *       Filename:  1860_incremental_memory_leak.c
 *
 *    Description:  Incremental memory leak 
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

#define ARRAY_SIZE 3
#define INIT_SECONDS 1

enum {
    CRASH_TIME = 0,
    MEMORY1_INDEX = 1,
    MEMORY2_INDEX = 2,
};

int* memLeak(int memory1, int memory2, int* returnSize) {

    int *result = NULL;
    int seconds = INIT_SECONDS;
    *returnSize = ARRAY_SIZE;

    result = (int *) calloc(ARRAY_SIZE, sizeof(int));

    if (memory1 || memory2) {

        for (seconds = 1; seconds; seconds++) {
     
            if (seconds > memory1 && seconds > memory2) {
                break;
            } else {
                if (memory2 > memory1) {
                    memory2 -= seconds;
                } else {
                    memory1 -= seconds;
                }
            }
        }
    }

    result[CRASH_TIME] = seconds;
    result[MEMORY1_INDEX] = memory1;
    result[MEMORY2_INDEX] = memory2;
    return result;
}

int main(void) {

    int *result = NULL;
    int index = 0;

    result = memLeak(8, 11, &index);

    for (int i = 0; i < index; i++) {
        printf("[%d] %d\n", i, result[i]);
    }

    free(result);
    return EXIT_SUCCESS;
}
