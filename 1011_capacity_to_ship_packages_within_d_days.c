/*
 * =====================================================================================
 *
 *       Filename:  1011_capacity_to_ship_packages_within_d_days.c
 *
 *    Description:  capacity to ship packages within d days
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
#include <limits.h>

typedef enum {false, true} bool;

typedef struct package_info {
    int *weights;
    int weightsSize;
    int max_weight;
    int days;
    int *day_array;
    int dlen;
    int total_sum;
} package_t;

typedef enum {
    B_DECREMENT = 0,
    B_INCREMENT = 1,
} boperation_t;

static bool check_is_satisfy(package_t *package, int max, int days, boperation_t *op) {

    int sum = 0, last_start = 0, temp = package->total_sum, count = 1;

    if (max < package->max_weight) {
        *op = B_INCREMENT;
        return false;
    } else {

        for (int i = 0; i < package->weightsSize; i++) {

            if ((sum+package->weights[i]) <= max) {
                sum += package->weights[i];
            } else {
                last_start = i;
                temp -= sum;
                sum = package->weights[i];
                count++;
            }
        }

        if (count <= days) {
            *op = B_DECREMENT;
        } else {
            *op = B_INCREMENT;
        }
    }

    return count <= days ? true : false;
}

static int binary_search(int head, int end, struct package_info *package) {

    int middle = (head+end)/2;
    int value = 0, count = 0;
    boperation_t op;

    if (head < end && package) {

        if (check_is_satisfy(package, middle, package->days, &op)) {
            package->day_array[package->dlen++] = middle;
        }

        if (op == B_DECREMENT) {
            value = binary_search(head, middle, package);
        } else if (op == B_INCREMENT) {
            value = binary_search(middle+1, end, package);
        }
    }
    return value;
}

static int get_range_sum(int *arr, int head, int end) {

    int sum = 0;

    if (head <= end) {
        for (int i = head; i <= end; i++) {
            sum += arr[i];
        }
    }
    return sum;
}

static int get_max_weight(int *arr, int arrSize) {

    int max = 0;

    for (int i = 0; i < arrSize; i++) {
        max = max < arr[i] ? arr[i] : max;
    }
    return max;
}

static int get_minimum(int *arr, int len) {

    int minimum = INT_MAX;

    for (int i = 0; i < len; i++) {
        if (minimum > arr[i]) {
            minimum = arr[i];
        }
    }
    return minimum;
}

int shipWithinDays(int* weights, int weightsSize, int days) {

    int start = 1, end = 0;
    int result = 0;

    package_t package = {.weights = weights, .weightsSize = weightsSize, .days = days, .dlen = 0};

    if (weightsSize) {
        package.day_array = (int *) calloc(BUFSIZ, sizeof(int));
        package.total_sum = end = get_range_sum(weights, 0, weightsSize-1);
        package.max_weight = get_max_weight(weights, weightsSize);
        binary_search(start, end+1, &package);
        result = get_minimum(package.day_array, package.dlen);
        free(package.day_array);
    }
    return result;
}
