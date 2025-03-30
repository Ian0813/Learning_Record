/*
 * =====================================================================================
 *
 *       Filename:  1865_finding_pairs_with_a_certain_sum.c
 *
 *    Description:  finding pairs with a certain sum
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
 * Your FindSumPairs struct will be instantiated and called as such:
 * FindSumPairs* obj = findSumPairsCreate(nums1, nums1Size, nums2, nums2Size);
 * findSumPairsAdd(obj, index, val);

 * int param_2 = findSumPairsCount(obj, tot);

 * findSumPairsFree(obj);
*/

#define MAX_NUMS2 1000000001

typedef struct {
    int *nums2_counter; // Count the frequency of each digit in nums2.
    int *nums1;
    int *nums2;
    int nums1Size;
    int nums2Size;
} FindSumPairs;

typedef FindSumPairs *FSP_ptr;

static void swap(int *v1, int *v2) {

    int temp;
    temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {

        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[last], &arr[head]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

static void count_frequency(int *nums, int numsSize, int *table) {

    if (table) {
        for (int i = 0; i < numsSize; i++) {
            table[nums[i]]++;
        }
    }
    return;
}

FindSumPairs* findSumPairsCreate(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    FSP_ptr obj = NULL;

    obj = (FSP_ptr) malloc(sizeof(*obj));

    if (obj) {
        obj->nums1 = nums1;
        obj->nums2 = nums2;
        obj->nums1Size = nums1Size;
        obj->nums2Size = nums2Size;
        obj->nums2_counter = (int *) calloc(MAX_NUMS2, sizeof(int));
        count_frequency(obj->nums2, obj->nums2Size, obj->nums2_counter);
        quick_sort(obj->nums1, 0, obj->nums1Size);
    }
    return obj;
}

void findSumPairsAdd(FindSumPairs* obj, int index, int val) {

    if (obj) {
        obj->nums2_counter[obj->nums2[index]]--;
        index < obj->nums2Size ? (obj->nums2[index]+=val) : -1;
        obj->nums2_counter[obj->nums2[index]]++;
    }
    return;
}

int findSumPairsCount(FindSumPairs* obj, int tot) {

    long int count = 0, diff = 0;

    if (obj) {
        for (int i = 0; i < obj->nums1Size; i++) {
            if (obj->nums1[i] < tot) {
                diff = tot - obj->nums1[i];
                count += obj->nums2_counter[diff];
                continue;
            }
            break;
        }
    }
    return count;
}

void findSumPairsFree(FindSumPairs* obj) {

    if (obj) {
        free(obj->nums2_counter);
        free(obj);
    }
    return;
}

/**
 * Your FindSumPairs struct will be instantiated and called as such:
 * FindSumPairs* obj = findSumPairsCreate(nums1, nums1Size, nums2, nums2Size);
 * findSumPairsAdd(obj, index, val);

 * int param_2 = findSumPairsCount(obj, tot);

 * findSumPairsFree(obj);
*/
