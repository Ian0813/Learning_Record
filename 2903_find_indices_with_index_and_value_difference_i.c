/*
 * =====================================================================================
 *
 *       Filename:  2903_find_indices_with_index_and_value_difference_i.c
 *
 *    Description:  find indices with index and value difference i
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

#define ANS_ARRLEN 2
#define FILL_IN_INDICES(arr, numsSize)\
        for (int i = 0; i < numsSize; i++) arr[i] = i;

typedef enum {
    INDEX_0 = 0,
    INDEX_1 = 1,
} arrindex_t;

typedef struct {
    int *nums;
    int *indices;
    int numsSize;
} indices_values;

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(indices_values *nums_set, int head, int end) {

    int last = head, tail = end;

    if (!nums_set)
        return;

    if (head < end) {

        while (last < tail) {
            if (nums_set->nums[head] > nums_set->nums[tail]) {
                last++;
                swap(&nums_set->nums[last], &nums_set->nums[tail]);
                swap(&nums_set->indices[last], &nums_set->indices[tail]);
                continue;
            }
            tail--;
        }

        swap(&nums_set->nums[head], &nums_set->nums[last]);
        swap(&nums_set->indices[head], &nums_set->indices[last]);
        quick_sort(nums_set, head, last-1);
        quick_sort(nums_set, last+1, end);
    }
    return;
}

int* findIndices(int* nums, int numsSize, int indexDifference, int valueDifference, int* returnSize) {

    int *answer = NULL;
    int indices[numsSize], start = 0;
    indices_values nums_set = {.nums = nums, .numsSize = numsSize, .indices = indices};

    *returnSize = 0; 
    answer = calloc(ANS_ARRLEN, sizeof(int));
    memset(nums_set.indices, 0, sizeof(int) * numsSize);

    if (answer) {

        *returnSize = ANS_ARRLEN; 
        answer[INDEX_0] = answer[INDEX_1] = -1;
        FILL_IN_INDICES(nums_set.indices, numsSize);

        quick_sort(&nums_set, 0, numsSize-1);

        while (start < numsSize) {
            for (int i = start, j = numsSize-1; i <= j; j--) {
                if (abs(nums[i]-nums[j]) >= valueDifference) {
                    if (abs(nums_set.indices[i]-nums_set.indices[j]) >= indexDifference) {
                        answer[INDEX_0] = nums_set.indices[i]; 
                        answer[INDEX_1] = nums_set.indices[j];
                        return answer; 
                    }
                    continue;
                }
                break;
            }
            start++;
        }
    }
    return answer;
}
