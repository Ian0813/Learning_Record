/*
 * =====================================================================================
 *
 *       Filename:  1331_rank_transform_of_an_array.c
 *
 *    Description:  rank transform of an array
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

struct arr_info {
    int *array;
    int *arr_indices;
    int *rank_counter; 
    int arrSize;
};

static void swap(int *v1, int *v2) {
    int temp = *v1; 

    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(struct arr_info *dup, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {
        while (last < tail) {
            if (dup->array[head] > dup->array[tail]) {
                last++;
                swap(&dup->array[last], &dup->array[tail]);
                swap(&dup->arr_indices[last], &dup->arr_indices[tail]);
                continue;
            }
            tail--;
        }
        swap(&dup->array[head], &dup->array[last]);
        swap(&dup->arr_indices[head], &dup->arr_indices[last]);
        quick_sort(dup, head, last);
        quick_sort(dup, last+1, end);
    }
    return;
}

static void fill_indices(int arrSize, int *arr_indices) {

    for (int i = 0; i < arrSize; i++) {
        arr_indices[i] = i;
    }
    return;
}

static void calculate_rank(struct arr_info *dup) {

    int count = 1;
    int index = 0;

    dup->rank_counter[dup->arr_indices[index++]] = count; 

    for (index; index < dup->arrSize; index++) {
        if (dup->array[index] != dup->array[index-1]) {
            count++;
        }    
        dup->rank_counter[dup->arr_indices[index]] = count;
    }
    return;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {

    struct arr_info dup = {NULL, .arrSize = arrSize};

    if (arrSize) {

        dup.array = (int *) calloc(arrSize, sizeof(int));
        dup.arr_indices = (int *) calloc(arrSize, sizeof(int));
        dup.rank_counter = (int *) calloc(arrSize, sizeof(int));

        memcpy(dup.array, arr, sizeof(int)*arrSize);
        fill_indices(arrSize, dup.arr_indices);

        quick_sort(&dup, 0, arrSize);
        calculate_rank(&dup);

		free(dup.array);
		free(dup.arr_indices);

        for (int i = 0; i < arrSize; i++) {
            printf("[%d] %d ", dup.arr_indices[i], dup.array[i]);
        }
        putchar('\n');
    }
    *returnSize = arrSize;
    return dup.rank_counter;
}
