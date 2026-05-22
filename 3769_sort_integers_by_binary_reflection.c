/*
 * =====================================================================================
 *
 *       Filename:  3769 sort integers by binary reflection.c
 *
 *    Description:  sort integers by binary reflection
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
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define INT_BITS (CHAR_BIT * sizeof(int))

struct number_set {
    int *nums;
    int *reflect;
    int size;
};

static void swap(int *p1, int *p2) {

    int temp = *p1;

    *p1 = *p2; 
    *p2 = temp;
    return;
}

static int *get_reflection(int *nums, int numsSize) {

    int *ptr = NULL, flag = 0, value = 0, pindex = 0;
    int highest_pos = 0; 

    ptr = (int *) calloc(numsSize, sizeof(int));

    if (ptr) {

        for (int i = 0; i < numsSize; i++) {
            for (int j = INT_BITS-1; j >= 0; j--) {

                if (!flag && (nums[i] >> j) & 1) {
                    flag = 1;
                    highest_pos = j;
                } else if (flag && ((nums[i] >> j) & 1))
                    value |=  (1U << (highest_pos - j));
            }
            ptr[pindex++] = value;
            flag = value = 0;
        }    
    }
    return ptr;
}

static void quick_sort(struct number_set *set, int head, int end) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {
             if (set->reflect[head] > set->reflect[tail] ||
                 ((set->reflect[head] == set->reflect[tail]) && set->nums[head] > set->nums[tail])) {
                 last++;
                 swap(&set->reflect[last], &set->reflect[tail]);
                 swap(&set->nums[last], &set->nums[tail]);
                 continue;
             }
             tail--;
        }

        swap(&set->reflect[head], &set->reflect[last]);
        swap(&set->nums[last], &set->nums[head]);
        quick_sort(set, head, last-1);
        quick_sort(set, last+1, end);
    }

    return;
}

int* sortByReflection(int* nums, int numsSize, int* returnSize) {

    int *arr = NULL;    
    struct number_set nums_info = {0};

    arr = get_reflection(nums, numsSize);

    nums_info.nums = nums;
    nums_info.reflect = arr;
    nums_info.size = numsSize;

    quick_sort(&nums_info, 0, numsSize-1);
    free(arr);

    *returnSize = numsSize;

    return nums; 
}
