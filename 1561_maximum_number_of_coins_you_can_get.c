/*
 * =====================================================================================
 *
 *       Filename:  1561_maximum_number_of_coins_you_can_get.c
 *
 *    Description:  Maximum number of coins you can get  
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

#define UNIT_NUMBER 3
#define ROUND_SIZE 2

static void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *piles, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {
         while (last < tail) {
             if (piles[head] > piles[tail]) {
                 last++; 
                 swap(&piles[last], &piles[tail]);
                 continue;
             }
             tail--;
         }
         swap(&piles[head], &piles[last]);
         quick_sort(piles, head, last);
         quick_sort(piles, last+1, end);
    }
    return;
}

static int get_second_large_num(int *piles, int *end) {

    int num = 0;         

    num = piles[*end-1];

    *end -= ROUND_SIZE;

    return num;
}

int maxCoins(int* piles, int pilesSize) {

    int earn = 0;
    int size = pilesSize - (pilesSize/UNIT_NUMBER);
    int end_index = pilesSize - 1;

    if (pilesSize) {

        quick_sort(piles, 0, pilesSize);

        while (size) {
            earn += get_second_large_num(piles, &end_index);           
            size -= ROUND_SIZE; 
        }
    }
    return earn;
}
