/*
 * =====================================================================================
 *
 *       Filename:  3867_sum_of_gcd_of_formed_pairs.c
 *
 *    Description:  sum of gcd of formed pairs
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
#include <stdbool.h>
#include <limits.h>

#define MAX(v1, v2) ((v1) > (v2) ? (v1) : (v2))
#define MIN(v1, v2) ((v1) < (v2) ? (v1) : (v2))

static void merge_process(int *arr, int head, int middle, int end) {

    int a1Size = (middle-head) + 1, a2Size = end - middle;    
    int a1[a1Size], a2[a2Size];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = 0; i < a1Size; i++) {
        a1[i] = arr[head + i];
    }

    for (int i = 0; i < a2Size; i++) {
        a2[i] = arr[middle + i + 1];
    }

    while (a1_index < a1Size && a2_index < a2Size) {
        if (a1[a1_index] < a2[a2_index]) {
            arr[index++] = a1[a1_index++];   
        } else {
            arr[index++] = a2[a2_index++];   
        }
    }

    while (a1_index < a1Size)
        arr[index++] = a1[a1_index++];   

    while (a2_index < a2Size)
        arr[index++] = a2[a2_index++];
    return;
}

static void merge_sort(int *arr, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(arr, head, middle);
        merge_sort(arr, middle+1, end);
        merge_process(arr, head, middle, end);
    }
    return;
}

static int gcd_calculate(int v1, int v2) {

    int modulo_val = 0, value = 0, rc = 0;

    value = MAX(v1, v2);
    rc = modulo_val = MIN(v1, v2);

    if (value % modulo_val) {
        rc = gcd_calculate(modulo_val, (value % modulo_val));      
    }
    return rc;
}

static bool prefixGcd_form(int *nums, int numsSize, int *prefixGcd) {

    int cur_max = INT_MIN;

    if (!nums || !prefixGcd || !numsSize)
        return false;

    for (int i = 0; i < numsSize; i++) {
        cur_max = MAX(nums[i], cur_max);
        prefixGcd[i] = gcd_calculate(nums[i], cur_max);
    }    
    return true;
}

long long gcdSum(int* nums, int numsSize) {

    int *prefixGcd = NULL;
    long long result = 0LL;

    if (numsSize) {

        prefixGcd = calloc(numsSize, sizeof(int));
        prefixGcd_form(nums, numsSize, prefixGcd);
        merge_sort(prefixGcd, 0, numsSize-1);

        for (int i = 0, j = numsSize-1; i < j; i++, j--) {
            result = result + ((long long) gcd_calculate(prefixGcd[i], prefixGcd[j]));
        }
        free(prefixGcd);
    }
    return result;
}
