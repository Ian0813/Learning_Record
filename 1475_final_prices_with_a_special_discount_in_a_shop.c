/*
 * =====================================================================================
 *
 *       Filename:  1475_final_prices_with_a_special_discount_in_a_shop.c
 *
 *    Description:  final prices with a special discount in a shop
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

int* finalPrices(int* prices, int pricesSize, int* returnSize) {

    int *result = NULL;
    int index = 0;
    int flag = 0;

    if (pricesSize) {

        result = (int *) calloc(pricesSize, sizeof(int));
        *returnSize = pricesSize;
        result[pricesSize-1] = prices[pricesSize-1];

        for (int i = 0; i < pricesSize-1; i++) {
            for (int j = i+1; j < pricesSize; j++) {
                if (prices[i] >= prices[j]) {
                    result[index++] = prices[i]-prices[j];
                    flag = 1; 
                    break;
                }
            }
            if (!flag) {
                result[index++] = prices[i]; 
            }
            flag = 0;
        }
    }
    return result;
}
