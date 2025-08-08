/*
 * =====================================================================================
 *
 *       Filename:  2389_longest_subsequence_with_limited_sum.c
 *
 *    Description:  longest subsequence with limited sum
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

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(int *arr, int head, int end, int *tracker) {

    int last = head, tail = end; 

    if (head < end) {

        while (last < tail) {

            if (arr[head] > arr[tail]) {
                last++; 
                swap(&arr[last], &arr[tail]);
                if (tracker)
                    swap(&tracker[last], &tracker[tail]);
                continue;
            }
            tail--;

        }

        if (tracker)
            swap(&tracker[head], &tracker[last]);
        swap(&arr[last], &arr[head]);
        quick_sort(arr, head, last-1, tracker);
        quick_sort(arr, last+1, end, tracker);
    }

    return;
}

static void get_prefixsum(int *nums, int numsSize, int *prefix_sum) {

    for (int i = 0; i < numsSize; i++) {
        if (!i) {
            prefix_sum[i] = nums[i]; 
        } else {
            prefix_sum[i] = nums[i] + prefix_sum[i-1];  
        }
    }

    return;
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {

    int *prefix_sum = NULL, *result = NULL, rindex = 0;
    int *tracker = NULL;

    prefix_sum = (int *) calloc(numsSize, sizeof(int));
    result = (int *) calloc(queriesSize, sizeof(int));
    tracker = (int *) calloc(queriesSize, sizeof(int));

    for (int i = 0; i < queriesSize; i++)
        tracker[i] = i;

    *returnSize = queriesSize;
    quick_sort(nums, 0, numsSize-1, NULL);
    quick_sort(queries, 0, queriesSize-1, tracker);
    get_prefixsum(nums, numsSize, prefix_sum);

    for (int i = 0; i < numsSize; i++) {
        if (rindex >= queriesSize)    
            break;
         
        if (prefix_sum[i] > queries[rindex]) {
            result[tracker[rindex]] = i;  
            i--;
            rindex++; 
        }
    }

    if (rindex < queriesSize) {
        for (int i = rindex; i < queriesSize; i++) {
            result[tracker[i]] = numsSize;   
        }
    }

    free(tracker);
    return result;
}

