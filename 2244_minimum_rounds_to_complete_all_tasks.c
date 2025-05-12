/*
 * =====================================================================================
 *
 *       Filename:  2244_minimum_rounds_to_complete_all_tasks.c
 *
 *    Description:  minimum rounds to complete all tasks
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

static void merge_operation (int *tasks, int head, int middle, int end) {

    int arr1Size = middle-head+1, arr2Size = end-middle;
    int arr1[arr1Size], arr2[arr2Size];
    int a1index = 0, a2index = 0, index = head;

    memset(arr1, 0, sizeof(int) *arr1Size);
    memset(arr2, 0, sizeof(int) *arr2Size);

    for (int i = a1index; i < arr1Size; i++) {
        arr1[i] = tasks[head+i];
    }

    for (int i = a2index; i < arr2Size; i++) {
        arr2[i] = tasks[middle+i+1];
    }

    while (a1index < arr1Size && a2index < arr2Size) {
        if (arr1[a1index] < arr2[a2index]) {
            tasks[index++] = arr1[a1index++];
        } else {
            tasks[index++] = arr2[a2index++];
        }
    }

    while (a1index < arr1Size) {
        tasks[index++] = arr1[a1index++];
    }

    while (a2index < arr2Size) {
        tasks[index++] = arr2[a2index++];
    }
    return;
}

static void merge_sort (int *tasks, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(tasks, head, middle);
        merge_sort(tasks, middle+1, end);
        merge_operation(tasks, head, middle, end);
    }
    return;
}

static int get_rounds(int amount) {

    int rounds = 0;

    while (amount >= 2 && (amount%3)) {
        amount -= 2;
        rounds++;
    }

    while (amount >= 3) {
        amount -= 3;
        rounds++;
    }

    if (amount)
        rounds = -1;

    return rounds;
}

static int calculate_rounds(int *tasks, int tasksSize) {

    int amount = 0, total = 0, temp = 0;

    if (tasksSize) {

        amount = 1;

        for (int i = 0; i < tasksSize-1; i++) {
            if (tasks[i] == tasks[i+1]) {
                amount += 1;
            } else {
                if ((temp = get_rounds(amount)) == -1) {
                    total = -1;
                    break;
                }
                total += temp;
                amount = 1;
            }
        }
        temp = get_rounds(amount);
        total = temp == -1 ? temp : temp+total;
    }
    return total;
}

int minimumRounds(int* tasks, int tasksSize) {

    int rounds = 0;

    if (tasksSize) {
        merge_sort(tasks, 0, tasksSize-1);
        rounds = calculate_rounds(tasks, tasksSize);
    }
    return rounds;
}
