/*
 * =====================================================================================
 *
 *       Filename:  2869_minimum_operations_to_collect_elements.c
 *
 *    Description:  minimum operations to collect elements
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

struct tracker {
    char *occurrence;
    int counter;
    int op_times;
};

int minOperations(int* nums, int numsSize, int k) {

    struct tracker record = {0};

    if (k) {

        record.occurrence = (char *) calloc(numsSize+1, sizeof(char));

        for (int i = numsSize-1; i >= 0; i--) {
            record.op_times++;
            if (nums[i] <= k && !record.occurrence[nums[i]]) {
                record.occurrence[nums[i]] = true;
                record.counter++;
            }
            if (record.counter == k)
                break;
        }
        free(record.occurrence);
    }
    return record.op_times;
}
