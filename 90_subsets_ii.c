/*
 * =====================================================================================
 *
 *       Filename:  90_subsets_ii.c
 *
 *    Description:  subsets ii
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
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct {
    int **sets; 
    int *sets_size;
    int sets_len;
    int total_size;
} nums_set;

static int compar(const void *p1, const void *p2) {

    int v1 = *(int *) p1, v2 = *(int *) p2; 

    if (v1 < v2)
        return -1;
    else if (v1 > v2) 
        return 1;
    return 0;
}

static int power_of_two(int exp) {

    int val = 1;

    if (exp > 10) {
        fprintf(stderr, "[%s] Invalid argument, please check the passed value less than or equal to 10.\n", __func__); 
        return 0;
    }

    for (int i = 1; i <= exp; i++) {
        val *= 2;
    }
    return val;
}

static nums_set *create_nums_set(int length) {

    if (!length)
        return NULL;

    nums_set *obj = NULL;

    obj = calloc(1, sizeof(*obj));

    if (obj) {
        obj->sets = calloc(power_of_two(length), sizeof(int *));
        obj->sets_len = 0;
        obj->sets_size = calloc(power_of_two(length), sizeof(int));
        obj->total_size = power_of_two(length);
    }
    return obj;
}

static bool check_no_duplicate(int *arr, int asize, int value, int target_count) {

    int count = 0;

    for (int i = 0; i < asize; i++) {
        if (arr[i] == value) 
            count++;
    }
    return count == target_count ? true : false;
}

static void subset_process(int *nums, int index, int numsSize, nums_set *obj, int *last_value, int *last_count) {

    int length = 0;

    if (!obj || !nums)
        return;

    if (index < numsSize) {

        if (*last_value == nums[index]) 
            *last_count += 1;

        if (obj->sets_len) {
            length = obj->sets_len;
            for (int i = 0, step = 0; i < length; i++) {
                if (*last_value == nums[index] && obj->sets[i][obj->sets_size[i]-1] != nums[index])
                    continue;

                if (*last_value == nums[index] && !check_no_duplicate(obj->sets[i], obj->sets_size[i], nums[index], *last_count))
                    continue;

                obj->sets[step + length] = calloc(obj->sets_size[i] + 1, sizeof(int));
                memcpy(obj->sets[step + length], obj->sets[i], obj->sets_size[i] * sizeof(int));
                obj->sets[step + length][obj->sets_size[i]] = nums[index];
                obj->sets_size[step + length] = obj->sets_size[i] + 1; 
                obj->sets_len++;
                step++;
            }    
        }

        if (*last_value != nums[index]) {
            obj->sets[obj->sets_len] = calloc(1, sizeof(int));
            obj->sets[obj->sets_len][0] = nums[index];
            obj->sets_size[obj->sets_len] = 1;
            obj->sets_len++; *last_count = 0; }
        *last_value = nums[index];
        subset_process(nums, index+1, numsSize, obj, last_value, last_count);
    }
    return;
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int last_value = INT_MIN, last_count = 0;

    qsort(nums, numsSize, sizeof(int), compar);
    nums_set *sets_obj = NULL;

    sets_obj = create_nums_set(numsSize);
    subset_process(nums, 0, numsSize, sets_obj, &last_value, &last_count);

    sets_obj->sets_size[sets_obj->sets_len] = 0;
    sets_obj->sets_len++;

    *returnSize = sets_obj->sets_len;
    *returnColumnSizes = sets_obj->sets_size;

    return sets_obj->sets;
}
