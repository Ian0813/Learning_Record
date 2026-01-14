/*
 * =====================================================================================
 *
 *       Filename:  1962_remove_stones_to_minimize_the_total.c
 *
 *    Description:  remove stones to minimize the total
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
#include <time.h>
#include <sys/random.h>
#include <math.h>

#define ARR_SIZE 32 
#define MAX_ADDR(v1, v2) ((v1) > (v2) ? &(v1) : &(v2))
#define CHECK_BOUNDARY(pos, boundary) (((pos)+1) < boundary || ((pos)+2) < boundary)

#define BOUNDARY_SUPPRESS(arr, arrlen, boundary) \
for (int i = 0; i < arrlen; i++)\
    arr[i] = (arr[i] % boundary);

typedef enum {false, true} bool;

static void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;

    return;
}

static void merge_process(int *arr, int head, int middle, int end) {

    int a1_size = (middle - head) + 1, a2_size = (end - middle);
    int a1[a1_size], a2[a2_size];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = 0; i < a1_size; i++)
        a1[i] = arr[head + i]; 

    for (int i = 0; i < a2_size; i++)
        a2[i] = arr[middle + i + 1]; 

    while (a1_index < a1_size && a2_index < a2_size) {
        if (a1[a1_index] > a2[a2_index]) {
            arr[index++] = a1[a1_index++]; 
        } else {
            arr[index++] = a2[a2_index++]; 
        }
    }

    while (a1_index < a1_size) {
        arr[index++] = a1[a1_index++];
    }

    while (a2_index < a2_size) {
        arr[index++] = a2[a2_index++];
    }
    return;
}

static void merge_sort(int *arr, int head, int end) {

    int middle = (head+end) / 2;

    if (head < end) {
        merge_sort(arr, head, middle);
        merge_sort(arr, middle + 1, end);
        merge_process(arr, head, middle, end);
    }

    return;
}

static void heap_move_down(int *arr, int arrlen, int pos) {

    int target = 0;
    int double_pos = pos * 2;
    
    while (arr && CHECK_BOUNDARY(double_pos, arrlen)) {

        if (((double_pos)+2) >= arrlen) {
            target = (double_pos) + 1;
        } else {
            target = arr[double_pos+1] > arr[double_pos+2] ? (double_pos + 1) : (double_pos + 2);
        }

        if (arr[pos] < arr[target]) {
            swap(&arr[pos], &arr[target]);
            pos = target;
            double_pos = pos * 2;
            continue;
        }
        break;
    }
    return;
}

int minStoneSum(int* piles, int pilesSize, int k) {

    int minsum = 0;

    merge_sort(piles, 0, pilesSize - 1);

    do {
        piles[0] -= ((int) ceil(piles[0]/2));
        heap_move_down(piles, pilesSize, 0); 
        k--;
    } while (k);

    for (int i = 0; i < pilesSize; i++) {
        minsum += piles[i];
    }

    return minsum;
}
