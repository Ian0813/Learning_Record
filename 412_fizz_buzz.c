/*
 * =====================================================================================
 *
 *       Filename:  412_fizz_buzz.c
 *
 *    Description:  fizz buzz
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

#define FIZZ "Fizz"
#define BUZZ "Buzz"

#define DIGIT_LEN 4

#define DIVISIBLE_BY_3(val) (!((val)%3))
#define DIVISIBLE_BY_5(val) (!((val)%5))

struct result_info {
    char **strs;
    int index;
};

static void form_result(struct result_info *result, int value) {

    char digits[DIGIT_LEN+1] = {0};

    if (DIVISIBLE_BY_3(value) && DIVISIBLE_BY_5(value)) {
        result->strs[result->index] = strdup(FIZZ BUZZ);
    } else if (DIVISIBLE_BY_3(value)) {
        result->strs[result->index] = strdup(FIZZ); 
    } else if (DIVISIBLE_BY_5(value)) {
        result->strs[result->index] = strdup(BUZZ); 
    } else {
        sprintf(digits, "%d", value);
        result->strs[result->index] = strdup(digits);
    }
    result->index++;
    return;
}

char** fizzBuzz(int n, int* returnSize) {

    struct result_info result = {0};

    result.strs = (char **) calloc(n, sizeof(char *));

    for (int i = 1; i <= n; i++) {
        form_result(&result, i);
    }

    *returnSize = n;
    return result.strs;
}
