/*
 * =====================================================================================
 *
 *       Filename:  1636_sort_array_by_increasing_frequency.c
 *
 *    Description:  Sort array by increasing frequency 
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

#define TABLE_SIZE 201
#define INDEX_MAP(val) (val > 0 ? val : ((-val)+100))
#define SWAP_FUNC(n1, n2) {typeof(n1) temp = n1; n1 = n2; n2 = temp;}
#define typeof __typeof__

void quick_sort(int *nums, int head, int end, int *table) {

    int front = head, tail = end - 1, last = head;

    if (head < end) {
        while (last < tail) {
            if (table[INDEX_MAP(nums[head])] > table[INDEX_MAP(nums[tail])]) {
                last++;
                SWAP_FUNC(nums[last], nums[tail]);
            } else if (table[INDEX_MAP(nums[head])] == table[INDEX_MAP(nums[tail])] 
                       && nums[head] < nums[tail]) {
                last++;
                SWAP_FUNC(nums[last], nums[tail]);
            } else {
               tail--;
            }
        }
        SWAP_FUNC(nums[head], nums[last]);
        quick_sort(nums, head, last, table);
        quick_sort(nums, last+1, end, table);
    }
    return;
}

void count_frequency(int *table, int *nums, int numsSize) {

    for (int i = 0; i < numsSize; i++) {
        table[INDEX_MAP(nums[i])]++;
    }
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int* nums, int numsSize, int* returnSize) {

    int table[TABLE_SIZE] = {0};
    int *result = (int *) calloc(numsSize, sizeof(int));

    count_frequency(table, nums, numsSize);
    quick_sort(nums, 0, numsSize, table);

    memcpy(result, nums, numsSize * sizeof(int));
    return result;
}

int main(void) {
    return EXIT_SUCCESS;
}
