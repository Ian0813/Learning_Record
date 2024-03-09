/*
 * =====================================================================================
 *
 *       Filename:  728_self_dividing_numbers.c
 *
 *    Description:  Self dividing numbers  
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

#define ARR_SIZE 10000
typedef enum {false, true} bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool check_dividing_number(int num) {

    int val = 0, target = num;
    bool rc = true;

    if (!(num%10))
        rc = false;
    else {
        while (num) {
            val = num%10;
			if (!val || target%val) {
                rc = false;
                break;
            }
            num /= 10;
        }
    }
    return rc;
}    

int* selfDividingNumbers(int left, int right, int* returnSize) {

    int *result = (int *) malloc(ARR_SIZE * sizeof(int));
    int index = 0;

    memset(result, 0, sizeof(int) * ARR_SIZE);

    for (int i = left; i <= right; i++) {
        if (check_dividing_number(i))
            result[index++] = i;
    }

    *returnSize = index;

    return result;
}
