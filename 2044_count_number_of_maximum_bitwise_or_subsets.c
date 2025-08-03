/*
 * =====================================================================================
 *
 *       Filename:  2044_count_number_of_maximum_bitwise_or_subsets.c
 *
 *    Description:  count number of maximum bitwise or subsets
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

#define CHECK_MAXVALUE(max, value) ((max) = (max) < (value) ? (value) : (max))

struct sets_info {
    int **sets;
    int *sets_len;
    int cur_size;
    int total;
    int *or_value;
    int max_value;
};

static int get_orvalue(int *arr, int length) {

    int value = arr[0];

    for (int i = 1; i < length; i++) {
        value |= arr[i];
    }

    return value;
}

static long long factorial(long long value) {

    if (!value) {
        return 1;
    }

    return value * factorial(value-1); 
}

static int cal_combination(int set, int sub) {

    int result = 0;

    result = factorial(set)/(factorial(set-sub) * factorial(sub) * 1LL);

    return result;
}

static int calculate_setlength(int numsSize) {

    int total = 0;

    for (int i = 1; i <= numsSize; i++) {
        total += cal_combination(numsSize, i);
    }

    return total;
}

static void setinfo_initialize(struct sets_info *sinfo) {

    if (sinfo) {
        sinfo->sets = (int **) calloc(sinfo->total, sizeof(int *)); 
        sinfo->sets_len = (int *) calloc(sinfo->total, sizeof(int)); 
        sinfo->or_value = (int *) calloc(sinfo->total, sizeof(int));
    }
    return;
}

static void setinfo_set_generator(int *nums, int numsSize, int index, struct sets_info *sinfo) {

    int temp = 0;

    if (index < numsSize) {

        if (sinfo->cur_size) {

            temp = sinfo->cur_size;

            for (int i = 0; i < temp; i++) {
                sinfo->sets[sinfo->cur_size] = (int *) calloc(sinfo->sets_len[i] + 1, sizeof(int));
                memcpy(sinfo->sets[sinfo->cur_size], sinfo->sets[i], sinfo->sets_len[i] * sizeof(int));
                sinfo->sets[sinfo->cur_size][sinfo->sets_len[i]] = nums[index];
                sinfo->sets_len[sinfo->cur_size] = sinfo->sets_len[i] + 1;
                sinfo->or_value[sinfo->cur_size] = get_orvalue(sinfo->sets[sinfo->cur_size], sinfo->sets_len[sinfo->cur_size]);
                CHECK_MAXVALUE(sinfo->max_value, sinfo->or_value[sinfo->cur_size]);
                sinfo->cur_size++;
            }
        }    

        sinfo->sets[sinfo->cur_size] = (int *) calloc(1, sizeof(int));
        sinfo->sets[sinfo->cur_size][0] = nums[index]; 
        sinfo->sets_len[sinfo->cur_size] = 1;
        sinfo->or_value[sinfo->cur_size] = nums[index];
        CHECK_MAXVALUE(sinfo->max_value, sinfo->or_value[sinfo->cur_size]);
        sinfo->cur_size++;

        setinfo_set_generator(nums, numsSize, index+1, sinfo);
    }
    return;
}

static void setinfo_deinitialize(struct sets_info *sinfo) {

    if (sinfo) {
        free(sinfo->sets);
        free(sinfo->sets_len);
        free(sinfo->or_value);
    }
    return;
}

int countMaxOrSubsets(int* nums, int numsSize) {

    struct sets_info sinfo = {0};
    int count = 0;

    sinfo.total = calculate_setlength(numsSize);

    setinfo_initialize(&sinfo);
    setinfo_set_generator(nums, numsSize, 0, &sinfo);

    for (int i = 0; i < sinfo.total; i++) {
        if (sinfo.or_value[i] == sinfo.max_value)        
            count++;
    }

    setinfo_deinitialize(&sinfo);

    return count;
}
