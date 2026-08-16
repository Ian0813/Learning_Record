/*
 * =====================================================================================
 *
 *       Filename:  2191_sort_the_jumbled_numbers.c
 *
 *    Description:  sort the jumbled numbers
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
#include <sys/param.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define CH_TO_VAL(ch) ((ch)-'0')
#define VAL_TO_CH(val) ((val)+'0')

typedef struct {
    int *mapping;
    int mappingSize;
    int *nums;
    int *mapped_nums;
    int *mapped_indices;
    int numsSize;
} map_nums_t;

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;  
    *v2 = temp;

    return;
}

static char *val_to_str(int val) {

    char str[BUFSIZ] = {0}, ch = '\0';
    int sindex = 0;

    *str = '0';

    while (val) {
        str[sindex++] = VAL_TO_CH(val%10); 
        val /= 10; 
    }

    for (int i = 0, j = sindex-1; i < j; i++, j--) {
        ch = str[i]; 
        str[i] = str[j];
        str[j] = ch;
    }
    return strdup(str);
}

static void quick_sort(map_nums_t *mnums, int head, int end) {

    int last = head, tail = end;  

    if (head < end) {

        while (last < tail) {

            if (mnums->mapped_nums[head] > mnums->mapped_nums[tail] || 
                (mnums->mapped_nums[head] == mnums->mapped_nums[tail] && mnums->mapped_indices[head] > mnums->mapped_indices[tail])) {
                last++;
                swap(&mnums->mapped_nums[last], &mnums->mapped_nums[tail]);
                swap(&mnums->mapped_indices[last], &mnums->mapped_indices[tail]);
                swap(&mnums->nums[last], &mnums->nums[tail]);
                continue;
            }
            tail--; 
        }

        swap(&mnums->mapped_nums[last], &mnums->mapped_nums[head]);
        swap(&mnums->mapped_indices[last], &mnums->mapped_indices[head]);
        swap(&mnums->nums[last], &mnums->nums[head]);
        quick_sort(mnums, head, last-1);
        quick_sort(mnums, last+1, end);
    }
    return;
}

static void merge_process(map_nums_t *mnums, int head, int middle, int end) {

    int m1_size = (middle-head) + 1, m2_size = end - middle;
    int m1_nums[m1_size], m1_indices[m1_size], m1_mapped_nums[m1_size];
    int m2_nums[m2_size], m2_mapped_nums[m2_size], m2_indices[m2_size]; 
    int m1_index = 0, m2_index = 0, index = head; 

    for (int i = 0; i < m1_size; i++) {
        m1_nums[i] = mnums->nums[head + i];    
        m1_mapped_nums[i] = mnums->mapped_nums[head + i];    
        m1_indices[i] = mnums->mapped_indices[head + i];    
    }

    for (int i = 0; i < m2_size; i++) {
        m2_nums[i] = mnums->nums[middle + i + 1];
        m2_mapped_nums[i] = mnums->mapped_nums[middle + i + 1];
        m2_indices[i] = mnums->mapped_indices[middle + i + 1];
    }

    while (m1_index < m1_size && m2_index < m2_size) {
        if (m1_mapped_nums[m1_index] < m2_mapped_nums[m2_index] || 
            (m1_mapped_nums[m1_index] == m2_mapped_nums[m2_index] && m1_indices[m1_index] < m2_indices[m2_index])) {
            mnums->nums[index] = m1_nums[m1_index];
            mnums->mapped_nums[index] = m1_mapped_nums[m1_index];
            mnums->mapped_indices[index] = m1_indices[m1_index];
            m1_index++;
        } else {
            mnums->nums[index] = m2_nums[m2_index];
            mnums->mapped_nums[index] = m2_mapped_nums[m2_index];
            mnums->mapped_indices[index] = m2_indices[m2_index];
            m2_index++;
        }
        index++;
    }

    while (m1_index < m1_size) {
        mnums->nums[index] = m1_nums[m1_index];
        mnums->mapped_nums[index] = m1_mapped_nums[m1_index];
        mnums->mapped_indices[index] = m1_indices[m1_index];
        m1_index++;
        index++;
    }

    while (m2_index < m2_size) {
        mnums->nums[index] = m2_nums[m2_index];
        mnums->mapped_nums[index] = m2_mapped_nums[m2_index];
        mnums->mapped_indices[index] = m2_indices[m2_index];
        m2_index++;
        index++;
    }
    return;
}

static void merge_sort(map_nums_t *mnums, int head, int end) {

    int middle = (head + end)/2;

    if (head < end) {
        merge_sort(mnums, head, middle);     
        merge_sort(mnums, middle+1, end);     
        merge_process(mnums, head, middle, end);
    }
    return;
}

static void map_nums_init(map_nums_t *mnums, int *mapping, int mappingSize, int *nums, int numsSize) {

    if (!mnums) {
        fprintf(stderr, "[%s] Invalid argument.", __func__);
        return;
    }

    mnums->mapping = mapping;
    mnums->mappingSize = mappingSize;
    mnums->nums = nums;
    mnums->numsSize = numsSize;
    mnums->mapped_nums = calloc(numsSize, sizeof(*mnums->mapped_nums));
    mnums->mapped_indices = calloc(numsSize, sizeof(*mnums->mapped_nums));

    for (int i = 0; i < mnums->numsSize; i++)
        mnums->mapped_indices[i] = i;

    return;
}

static int map_nums_mapping_convert(map_nums_t *mnums, char *str, int slen) {

    int val = 0;
    char ch = '\0';

    for (int i = 0; i < slen; i++) {
        ch = mnums->mapping[CH_TO_VAL(str[i])] + '0';
        str[i] = ch;
        val *= 10; 
        val += CH_TO_VAL(str[i]);
    }

    free(str);
    return val;
}

static void map_nums_process(map_nums_t *mnums) {

    if (!mnums)
        return; 

    char *str = NULL;

    for (int i = 0; i < mnums->numsSize; i++) {
        str = val_to_str(mnums->nums[i]);
        mnums->mapped_nums[i] = map_nums_mapping_convert(mnums, str, strlen(str));
        //printf("(%d, %d) ", mnums->mapped_nums[i], mnums->mapped_indices[i]);
    }
    //putchar('\n');

    merge_sort(mnums, 0, mnums->numsSize-1);

    return;
}

int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {

    map_nums_t mnums = {0};

    map_nums_init(&mnums, mapping, mappingSize, nums, numsSize);

    map_nums_process(&mnums);

    if (mnums.mapped_nums) 
        free(mnums.mapped_nums);

    if (mnums.mapped_indices) 
        free(mnums.mapped_indices);

    *returnSize = numsSize;
    return nums; 
}
