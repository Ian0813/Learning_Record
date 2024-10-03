/*
 * =====================================================================================
 *
 *       Filename:  238_product_of_array_except_self.c
 *
 *    Description:  product of array except self.c
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

typedef enum {false, true} bool;

typedef struct calculate_info {
    bool contain_zero;
    int product_value;
    int zero_counter;
} CalInfo;

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int *result = NULL;
    CalInfo process_info = {.product_value = 1};
    *returnSize = numsSize;

    if (numsSize) {

        result = (int *) calloc(numsSize, sizeof(int));

        for (int i = 0; i < numsSize; i++) {
            if (nums[i]) {
                process_info.product_value *= nums[i];
            } else {
                process_info.contain_zero = true;
                process_info.zero_counter++;
            }
        }

        if (process_info.zero_counter < 2) {
            for (int i = 0; i < numsSize; i++) {
                if (process_info.contain_zero) {
                    if (nums[i]) {
                        result[i] = 0;
                    } else {
                        result[i] = process_info.product_value;
                    }
                } else {
                    result[i] = process_info.product_value/nums[i];
                }
            }
        } else {
            memset(result, 0, sizeof(int) * process_info.zero_counter);
        }
    }
    return result;
}

int main(void) {

    int arr[] = {0, 1};
    int size = 0;
    int *result = NULL;

    result = productExceptSelf(arr, sizeof(arr)/sizeof(*arr), &size);

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    putchar('\n');
    free(result);

    return EXIT_SUCCESS;
}
