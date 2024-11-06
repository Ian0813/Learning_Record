/*
 * =====================================================================================
 *
 *       Filename:  1493 longest subarray of 1s after deleting one element.c
 *
 *    Description:  longest subarray of 1s after deleting one element
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
#include <unistd.h>

int range_count(int *nums, int *one_index, int start, int end) {

    int flag = 0;
    int count = 0;

    for (int i = start; i < end; i++) {
        if (nums[i]) {
            count++;
            if (flag == 1) {
                *one_index = i;
                flag++;
            }
            continue;
        } else if (flag) {
            if (!(*one_index)) {
                *one_index = i+1;
            }
            break; 
        }
        flag++;
    }

    if (!flag) {
        count--;
        *one_index = end-1;
    }
    return count;
}

static int get_oneindex(int *nums, int start, int end) {

    for (start; start < end; start++) {
        if (nums[start])
            break; 
    }
    return start;
}

int longestSubarray(int* nums, int numsSize) {

    int zero_count = 0, zero_index = -1;
    int count = 0, max = 0;

    for (int i = 0; i < numsSize;) {

        if (nums[i]) {
            for (int j = i; j < numsSize; j++) {
                if (nums[j]) {
                    count++;
                } else {
                    if (!zero_count) {
                        zero_count++;
                        zero_index = j;
                    } else {
                        break;   
                    }
                }
            }
            if (count > max)
                max = count;
            if (!zero_count) {
                if (count == max && zero_index == -1)
                    max--;
                break;  
            }
        } else {
            zero_index = i;
        }
        count = zero_count = 0;
        i = get_oneindex(nums, zero_index+1, numsSize);
    }
    return max;
}

int main(void) {

    int arr[] = {1,1,0,0,1,1,1,0,1};
    int max = 0;

    max = longestSubarray(arr, sizeof(arr)/sizeof(*arr));
    printf("%d\n", max);

    return EXIT_SUCCESS;
}
