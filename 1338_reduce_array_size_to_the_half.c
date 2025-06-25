/*
 * =====================================================================================
 *
 *       Filename:  1338_reduce_array_size_to_the_half.c
 *
 *    Description:  reduce array size to the half
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

#define TABLE_SIZE 100001

static void get_frequencies(int *arr, int arrSize, int *table) {
    for (int i = 0; i < arrSize; i++) {
        table[arr[i]]++;
    }
    return;
}

static void merge_operation(int *arr, int head, int middle, int end, int *table) {

    int a1Size = (middle-head)+1, a2Size = (end-middle);
    int a1[a1Size], a2[a2Size];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = a1_index; i < a1Size; i++) {
        a1[i] = arr[head+i];
    }

    for (int i = a2_index; i < a2Size; i++) {
        a2[i] = arr[middle+i+1];
    }

    while (a1_index < a1Size && a2_index < a2Size) {
        if (table[a1[a1_index]] > table[a2[a2_index]]) {
            arr[index++] = a1[a1_index++];
        } else {
            arr[index++] = a2[a2_index++];
        }
    }

    while (a1_index < a1Size) {
        arr[index++] = a1[a1_index++];
    }

    while (a2_index < a2Size) {
        arr[index++] = a2[a2_index++];
    }

    return;
}

static void merge_sort(int *arr, int head, int end, int *table) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(arr, head, middle, table);
        merge_sort(arr, middle+1, end, table);
        merge_operation(arr, head, middle, end, table);
    }

    return;
}

static int remove_integer(int *arr, int arrSize, int *table) {

    int amount = 0;
    int count = 0, prev = 0;
    int lower_bound = !(arrSize%2) ? (arrSize/2) : (arrSize/2)+1;

    for (int i = 0; i < arrSize; i += table[prev]) {

        prev = arr[i];
        count++;
        amount += table[arr[i]];

        if (amount >= lower_bound) {
            break;
        }
    }
    return count;
}

int minSetSize(int* arr, int arrSize) {

    int table[TABLE_SIZE] = {0};
    int count = 0;

    get_frequencies(arr, arrSize, table);
    merge_sort(arr, 0, arrSize-1, table);
    count = remove_integer(arr, arrSize, table);

    return count;
}
