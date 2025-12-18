/*
 * =====================================================================================
 *
 *       Filename:  2110_number_of_smooth_descent_periods_of_a_stock.c
 *
 *    Description:  number of smooth descent periods of a stock
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>

typedef enum {false, true} bool; 

typedef struct {
    int len;
    int cur_mini;
    int start_index;
    long long count;
} price_list;

static void count_descent_periods(price_list *list_ptr, int *prices, int pricesSize, int index) {

    int boundary = list_ptr->len;;

    if (index < pricesSize) {

        if (list_ptr->cur_mini == (prices[index] + 1)) {
            list_ptr->count += (index - list_ptr->start_index); 
        } else {
            list_ptr->start_index = index;
        }

        list_ptr->cur_mini = prices[index];
        list_ptr->count++;

        count_descent_periods(list_ptr, prices, pricesSize, index+1);
    }
    return;
}

long long getDescentPeriods(int* prices, int pricesSize) {

    long long count = 0L;
    price_list list_ptr = {.cur_mini = INT_MAX, .start_index = 0};

    count_descent_periods(&list_ptr, prices, pricesSize, 0);
    count = list_ptr.count;

    return count;
}
