/*
 * =====================================================================================
 *
 *       Filename:  1630_arithmetic_subarrays.c
 *
 *    Description:  Arirhmetic subarrays  
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

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end - 1;

    if (front < tail) {
        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

static bool check_arithmetic_array(int *nums, int size, int difference) {

    for (int i = 0; i < (size-1); i++) {
        if ((nums[i+1]-nums[i]) != difference) {
            return false; 
        }
    }
    return true;
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize) {

    int rindex = 0, len = 0;
    bool *result = NULL, status = false;
    result = (bool *) calloc(lSize, sizeof(bool));
    int temp[BUFSIZ] = {0};

    if ((*r-*l) > 0) {
        for (int i = 0; i < lSize; i++) {
            len = r[i]-l[i]+1; 
            memcpy(temp, &nums[l[i]], sizeof(int)*len);
            quick_sort(temp, 0, len);
            status = check_arithmetic_array(temp, len, temp[1]-temp[0]);
            result[rindex++] = status;
            memset(temp, 0, sizeof(int)*BUFSIZ);
        }
    } else {
        result[rindex++] = status; 
    }
    *returnSize = rindex;
    return result;
}
