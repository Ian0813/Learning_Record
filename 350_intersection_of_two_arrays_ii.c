/*
 * =====================================================================================
 *
 *       Filename:  350_intersection_of_two_arrays_ii.c
 *
 *    Description:  Intersection of two arrays
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

#define TABLE_SIZE 1001

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int result_len = (nums1Size > nums2Size) ? nums1Size : nums2Size;
    int *result = (int *) calloc(result_len, sizeof(int)), index = 0;
    int table[TABLE_SIZE] = {0};

    for (int i = 0; i < nums1Size; i++) {
        table[nums1[i]]++;
    }

    for (int i = 0; i < nums2Size; i++) {
        if (table[nums2[i]]) {
            result[index++] = nums2[i];
            table[nums2[i]]--;
        }
    }

    *returnSize = index;

    return result;
}
