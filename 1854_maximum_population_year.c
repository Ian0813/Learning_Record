/*
 * =====================================================================================
 *
 *       Filename:  1854_maximum_population_year.c
 *
 *    Description:  maximum population year
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

#define BORN_INDEX (0)
#define DEAD_INDEX (1)

struct years_population {
    int *years_arr;
    int *population;
    int index;
};

static void swap(int *a1, int *a2) {

    int temp = *a1;

    *a1 = *a2;
    *a2 = temp;
    return;
}

static void quick_sort(int *years_arr, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {

        while (last < tail) {
            if (years_arr[head] > years_arr[tail]) {
                last++;
                swap(&years_arr[last], &years_arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&years_arr[head], &years_arr[last]);
        quick_sort(years_arr, head, last);
        quick_sort(years_arr, last+1, end);
    }
    return;
}

static void count_population(struct years_population *years_info, int **logs, int logsSize) {

    for (int i = 0; i < years_info->index; i++) {

        for (int j = 0; j < logsSize; j++) {
            if (years_info->years_arr[i] >= logs[j][BORN_INDEX] && years_info->years_arr[i] < logs[j][DEAD_INDEX]) {
                years_info->population[i]++;
            }
        }
    }
    return;
}

static void get_years_arr(int *years_arr, int **logs, int logsSize, int *index) {

    if (logs) {
        for (int i = 0; i < logsSize; i++) {
            years_arr[(*index)++] = logs[i][BORN_INDEX];
            years_arr[(*index)++] = logs[i][DEAD_INDEX];
        }
    }
    return;
}

static int get_year_max_population(int *years_arr, int *population, int size) {

    int max = 0;
    int year = 0;

    for (int i = 0; i < size; i++) {
        if (population[i] > max) {
            max = population[i];
            year = years_arr[i];
        }
    }
    return year;
}

int maximumPopulation(int** logs, int logsSize, int* logsColSize) {

    int result = 0;
    struct years_population years_info = {NULL};

    if (logsSize) {

        years_info.years_arr = (int *) calloc(logsSize*2, sizeof(int));
        years_info.population = (int *) calloc(logsSize*2, sizeof(int));
        get_years_arr(years_info.years_arr, logs, logsSize, &years_info.index);
        quick_sort(years_info.years_arr, 0, years_info.index);

        count_population(&years_info, logs, logsSize);

        result = get_year_max_population(years_info.years_arr, years_info.population, years_info.index);
        free(years_info.years_arr);
        free(years_info.population);
    }
    return result;
}
