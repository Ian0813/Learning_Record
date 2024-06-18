/*
 * =====================================================================================
 *
 *       Filename:  278_first_bad_version.c
 *
 *    Description:  First bad version  
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

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
typedef enum {false, true} bool;
bool isBadVersion(int version);

int firstBadVersion(int n) {

    int first_bad = n;
    int start = 1, end = n;
    int flag = 0;

    while (start < end) {
        if (isBadVersion((end+start)/2)) {
            if (first_bad > (end+start)/2)
                first_bad = (end+start)/2; 
            if (end != (end+start)/2)
               end = (end+start)/2;
            else
               end--;
        } else {
            if (start != (end+start)/2)
                start = (end+start)/2;
            else
                start++;
        }
    }
    return first_bad;
}
