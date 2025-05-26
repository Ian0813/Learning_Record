/*
 * =====================================================================================
 *
 *       Filename:  3005_count_elements_with_maximum_frequency.c
 *
 *    Description:  count elements with maximum frequency
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

#define TABLE_SIZE 101

struct count_tracker {
    int table[TABLE_SIZE];
    int max_count;
};

static void count_occurrence(int *nums, int numsSize, struct count_tracker *tracker) {

    for (int i = 0; i < numsSize; i++) {

        tracker->table[nums[i]]++;

        if (tracker->table[nums[i]] > tracker->max_count) {
            tracker->max_count = tracker->table[nums[i]];
        }
    }
    return;
}

static int get_maxfreq_element(struct count_tracker *tracker) {

    int total = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (tracker->table[i] == tracker->max_count) {
            total += tracker->max_count;
        }
    }
    return total;
}

int maxFrequencyElements(int* nums, int numsSize) {

    struct count_tracker tracker = {0};

    count_occurrence(nums, numsSize, &tracker);

    return get_maxfreq_element(&tracker); 
}
