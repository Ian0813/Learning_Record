/*
 * =====================================================================================
 *
 *       Filename:  2037_minimum_number_of_moves_to_seat_everyone.c
 *
 *    Description:  minimum number of moves to seat everyone
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

static void merge_operation(int *arr, int head, int middle, int end) {

    int a1Size = (middle-head)+1, a2Size = end-middle;
    int a1[a1Size], a2[a2Size];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = a1_index; i < a1Size; i++) {
        a1[i] = arr[i+head];
    }

    for (int i = a2_index; i < a2Size; i++) {
        a2[i] = arr[i+middle+1];
    }

    while (a1_index < a1Size && a2_index < a2Size) {
        if (a1[a1_index] > a2[a2_index]) {
            arr[index++] = a2[a2_index++]; 
        } else {
            arr[index++] = a1[a1_index++]; 
        }
    }

    while (a1_index < a1Size)  {
        arr[index++] = a1[a1_index++];
    }

    while (a2_index < a2Size)  {
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

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {

    int steps = 0;

    if (seatsSize == studentsSize) {

        merge_sort(seats, 0, seatsSize-1);
        merge_sort(students, 0, studentsSize-1);

        for (int i = 0; i < seatsSize; i++) {
            steps += abs(seats[i]-students[i]);
        }
    }

    return steps;
}

