/*
 * =====================================================================================
 *
 *       Filename:  662_find_first_and_last_position_of_element_in_sorted_array.c
 *
 *    Description:  find first and last position of element in sorted array
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

#define RESULT_LEN 2

#define INIT_RESULT_CHECK(result) (result[0] == -1 && result[1] == -1)
#define COMPARE_LESS_REPLACE(v1, v2) {int temp = 0; if ((v1) < (v2)) {temp = (v1); (v1) = (v2); (v2) = temp;}}
#define COMPARE_GREAT_REPLACE(v1, v2) {int temp = 0; if ((v1) > (v2)) {temp = (v1); (v1) = (v2); (v2) = temp;}}

void compare_indices(int index, int *result) {

    if (INIT_RESULT_CHECK(result)) {
        memcpy(&result[0], &index, sizeof(index));
        memcpy(&result[1], &index, sizeof(index));
    }

    COMPARE_LESS_REPLACE(index, result[0]);
    COMPARE_GREAT_REPLACE(index, result[1]);
    return; 
}

int binary_search(int *arr, int head, int end, int target, int *result) {

    int middle = (head+end)/2;
    int index = -1;

    if (head < end) {
        if (arr[middle] == target) {
            compare_indices(middle, result);
            index = binary_search(arr, head, middle, target, result);
            index = binary_search(arr, middle+1, end, target, result);
        } else if (arr[middle] > target) {
            index = binary_search(arr, head, middle, target, result);
        } else if (arr[middle] < target) {
            index = binary_search(arr, middle+1, end, target, result);
        }
    }
    return index;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {

    int *result = NULL;
    int invalid[RESULT_LEN] = {-1, -1};
    int tindex = 0;

    result = (int *) calloc(RESULT_LEN, sizeof(int));
    *returnSize = RESULT_LEN;
    memcpy(result, invalid, sizeof(int) * RESULT_LEN);

    binary_search(nums, 0, numsSize, target, result);

    return result;
}
