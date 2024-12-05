/*
 * =====================================================================================
 *
 *       Filename:  628_maximum_product_of_three_numbers.c
 *
 *    Description:  Maximum product three numbers 
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


void merge(int *arr, int left, int middle, int right) {

    int index1 = 0, index2 = 0, aindex = left;
    int lim_left = middle-left + 1, lim_right = right-middle;
    int sub1[lim_left], sub2[lim_right];

    memset(sub1, 0, sizeof(sub1));
    memset(sub2, 0, sizeof(sub2));

    for (index1 = 0; index1 < lim_left; index1++) {
        sub1[index1] = arr[index1+left];
        //printf("sub1[%d]: %d\n", index1, sub1[index1]);
    }

    for (index2 = 0; index2 < lim_right; index2++) {
        sub2[index2] = arr[index2+middle+1];
        //printf("sub2[%d]: %d\n", index2, sub2[index2]);
    }

    index1 = 0;
    index2 = 0;

    while (index1 < lim_left && index2 < lim_right) {
        if (sub1[index1] < sub2[index2]) {
            arr[aindex++] = sub1[index1];
            index1++;
        } else {
            arr[aindex++] = sub2[index2];
            index2++;
        }
        //printf("[%s] arr[%d]: %d\n", __func__, aindex, arr[aindex]);
    }

    while (index1 < lim_left) {
        arr[aindex++] = sub1[index1];
        index1++;
    }

    while (index2 < lim_right) {
        arr[aindex++] = sub2[index2];
        index2++;
    }
    return;
}

void merge_sort(int *arr, int left, int right) {

    int middle = (right+left)/2;

    if (left < right) {

        merge_sort(arr, left, middle);
        merge_sort(arr, middle+1, right);

        merge(arr, left, middle, right);
    }
    return;
}

int pos_counter(int *arr, int size) {

    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0)
            count++;
    }
    return count;
}

static int neg_counter(int *arr, int size) {

    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            count++;
        }
    }
    return count;
}

int maximumProduct(int* nums, int numsSize) {

    int v1 = 0, v2 = 0;
    int pos_num = pos_counter(nums, numsSize);
    int neg_num = neg_counter(nums, numsSize);
    int result = 1;

    merge_sort(nums, 0, numsSize - 1);

    if (neg_num+pos_num <= 3) {
        for (int i = 0; i < numsSize; i++)
            result *= nums[i];
    } else if (neg_num < 2) {
        for (int i = numsSize-1; i >= (numsSize-3); i--)
            result *= nums[i];
    } else {
        v1 = nums[0] * nums[1] * nums[numsSize-1];       
        v2 = nums[numsSize-1] * nums[numsSize-2] * nums[numsSize-3];
        result = v1 > v2 ? v1 : v2;
    }
    return result;
}
