/*
 * =====================================================================================
 *
 *       Filename:  3678_smallest_absent_positive_greater_than_average.c
 *
 *    Description:  smallest absent positive greater than average
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 102

static void merge_process(int *nums, int head, int middle, int end) {

    int arr1_size = (middle - head) + 1, arr2_size = end - middle;
    int arr1[arr1_size], arr2[arr2_size];
    int arr1_index = 0, arr2_index = 0, index = head;

    for (int i = 0; i < arr1_size; i++) {
        arr1[i] = nums[head + i];
    }

    for (int i = 0; i < arr2_size; i++) {
        arr2[i] = nums[middle+i+1];
    }

    while (arr1_index < arr1_size && arr2_index < arr2_size) {

        if (arr1[arr1_index] < arr2[arr2_index]) {
            nums[index++] = arr1[arr1_index++];
        } else {
            nums[index++] = arr2[arr2_index++];
        }
    }

    while (arr1_index < arr1_size) {
        nums[index++] = arr1[arr1_index++];
    }

    while (arr2_index < arr2_size) {
        nums[index++] = arr2[arr2_index++];
    }
    return;
}

static void merge_sort(int *nums, int head, int end) {

    int middle = (head + end) / 2;

    if (head < end) {
        merge_sort(nums, head, middle);
        merge_sort(nums, middle+1, end);
        merge_process(nums, head, middle, end);
    }
    return;
}

static int get_average(int *nums, int numsSize, int *table) {

    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > -1)
            table[nums[i]] = 1;
        sum += nums[i];
    }

    return sum/numsSize;
}

int smallestAbsent(int* nums, int numsSize) {

    int table[TABLE_SIZE] = {0};
    int smallest = 0, average = 0;

    average = get_average(nums, numsSize, table);

    for (int i = 1; i < TABLE_SIZE; i++) {
        if (!table[i] && i > average) {
            smallest = i;
            break;
        }
    }
    return smallest;
}
