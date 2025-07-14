/*
 * =====================================================================================
 *
 *       Filename:  2239_find_closest_number_to_zero.c
 *
 *    Description:  find closest number to zero
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

typedef enum {false, true} bool;

static bool is_zeroexist(int *nums, int numsSize) {

    bool rc = false;

    for (int i = 0; i < numsSize; i++) {
        if (!nums[i]) {
            rc = true;
            break;
        }
    }
    return rc;
}

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(int *arr, int head, int end) {

    int last = head, tail = end;

    if (head < tail) {
        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last-1);
        quick_sort(arr, last+1, end);
    }

    return;
}

static int binary_search(int *arr, int head, int end) {

    int middle = (head+end)/2;
    int rc = 0;

    if (head < end) {
        if (!arr[middle]) {
            rc = middle;
        } else if (arr[middle] > 0) {
            rc = binary_search(arr, head, middle);
        } else if (arr[middle] < 0) {
            rc = binary_search(arr, middle+1, end);
        }
    }
    return rc;
}

int findClosestNumber(int* nums, int numsSize) {

    int result = 0, index = 0;
    int *temp = NULL;

    if (is_zeroexist(nums, numsSize))
        return result;

    temp = (int *) calloc(numsSize+1, sizeof(int));
    temp[0] = 0;
    memcpy(&temp[1], nums, sizeof(int) * numsSize);

    quick_sort(temp, 0, numsSize);
    index = binary_search(temp, 0, numsSize+1);

    if (!index) {
        result = temp[index+1];
    } else if (index == numsSize) {
        result = temp[index-1];
    } else {
        result = abs(temp[index+1]) == abs(temp[index-1]) ? temp[index+1] :\
                 abs(temp[index+1]) > abs(temp[index-1]) ? temp[index-1] : temp[index+1];
    }
    free(temp);

    return result;
}
