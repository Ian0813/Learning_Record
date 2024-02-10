/*
 * =====================================================================================
 *
 *       Filename:  1833_maximum_ice_cream_bars.c
 *
 *    Description:  Maximum ice cream bars  
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

#define MAX 100001

int maxIceCream(int* costs, int costsSize, int coins) {

    int cost_table[MAX] = {0};
    int count = 0;

    for (int i = 0; i < costsSize; i++) {
        cost_table[costs[i]]++;
    }

    for (int i = i; i < MAX; i++) {
        while (cost_table[i]) {
            if (coins >= i) {
                coins -= i;
                cost_table[i]--;
                count++;
                continue;
            }
            break;
        }
        if (cost_table[i])
            break;
    }
    return count;
}

int main(void) {
    return EXIT_SUCCESS;
}
