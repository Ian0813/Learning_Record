/*
 * =====================================================================================
 *
 *       Filename:  1004 max consecutive ones iii.c
 *
 *    Description:  max consecutive ones iii
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

typedef struct recorder {
    int *flip_array;
    int arrlen; 
    int flip_count;
    int maxlen;
} recorder;

static void get_max_consecutive(recorder *tracker) {

    int count = 0;
    bool contain_one = false;

    if (!tracker)
        return;

    for (int i = 0, j = 0; j < tracker->arrlen; j++) {

        count = !tracker->flip_array[j] ? (count + 1) : count;
        contain_one = tracker->flip_array[j] ? true : contain_one;

        if (count > tracker->flip_count) {
            while (i < j && tracker->flip_array[i])
                i++;

            if (i == j)
                continue;  
            else {
                count--;
                i++;
            }
        }

        if (tracker->maxlen < ((j-i))) {
            tracker->maxlen = (j-i); 
        }
    }

    tracker->maxlen = contain_one ? (tracker->maxlen+1) : tracker->flip_count;
    return;
}

int longestOnes(int* nums, int numsSize, int k) {

    recorder tracker = {.flip_array = nums, .arrlen = numsSize, .flip_count = k, .maxlen = 0};

    get_max_consecutive(&tracker);

    return tracker.maxlen;
}

