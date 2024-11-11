/*
 * =====================================================================================
 *
 *       Filename:  1122_relative_sort_array.c
 *
 *    Description:  relative_sort_array
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef enum {false, true} bool;

#define TABLE_SIZE 1001

static void swap(int *v1, int *v2) {
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp; 
    return;
}

static void table_recorder(int *arr, int arrSize, int *table) {

   for (int i = 0; i < arrSize; i++) {
        table[arr[i]] = i+1;
   } 
   return;
}

static void quick_sort(int *arr, int head, int end, int *table) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {
        while (last < tail) {
            if (!table) {
                if (arr[head] > arr[tail]) {
                    last++;
                    swap(&arr[last], &arr[tail]);
                    continue;
                }
            } else {
                if (table[arr[head]] > table[arr[tail]]) {
                    last++;
                    swap(&arr[last], &arr[tail]);
                    continue;
                }
            }    
            tail--;
        }        
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last, table);
        quick_sort(arr, last+1, end, table);
    }
    return;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {

    int *result = NULL;
    int table1[TABLE_SIZE] = {0}, table2[TABLE_SIZE];
    int in_array[TABLE_SIZE] = {0}, out_array[TABLE_SIZE] = {0};
    int out_index = 0, in_index = 0;

    result = (int *) calloc(arr1Size, sizeof(int));

    table_recorder(arr2, arr2Size, table2);
    table_recorder(arr1, arr1Size, table1);

    for (int i = 0; i < arr1Size; i++) {
        if (!table2[arr1[i]] && table1[arr1[i]]) {
            out_array[out_index++] = arr1[i];
        }
    }

    for (int i = 0; i < arr1Size; i++) {
        if (table2[arr1[i]])
            in_array[in_index++] = arr1[i];
    }

    quick_sort(out_array, 0, out_index, NULL);
    quick_sort(in_array, 0, in_index, table2);

    memcpy(result, in_array, in_index*sizeof(int));
    memcpy(result+in_index, out_array, out_index*sizeof(int));

    *returnSize = arr1Size;

    return result;
}

int main(void) {

    int *ptr = NULL, len = 0;
    int arr1[] = {2,21,43,38,0,42,33,7,24,13,12,27,12,24,5,23,29,48,30,31}, arr2[] = {2,42,38,0,43,21};

    printf("%s\n", __DATE__);

    ptr = relativeSortArray(arr1, sizeof(arr1)/sizeof(*arr1), arr2, sizeof(arr2)/sizeof(*arr2), &len);

    for (int i = 0; i < len; i++) {
        printf("%d ", ptr[i]);
    }
    putchar('\n');
    free(ptr);

    return EXIT_SUCCESS;
}

