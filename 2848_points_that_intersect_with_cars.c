/*
 * =====================================================================================
 *
 *       Filename:  2848_points_that_intersect_with_cars.c
 *
 *    Description:  points that intersect with cars
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
#include <limits.h>

#define UNIT_SIZE (sizeof(int)*2)

enum {
    START_INDEX = 0,
    END_INDEX = 1
};

static void swap(int *ptr1, int *ptr2) {

    int temp[UNIT_SIZE] = {0};

    memcpy(temp, ptr1, UNIT_SIZE);
    memcpy(ptr1, ptr2, UNIT_SIZE);
    memcpy(ptr2, temp, UNIT_SIZE);
    return;
}

static void quick_sort(int **nums, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {

        while (last < tail) {
            if (nums[head][START_INDEX] > nums[tail][START_INDEX]) {
                last++;
                swap(nums[last], nums[tail]);
                continue;
            }
            tail--;
        }
        swap(nums[head], nums[last]);
        quick_sort(nums, head, last);
        quick_sort(nums, last+1, end);
    }
    return;
}    

int numberOfPoints(int** nums, int numsSize, int* numsColSize) {

    int result = 0;
    int pre_end = 0;

    if (numsSize) {
        quick_sort(nums, 0, numsSize);

        for (int i = 0; i < numsSize; i++) {
            if (pre_end < nums[i][START_INDEX]) {
                result += (nums[i][END_INDEX]-nums[i][START_INDEX]+1);
            } else if (pre_end < nums[i][END_INDEX]) {
                result += (nums[i][END_INDEX]-pre_end);
            }
            if (nums[i][END_INDEX] > pre_end)
                pre_end = nums[i][END_INDEX]; 
        }
    }
    return result;
}

