/*
 * =====================================================================================
 *
 *       Filename:  2091_removing_minimum_and_maximum_from_array.c
 *
 *    Description:  removing minimum and maximum from array
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
#include <sys/param.h>
#include <limits.h>

typedef enum {
    TARGET_MIN_INDEX = 0,
    TARGET_MAX_INDEX = 1,
} target_index_opt;

static int get_target_index(int *nums, int numsSize, target_index_opt opt) {

    int target = opt == TARGET_MIN_INDEX ? INT_MAX : INT_MIN;
    int index = 0;

    for (int i = 0; i < numsSize; i++) {
        target = opt == TARGET_MIN_INDEX ? MIN(target, nums[i]) : MAX(target, nums[i]);
        index = target == nums[i] ? i : index;
    }
    return index;
}

int minimumDeletions(int* nums, int numsSize) {

    int max_index = 0, min_index = 0;
    int front_off = 0, inter_distance = 0, back_off = 0, result = 0, temp1 = 0, temp2 = 0;

    max_index = get_target_index(nums, numsSize, TARGET_MAX_INDEX);
    min_index = get_target_index(nums, numsSize, TARGET_MIN_INDEX);

    inter_distance = (MAX(max_index, min_index) - MIN(max_index, min_index));
    front_off = max_index == min_index ? 0 : (MIN(max_index, min_index) + 1);
    back_off = max_index == min_index ? 0 : (numsSize - MAX(max_index, min_index));

    if (inter_distance <= 1) {
        result = MIN(front_off, back_off) + 1;    
    } else {
        temp1 = MIN(back_off, inter_distance) + front_off;
        temp2 = MIN(front_off, inter_distance) + back_off;
        result = MIN(temp1, temp2); 
    }
    return result;
}
