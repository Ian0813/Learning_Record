/*
 * =====================================================================================
 *
 *       Filename:  826 most profit assigning work.c
 *
 *    Description:  most profit assigning work
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

#define TABLE_SIZE 100001

typedef struct {
    int min;
    int max; 
} difficulty_range;

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp; 
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end-1;     

    if (front < tail) {

        while (last < tail) {
            if (arr[head] < arr[tail]) {
                last++; 
                swap(&arr[last], &arr[tail]); 
                continue;
            }
            tail--;
        }
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

static int get_difficulty_level(int *difficulty, int head, int end, int worker) {

    int middle = (head+end)/2;

    if (head < end) {
        if (worker == difficulty[middle]) {
            return middle;
        } else if (worker > difficulty[middle]) {
            middle = get_difficulty_level(difficulty, middle+1, end, worker);
        } else if (worker < difficulty[middle]) {
            middle = get_difficulty_level(difficulty, head, middle, worker);
        }
    }
    return head;
}

static void profit_track(int *difficulty, int *profit, int profitSize, difficulty_range *profit_table) {

    for (int i = 0; i < profitSize; i++) {

        if (!profit_table[profit[i]].min) {
            profit_table[profit[i]].min = difficulty[i];
        }

        if (profit_table[profit[i]].min > difficulty[i]) {
            profit_table[profit[i]].min = difficulty[i];
        }

        if (profit_table[profit[i]].max < difficulty[i]) {
            profit_table[profit[i]].max = difficulty[i];
        }
    }
    return;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {

    int result = 0;
    int level = 0;
    difficulty_range profit_table[TABLE_SIZE] = {0};

    profit_track(difficulty, profit, profitSize, profit_table);

    quick_sort(profit, 0, profitSize);

    for (int i = 0; i < workerSize; i++) {


        for (int j = 0; j < profitSize; j++) {
            if (worker[i] >= profit_table[profit[j]].min) {
                result += profit[j];
                break;
            }
        }    
    }    
    return result;
}
