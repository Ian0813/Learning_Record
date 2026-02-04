/*
 * =====================================================================================
 *
 *       Filename:  1385_find_the_distance_value_between_two_arrays.c
 *
 *    Description:  1385 find the distance value between two arrays
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

static int binary_search(int *arr, int head, int end, int target) {

    int middle = (head + end) / 2;
    int index = middle;

    if (head < end) {
        if (arr[middle] == target) {
            index = middle;
        } else if (arr[middle] > target) {
            index = binary_search(arr, head, middle, target);
        } else if (arr[middle] < target) {
            index = binary_search(arr, middle + 1, end, target);
        }
    }
    return index;
}    

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(int *arr, int head, int end) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {

            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }

        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last-1);
        quick_sort(arr, last + 1, end);
    }

    return;
}

static int get_closes(int base, int cp1, int cp2) {

    if (abs(base-cp1) > abs(base-cp2)) {
        return cp2;     
    }
    return cp1;
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {

    int count_distance = 0, index = 0, value = 0;

    quick_sort(arr2, 0, arr2Size-1);

    for (int i = 0; i < arr1Size; i++) {

        index = binary_search(arr2, 0, arr2Size, arr1[i]); 

        value = get_closes(arr1[i], index ? arr2[index-1] : arr2[index], index < arr2Size ? arr2[index] : arr2[index-1]); 

        if (abs(arr1[i]-value) > d)
            count_distance++;
    }

    return count_distance;
}
