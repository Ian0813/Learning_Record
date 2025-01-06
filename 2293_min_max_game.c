/*
 * =====================================================================================
 *
 *       Filename:  2293_min_max_game.c
 *
 *    Description:  min_max_game.c

 *
 *        Version:  1.0
 *        Created:  2025年01月06日 22時49分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MIN(a, b) ((a) <= (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CALCULATE_OP(i, nums, index) (index%2 ? MAX(nums[i], nums[i+1]) : MIN(nums[i], nums[i+1]))

static int get_result(int *nums, int len) {

    int new_index = 0;
    int value = 0, result = 0;

    if (len > 1) {
        for (int i = 0; i < len; i += 2) {
            value = CALCULATE_OP(i, nums, new_index);
            nums[new_index++] = value;
        }
        result = get_result(nums, new_index);
    } else {
        return nums[0];
    }
    return result;
}

int minMaxGame(int* nums, int numsSize) {

    int result = 0;

    result = get_result(nums, numsSize);

    return result;
}

int main(void) {
 
    int nums[] = {1,3,5,2,4,8,2,2};

    printf("%d\n", minMaxGame(nums, sizeof(nums)/sizeof(int)));

    return EXIT_SUCCESS;
}    
