/*
 * =====================================================================================
 *
 *       Filename:  121_best_time_to_buy_and_sell_stock.c
 *
 *    Description:  Best time to buy and sell stock  
 *
 *         Author:  Ian
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int maxProfit(int* prices, int pricesSize) {

    int profit = 0, diff = 0;

	for (int i = 0; i < pricesSize; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[i] < prices[j]) {
                diff = prices[j] - prices[i];
                if (profit < diff) {
                    profit = diff;
				}
			} else {
			    break;
			}
		}
	}
	return profit;
}


int main(void) {

    int arr[] = {7, 6, 5, 4, 3, 2, 1};

    printf("maxProfit: %d\n", maxProfit(arr, sizeof(arr)/sizeof(int)));
	printf("size: %ld\n", sizeof(arr)/sizeof(int));

	return 0;
}

