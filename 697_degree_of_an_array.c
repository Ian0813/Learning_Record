/*
 * =====================================================================================
 *
 *       Filename:  697_degree_of_an_array.c
 *
 *    Description:  degree of an array
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

#define TABLE_SIZE 50000

struct max_recorder {
    int max_frequency;
    int max_count;
    int marked[TABLE_SIZE];
};

enum {
    NON_MARK = 0,
    DO_MARK = 1
};

static void counting(int *table, int *nums, int numsSize, struct max_recorder *max_info) {

    for (int i = 0; i < numsSize; i++) {
        table[nums[i]]++;

        if (max_info->max_frequency < table[nums[i]]) {
            max_info->max_frequency = table[nums[i]];
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (table[nums[i]] == max_info->max_frequency && !max_info->marked[nums[i]]) {
            max_info->max_count++;
            max_info->marked[nums[i]] = DO_MARK;
        }
    }
    return;
}

static void update_maxinfo(int *table, int *nums, int numsSize, struct max_recorder *info) {

    info->max_count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (table[nums[i]] == info->max_frequency && info->marked[nums[i]] == NON_MARK) {
            info->max_count++;
            info->marked[nums[i]] = DO_MARK;
        }
    }
    return;
}

static int get_smallest_length_v1(int *table, int *nums, int numsSize, struct max_recorder *info) {

    int start = 0, tail = numsSize-1, count = 0;

    count = info->max_count;

    while (count) {
        if (table[nums[tail]] == info->max_frequency && info->marked[nums[tail]] == DO_MARK) {
            count--;
            info->marked[nums[tail]] = NON_MARK;
        }
        table[nums[tail]]--;
        tail--;
    }

    tail++;
    table[nums[tail]]++;
    update_maxinfo(table, nums, numsSize, info);
    count = info->max_count;

    while (count) {
        if (table[nums[start]] == info->max_frequency && info->marked[nums[start]] == DO_MARK) {
            count--;
            info->marked[nums[start]] = NON_MARK;
        }
        start++;
    }

    start--;
    return (tail-start)+1;
}

static int get_smallest_length_v2(int *table, int *nums, int numsSize, struct max_recorder *info) {

    int start = 0, tail = numsSize-1, count = 0;

    count = info->max_count;

    while (count) {
        if (table[nums[start]] == info->max_frequency && info->marked[nums[start]] == DO_MARK) {
            count--;
            info->marked[nums[start]] = NON_MARK;
        }
        table[nums[start]]--;
        start++;
    }

    start--;
    table[nums[start]]++;
    update_maxinfo(table, nums, numsSize, info);
    count = info->max_count;

    while (count) {
        if (table[nums[tail]] == info->max_frequency && info->marked[nums[tail]] == DO_MARK) {
            count--;
            info->marked[nums[tail]] = NON_MARK;
        }
        table[nums[tail]]--;
        tail--;
    }

    tail++;
    return (tail-start)+1;
}

int findShortestSubArray(int* nums, int numsSize) {

    int table[TABLE_SIZE] = {0}, smallest_length = 0, temp = 0;
    struct max_recorder info = {0};

    if (numsSize) {
        counting(table, nums, numsSize, &info); 
        smallest_length = get_smallest_length_v1(table, nums, numsSize, &info); 
        memset(table, 0, sizeof(int) * TABLE_SIZE);
        memset(&info, 0, sizeof(struct max_recorder));
        counting(table, nums, numsSize, &info); 
        temp = get_smallest_length_v2(table, nums, numsSize, &info); 
        smallest_length = smallest_length > temp ? temp : smallest_length; 
    }
    return smallest_length;
}
