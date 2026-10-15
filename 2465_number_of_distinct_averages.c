/*
 * =====================================================================================
 *
 *       Filename:  2465_number_of_distinct_averages.c
 *
 *    Description:  number of distinct averages
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
#include <limits.h>

static int comparison(const void *v1, const void *v2) {

    if ((*((float *) v1)) > (*(float *) v2)) {
        return 1;
    } else if ((*((float *) v1)) < (*(float *) v2)) {
        return -1;
    }
    return 0;
}

int distinctAverages(int* nums, int numsSize) {

    int distinct_num = 0, average_len = 0;
    float average_nums[numsSize], d1 = 0.0, d2 = 0.0, last = INT_MAX;

    qsort((void *) nums, numsSize, sizeof(int), comparison);
    
    for (int i = 0, j = numsSize-1; i < j; i++, j--) {
        d1 = nums[i];
        d2 = nums[j];
        average_nums[average_len++] = (d1+d2)/2.0;
    }

    qsort(average_nums, average_len, sizeof(float), comparison);

    for (int i = 0; i < (average_len); i++) {
        if (last != average_nums[i]) {
            last = average_nums[i];
            distinct_num++;
        }
    }
    return distinct_num;
}
