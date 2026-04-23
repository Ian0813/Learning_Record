/*
 * =====================================================================================
 *
 *       Filename:  3683_earliest_time_to_finish_one_task.c
 *
 *    Description:  earliest time to finish one task
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

typedef enum {false, true} bool;

enum {
    TASK_1 = 0,
    TASK_2 = 1
}; 

static void swap(int **p1, int **p2) {

    int *temp = *p1;

    *p1 = *p2;
    *p2 = temp;

    return;
}

static bool compare(int *t1, int *t2) {
    return (t1[TASK_1] + t1[TASK_2]) > (t2[TASK_1] + t2[TASK_2]);
}

static void quick_sort(int **tasks, int head, int end) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {
            if (compare(tasks[head], tasks[tail])) {
                last++;
                swap(&tasks[last], &tasks[tail]);
                continue;
            }
            tail--;
        }

        swap(&tasks[head], &tasks[last]);
        quick_sort(tasks, head, last-1);
        quick_sort(tasks, last+1, end);
    }
    return;
}

int earliestTime(int** tasks, int tasksSize, int* tasksColSize) {

    quick_sort(tasks, 0, tasksSize-1);

    return tasks[0][TASK_1] + tasks[0][TASK_2];
}
