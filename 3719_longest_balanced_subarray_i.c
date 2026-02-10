/*
 * =====================================================================================
 *
 *       Filename:  3719_longest_balanced_subarray_i.c
 *
 *    Description:  longest balanced subarray i
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

typedef enum {false, true} bool;


#define TABLE_SIZE 100001
#define ID_ODD(val) ((val)%2)
#define ID_EVEN(val) (!((val)%2))

int longestBalanced(int* nums, int numsSize) {

    bool table[TABLE_SIZE] = {0};
    int length = 0, even_count = 0, odd_count = 0, max = 0;

    for (int i = 0; i < numsSize; i++) {

        for (int j = i; j < numsSize; j++) {

            if (!table[nums[j]] && ID_ODD(nums[j])) {
                table[nums[j]] = true;
                odd_count++;
            } else if (!table[nums[j]] && ID_EVEN(nums[j])) {
                table[nums[j]] = true;
                even_count++;
            }

            length = even_count == odd_count ? (j+1) - i : length;

            if (max < length)
                max = length;
        }

        if (max == (numsSize - i)) {
            break;
        }

        even_count = odd_count = 0 ;
        memset(table, false, sizeof(bool) * TABLE_SIZE);
    }

    return max;
}
