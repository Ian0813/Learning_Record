/*
 * =====================================================================================
 *
 *       Filename:  1491_average_salary_excluding_the_minimum_and_maximum_salary.c
 *
 *    Description:  average salary excluding the minimum and maximum salary
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

static void merge_operation(int *arr, int head, int middle, int end) {

    int a1_size = (middle-head)+1, a2_size = end - middle;
    int a1[a1_size], a2[a2_size];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = 0; i < a1_size; i++) {
        a1[i] = arr[head+i];
    }

    for (int i = 0; i < a2_size; i++) {
        a2[i] = arr[middle+i+1];
    }

    while (a1_index < a1_size && a2_index < a2_size) {
        if (a1[a1_index] < a2[a2_index]) {
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

    int middle = (head+end)/2; 

    if (head < end) {
        merge_sort(arr, head, middle);
        merge_sort(arr, middle+1, end);
        merge_operation(arr, head, middle, end);
    }

    return;
}

double average(int* salary, int salarySize) {

    double rc = 0.0;

    if (salarySize > 2) {

        merge_sort(salary, 0, salarySize-1);

        for (int i = 1; i < (salarySize-1); i++) {
            rc += (salary[i] * 1.0);
        }

        rc /= ((salarySize-2) * 1.0);
    }

    return rc;
}
