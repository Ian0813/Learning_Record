/*
 * =====================================================================================
 *
 *       Filename:  539_minimum_time_difference.c
 *
 *    Description:  Minimum time difference  
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

#define HOURS 24
#define MINUTES 60
#define CONVERT_FIELD 2

struct time_point {
    int val;
    int occur;
};

void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

void quick_sort(int *arr, int head, int end) {

    int front = head, tail = end - 1, last = head;

    if (front < tail) {

        while (last < tail) {
            if (arr[front] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[front], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

void time_toindex(char *timePoints, int *time_convert) {

    int val = 0, index = 0;    

    memset(time_convert, 0, sizeof(int) * CONVERT_FIELD);

    for (int i = 0; i < strlen(timePoints); i++) {
        if (timePoints[i] == ':') {
            index++;
            continue;
        }
        time_convert[index] *= 10; 
        val = (timePoints[i] - '0');
        time_convert[index] += val;
    }
    return;
}    

void fill_timetable(struct time_point time_table[][MINUTES]) {

    for (int i = 0; i < HOURS; i++) {
        for (int j = 0; j < MINUTES; j++) {
            time_table[i][j].val = (MINUTES * i) + j;
            //printf("time_table[%d][%d]: %d\n", i, j, time_table[i][j].val);
        }
    }
    return;
}

int findMinDifference(char** timePoints, int timePointsSize) {

    struct time_point time_table[HOURS][MINUTES] = {0};
    int time_convert[CONVERT_FIELD] = {0};
    int *timeval_arr = (int *) calloc(timePointsSize, sizeof(int));
    int *timeval_diff = (int *) calloc(timePointsSize, sizeof(int));
    int dindex = 0, minimum_diff = INT_MAX, overlap = 0;

    if (timePointsSize) {

        fill_timetable(time_table);

        for (int i = 0; i < timePointsSize; i++) {
            time_toindex(timePoints[i], time_convert);
            timeval_arr[i] = time_table[time_convert[0]][time_convert[1]].val; 
            time_table[time_convert[0]][time_convert[1]].occur++;
            //printf("timeval_arr[%d]: %d\n", i, timeval_arr[i]);
            if (time_table[time_convert[0]][time_convert[1]].occur > 1) {
                overlap = 1;
                break;
            }
        }

        if (!overlap) {

            quick_sort(timeval_arr, 0, timePointsSize); 

            for (int i = 0; i < timePointsSize; i++) {

                if (i == (timePointsSize - 1)) {
                    timeval_diff[i] = timeval_arr[0] - timeval_arr[i];
                } else {
                    timeval_diff[i] = timeval_arr[i+1] - timeval_arr[i];
                    if (timeval_diff[i] == 1) {
                        minimum_diff = 1; 
                        break;
                    }
                }
            }

            if (minimum_diff == INT_MAX) {

                for (int i = 0; i < timePointsSize; i++) {

                    timeval_diff[i] = timeval_diff[i] < 0 ? (-timeval_diff[i]) : timeval_diff[i];

                    if (timeval_diff[i] > (12*MINUTES)) {
                        timeval_diff[i] = (HOURS*MINUTES) - timeval_diff[i];    
                    }

                    if (timeval_diff[i] < minimum_diff) {
                        minimum_diff = timeval_diff[i];
                    }
                }
            }
        } else {
            minimum_diff = 0;
        }    
    }

    free(timeval_arr);
    free(timeval_diff);
    return minimum_diff;
}

int main(void) {

    char *timePoints[3] = {"00:00","23:59","00:01"};

    printf("minumum difference: %d\n", findMinDifference(timePoints, 3));

    return 0;
}
