/*
 * =====================================================================================
 *
 *       Filename:  1814_count_nice_pairs_in_an_array.c
 *
 *    Description:  count nice pairs in an array
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

#define BOUNDARY_VAL 1000000007

static int reverse_perform(int val) {

    int result = 0;

    do {
        result *= 10;
        result += (val%10);
        val /= 10;
    } while (val);

    return result;
}

static void get_count_nums(int *nums, int *count_nums, int numsSize) {

    for (int i = 0; i < numsSize; i++) {
        count_nums[i] = nums[i] - reverse_perform(nums[i]);
    }
    return;
}

static int comp(const void *v1, const void *v2) {
    return *((int *) v1) > *((int *) v2);
}

static int count_pairs(int *count_nums, int size) {

    int val = 0;
    long long count = 0LL, occurrence = 0LL;

    if (size > 1) {

        val = count_nums[0];
        occurrence = 1;

        for (int i = 1; i < size; i++) {
            if (val == count_nums[i])
                occurrence++;
            else {
                count = (count + ((occurrence*(occurrence-1)) / 2)) % BOUNDARY_VAL;
                occurrence = 1;
                val = count_nums[i];
            }
        }

        if (occurrence)
            count = (count + ((occurrence*(occurrence-1)) / 2)) % BOUNDARY_VAL;
    }
    return (int) count;
}

int countNicePairs(int* nums, int numsSize) {

    int *count_nums = NULL, count = 0;
    long long v1 = 0LL, v2 = 0LL;

    count_nums = calloc(numsSize, sizeof(*count_nums));

    get_count_nums(nums, count_nums, numsSize);
    qsort(count_nums, numsSize, sizeof(int), comp);

    count = count_pairs(count_nums, numsSize);
    free(count_nums);
    return count;
}

