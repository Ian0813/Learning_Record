/*
 * =====================================================================================
 *
 *       Filename:  1109_corporate_flight_bookings.c
 *
 *    Description:  corporate flight bookings
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
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int *cumulates;
    int csize;
} cumulate_table;

typedef enum {
    S_INDEX = 0,
    E_INDEX = 1,
    V_INDEX = 2,
} range_index_t;

static bool cumulate_table_init(cumulate_table *t, int size) {

    if (!t)
        return false;

    t->cumulates = calloc(size+1, sizeof(int)); 
    t->csize = size;

    return true;
}

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize) {

    cumulate_table table = {0};    

    if (cumulate_table_init(&table, n)) {
        for (int i = 0; i < bookingsSize; i++) {
            table.cumulates[bookings[i][S_INDEX]-1] += bookings[i][V_INDEX];
            table.cumulates[bookings[i][E_INDEX]] -= bookings[i][V_INDEX];
        }

        for (int i = 1; i < table.csize; i++) {
            table.cumulates[i] = table.cumulates[i] + table.cumulates[i-1];
        }
        *returnSize = table.csize;
    }
    return table.cumulates;
}
