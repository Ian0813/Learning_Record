/*
 * =====================================================================================
 *
 *       Filename:  2540_minimum_common_value.c
 *
 *    Description:  Minimum common value amongst two arrays  
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

int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int i = 0, j = 0; 
    int common = -1;

    for (i = 0; i < nums1Size; i++, j = 0) {

        for (j = 0; j < nums2Size; j++) {
            if (nums2[j] > nums1[i]) {
                break;
            } else if (nums2[j] == nums1[i]) {
                common = nums2[j];      
                break;
            }
        }

        if (common != -1) {
            break; 
        } else if (j == nums2Size) {
            break;
        }
    }
    return common;
}

