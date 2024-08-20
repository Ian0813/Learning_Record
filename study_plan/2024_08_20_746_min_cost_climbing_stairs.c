/*
 * =====================================================================================
 *
 *       Filename:  2024_08_20_746_min_cost_climbing_stairs.c
 *
 *    Description:  Min cost climbing stairs  
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

int minCostClimbingStairs(int* cost, int costSize) {

    int amount = 0, index = 0;
    int *dp = (int *) calloc(costSize, sizeof(int));

    dp[costSize-1] = cost[costSize-1];
    dp[costSize-2] = cost[costSize-2];

    for (int i = costSize-3; i >= 0; i--) {
        dp[i] = cost[i] + (dp[i+1] > dp[i+2] ? dp[i+2] : dp[i+1]);
    }

    amount = dp[0] < dp[1] ? dp[0] : dp[1];
    printf("amount: %d\n", amount);
    free(dp);

    return amount; 
}

int main(void) {

    int cost[] = {0,2,3,2};
    int amount = minCostClimbingStairs(cost, sizeof(cost)/sizeof(*cost));

    printf("amount: %d\n", amount);

    return EXIT_SUCCESS;
}
