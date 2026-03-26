/*
 * =====================================================================================
 *
 *       Filename:  3847_find_the_score_difference_in_a_game.c
 *
 *    Description:  find the score difference in a game
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

typedef enum {false, true} bool;

#define USER_LEN 2

#define IS_SWAP_1(value) (((value)%2) ? true : false)
#define IS_SWAP_2(count) (!((count)%6) ? true : false)

int scoreDifference(int* nums, int numsSize) {

    int users[USER_LEN] = {0}, uindex = 0;
    int diff = 0, count = 0;

    for (int i = 0; i < numsSize; i++) {
        count++;
        if (IS_SWAP_1(nums[i])) {
            uindex = (uindex+1) % USER_LEN; 
        }

        if (IS_SWAP_2(count)) {
            uindex = (uindex+1) % USER_LEN; 
        }
        users[uindex] += nums[i]; 
    }

    if (sizeof(users) == (sizeof(int) * 2))
        diff = users[0] - users[1];

    return diff;
}
