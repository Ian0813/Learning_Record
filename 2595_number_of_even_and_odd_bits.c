/*
 * =====================================================================================
 *
 *       Filename:  2595_number_of_even_and_odd_bits.c
 *
 *    Description:  number of even and odd bits
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

#define RESULT_SIZE 2

static void get_binary(int n, char *binary, int *index) {

    while (n) {
        binary[(*index)++] = n%2;
        n /= 2;
    }
    return;
}

int* evenOddBit(int n, int* returnSize) {

    int *result = (int *) calloc(RESULT_SIZE, sizeof(int)), index = 0;
    char binary[BUFSIZ] = {0};

    get_binary(n, binary, &index);

    for (int i = index-1; i >= 0; i--) {
        if (binary[i]) {
            result[(i)%2]++;
        }
    }

    *returnSize = RESULT_SIZE;
    return result;
}

int main(void) {

    int *result = NULL;
    int size = 0;

    result = evenOddBit(50, &size);

    printf("%d, %d\n", result[0], result[1]);

    free(result);

    return EXIT_SUCCESS;
}
