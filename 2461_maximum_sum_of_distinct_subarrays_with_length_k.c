/*
 * =====================================================================================
 *
 *       Filename:  2461 maximum sum of distinct subarrays with length k.c
 *
 *    Description:  maximum sum of distinct subarrays with length k
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

#define TABLE_SIZE 100001

typedef struct {
    int count[TABLE_SIZE];
    int dup_flag[TABLE_SIZE];
    int dup_array[TABLE_SIZE];
    int dup_size;
} counter_info;

long long maximumSubarraySum(int* nums, int numsSize, int k) {

    counter_info checker = {0};
    long long result = 0LL, maximum = 0LL;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {

        count++;
        checker.count[nums[i]]++;
        result += nums[i];

        if (checker.count[nums[i]] > 1 && !checker.dup_flag[nums[i]]) {
            checker.dup_array[checker.dup_size++] = nums[i];
            checker.dup_flag[nums[i]] = 1;
        }

        if (count > k) {
            checker.count[nums[i-k]]--;
            result -= nums[i-k];
            count--;
            for (int j = 0; j < checker.dup_size; j++) {
                if (checker.dup_array[j] == nums[i-k] && checker.count[nums[i-k]] <= 1) {
                    memcpy(&checker.dup_array[j], &checker.dup_array[j+1], sizeof(int) * (checker.dup_size-(j+1)));
                    checker.dup_flag[nums[i-k]] = 0;
                    checker.dup_array[checker.dup_size-1] = 0;
                    checker.dup_size--;
                    break;
                }
            }
        }

        if (count == k && !checker.dup_size) {
            maximum = maximum < result ? result : maximum;     
        }
    }

    return maximum;
}
