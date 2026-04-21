/*
 * =====================================================================================
 *
 *       Filename:  3843_first_element_with_unique_frequency.c
 *
 *    Description:  first element with unique frequency
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

#define COUNT_LEN 100001

static void update_occur_times(int *nums, int index, int *counter, int *occur_times) {

    counter[nums[index]]++;
    if (counter[nums[index]] > 1) {
        occur_times[counter[nums[index]]-1]--;
    }
    occur_times[counter[nums[index]]]++;

    return;
}

int firstUniqueFreq(int* nums, int numsSize) {

    int counter[COUNT_LEN] = {0}, occur_times[COUNT_LEN] = {0};


    for (int i = 0; i < numsSize; i++) {
        update_occur_times(nums, i, counter, occur_times);
    }

    for (int i = 0; i < numsSize; i++) {
        if (occur_times[counter[nums[i]]] == 1) {
            return nums[i];
        }
    }
    return -1;
}
