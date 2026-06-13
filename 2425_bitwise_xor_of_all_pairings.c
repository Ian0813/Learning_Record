/*
 * =====================================================================================
 *
 *       Filename:  2425_bitwise_xor_of_all_pairings.c
 *
 *    Description:  bitwise xor of all pairings
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

int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int result = -1, temp = 0, nums2_xor = nums2[0];

    for (int i = 1; i < nums2Size; i++) {
        nums2_xor ^= nums2[i];
    }

    for (int i = 0; i < nums1Size; i++) {
        temp = (nums2Size%2) ? nums1[i] : 0;
        temp ^= nums2_xor;
        result = result == -1 ? temp : (result ^ temp);
    }
    return result;
}
