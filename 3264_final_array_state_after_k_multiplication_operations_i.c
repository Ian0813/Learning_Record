/*
 * =====================================================================================
 *
 *       Filename:  3264_final_array_state_after_k_multiplication_operations_i.c
 *
 *    Description:  final array state after k multiplication operations i
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define IS_EQUAL(v1, v2) (v1) == (v2)
#define CHECK_INDEX(v1, v2, i1, i2) (IS_EQUAL(v1, v2) && (i1 > i2))

struct nums_recorder {
    int *nums;
    int size;
    int *indices;
};

static void recorder_alloc(struct nums_recorder *recorder, int *nums, int numsSize) {

    recorder->size = numsSize;
    recorder->nums = (int *) calloc(numsSize, sizeof(int));
    recorder->indices = (int *) calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        recorder->nums[i] = nums[i];
        recorder->indices[i] = i;
    }    
    return;
}

static void recorder_dealloc(struct nums_recorder *recorder) {
    free(recorder->indices);
    return;
}

static void swap(int *v1, int *v2) {

    int temp = 0;
    temp = *v1;
    *v1 = *v2; 
    *v2 = temp;
    return;
}

static void quick_sort(struct nums_recorder *recorder, int head, int end) {

    int front = head, last = head, tail = end - 1;

    if (front < tail) {

        while (last < tail) {
            if (recorder->nums[head] > recorder->nums[tail]
               || CHECK_INDEX(recorder->nums[head], recorder->nums[tail], recorder->indices[head], recorder->indices[tail])) {
                last++;
                swap(&recorder->nums[last], &recorder->nums[tail]);
                swap(&recorder->indices[last], &recorder->indices[tail]);
                continue;
            }
            tail--;
        }

        swap(&recorder->nums[head], &recorder->nums[last]);
        swap(&recorder->indices[head], &recorder->indices[last]);

        quick_sort(recorder, head, last);
        quick_sort(recorder, last+1, end);
    }
    return;
}

static void update_index(struct nums_recorder *recorder, int first) {

    int findex = first;

    if (first < recorder->size-1) {
        for (int i = findex; i < recorder->size-1; i++) {
            if (CHECK_INDEX(recorder->nums[i], recorder->nums[i+1],
                    recorder->indices[i], recorder->indices[i+1])) {
                swap(&recorder->nums[i], &recorder->nums[i+1]); 
                swap(&recorder->indices[i], &recorder->indices[i+1]);
                continue;
            }
            break;
        }
        update_index(recorder, first+1);
    }
    return;
}

static void update_multiplication(struct nums_recorder *recorder, int multiplier) {

    int findex = 0;

    recorder->nums[findex] *= multiplier;

    for (int i = findex; i < recorder->size-1; i++) {
        if (recorder->nums[i] > recorder->nums[i+1]) {
            swap(&recorder->nums[i], &recorder->nums[i+1]); 
            swap(&recorder->indices[i], &recorder->indices[i+1]); 
            continue;
        }
        break;
    }
    update_index(recorder, 0);
    return;
}

static void update_nums(struct nums_recorder *recorder, int *nums) {

    if (recorder && nums) {
        for (int i = 0; i < recorder->size; i++) {
            nums[recorder->indices[i]] = recorder->nums[i];
        }
        memcpy(recorder->nums, nums, sizeof(int)*recorder->size);
    }
    return;
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {

    struct nums_recorder recorder = {NULL};

    if (numsSize) {

        *returnSize = numsSize;
        recorder_alloc(&recorder, nums, numsSize);

        quick_sort(&recorder, 0, numsSize);

        for (int i = 0; i < k; i++) {
            update_multiplication(&recorder, multiplier);
        }    

        update_nums(&recorder, nums);
        recorder_dealloc(&recorder);

    }
    return recorder.nums;
}
