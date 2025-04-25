/*
 * =====================================================================================
 *
 *       Filename:  888_fair_candy_swap.c
 *
 *    Description:  fair candy swap
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define RESULT_AMOUNT 2
#define TABLE_SIZE 100001

typedef enum {
    ALICE_INDEX = 0,
    BOB_INDEX = 1
} result_index_t;

struct candy_info {
    int total;
    int target;
    int table[TABLE_SIZE];
};

static void information_init(struct candy_info *info, int *arr, int arrSize) {

    if (info) {
        for (int i = 0; i < arrSize; i++) {
            info->table[arr[i]]++;
            info->total += arr[i];
        }
    }
    return;
}

static int get_target(int t1, int t2) {
    return (t1+t2)/2;
}

static void get_result(int *result, struct candy_info *ainfo, struct candy_info *binfo) {

    int diff = 0, exchange = 0;

    diff = abs(ainfo->target - ainfo->total);

    for (int i = diff+1; i < TABLE_SIZE; i++) {
        if (ainfo->target > ainfo->total) {
            if (binfo->table[i] && ainfo->table[i-diff]) {
                result[BOB_INDEX] = i;
                result[ALICE_INDEX] = i-diff;
                break;
            }
        } else {
            if (ainfo->table[i] && binfo->table[abs(i-diff)]) {
                result[ALICE_INDEX] = i;
                result[BOB_INDEX] = i-diff;
                break;
            }
        }
    }
    return;
}

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {

    struct candy_info alice_info = {0}, bob_info = {0};
    int *result = NULL;

    result = (int *) calloc(RESULT_AMOUNT, sizeof(int));

    information_init(&alice_info, aliceSizes, aliceSizesSize);
    information_init(&bob_info, bobSizes, bobSizesSize);

    alice_info.target = bob_info.target = get_target(alice_info.total, bob_info.total);
    get_result(result, &alice_info, &bob_info);
    *returnSize = RESULT_AMOUNT;

    return result;
}
