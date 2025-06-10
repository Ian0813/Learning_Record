/*
 * =====================================================================================
 *
 *       Filename:  386_lexicographical_numbers.c
 *
 *    Description:  lexicographical numbers
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

#define UNIT 10

static void recursive(int *result, int value, int target, int *index) {

    if (value <= target) {

        result[*index] = value;
        *index += 1;

        recursive(result, value*UNIT, target, index);

        if ((value+1)%10) {
            recursive(result, value+1, target, index);
        }
    }
    return;
}

int* lexicalOrder(int n, int* returnSize) {

    int *result = NULL, rindex = 0;

    result = (int *) calloc(n, sizeof(int));

    recursive(result, 1, n, &rindex);
    *returnSize = n;

    return result;
}

int main(int argc, char *argv[]) {

    int size = 0, *result = NULL; 
    int n = 0;

    if (argc > 1)
        n = atoi(argv[1]);
    else
        n = 13;

    result = lexicalOrder(n, &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    putchar('\n');

    free(result);
    return EXIT_SUCCESS;
}
