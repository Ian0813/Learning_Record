/*
 * =====================================================================================
 *
 *       Filename:  680_valid_palindrome_ii.c
 *
 *    Description:  valid palindrome ii
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
#include <limits.h>

typedef enum {false, true} bool;

bool check_palindrome(char *s, int *front, int *tail) {

    bool rc = true;

    for (; *front < *tail; *front += 1, *tail -= 1) {
        if (s[*front] != s[*tail]) {
            rc = false;
            break;    
        }
    }
    return rc;
}

bool validPalindrome(char* s) {

    bool rc = true;
    int front = 0, tail = strlen(s)-1;
    int backup_front = 0, backup_tail = 0;

    rc = check_palindrome(s, &front, &tail);

    if (!rc) {
        backup_front = front; 
        backup_tail = tail; 
        front++;
        rc = check_palindrome(s, &front, &tail);
    }

    if (!rc) {
        front = backup_front;
        tail = backup_tail;
        tail--;
        rc = check_palindrome(s, &front, &tail);
    }
    return rc;
}

#if 0
bool check_setbit(int n) {

    int num = 1, offset = 1;
    bool rc = true;

    while (num < n) {
        if (!(n & (num))) {
            rc = false; 
            break;
        }
        num <<= offset;
    }
    return rc;
}

int smallestNumber(int n) {

    int result = 0;

    for (int i = n; ;i++) {
        if (!(i%2)) {
            continue;
        }
        if (check_setbit(i)) {
            result = i; 
            break;
        }    
    }
    return result;
}

int getLargestOutlier(int* nums, int numsSize) {

    int total_sum = 0; 
    int subtract = 0;
    int outlier = 0, max_outlier = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        subtract = total_sum-nums[i]; 
        //printf("subtract: %d, total_sum: %d, nums: %d\n", subtract, total_sum, nums[i]);
        if (nums[i] <= max_outlier)
            continue;
        for (int j = 0; j < numsSize; j++) {
            if (i == j)
                continue;
            if ((subtract-nums[j]) == nums[j]) {
                outlier = nums[i];
                if (outlier > max_outlier) {
                    max_outlier = outlier;
                }
                break;
            }
        }
    }
    return max_outlier;
}


int main(void) {

    int arr[] = {2, 5, 3, 10};
    int result = 0;

    result = getLargestOutlier(arr, sizeof(arr)/sizeof(*arr));

    printf("result: %d\n", result);

    return EXIT_SUCCESS;
}
#endif
