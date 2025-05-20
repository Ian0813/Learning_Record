/*
 * =====================================================================================
 *
 *       Filename:  1817_finding_the_users_active_minutes.c
 *
 *    Description:  finding the users active minutes
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

#define TABLE_SIZE 100001
#define ITEM_LEN 2

enum {
    ID_INDEX = 0,
    TIME_INDEX = 1
};

struct id_tracker {
   int cur_id;
   int count;
   int activities;
   int *table;
   int *result;
};

static void merge_operation(int **logs, int head, int middle, int end) {

    int a1Size = (middle-head)+1, a2Size = (end-middle);
    int a1[a1Size][ITEM_LEN], a2[a2Size][ITEM_LEN];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = a1_index; i < a1Size; i++) {
        memcpy(a1[i], logs[head+i], ITEM_LEN*sizeof(int));
    }

    for (int i = a2_index; i < a2Size; i++) {
        memcpy(a2[i], logs[middle+i+1], ITEM_LEN*sizeof(int));
    }

    while (a1_index < a1Size && a2_index < a2Size) {

        if (a1[a1_index][ID_INDEX] < a2[a2_index][ID_INDEX]) {
            memcpy(logs[index], a1[a1_index], ITEM_LEN*sizeof(int));
            index++, a1_index++;
        } else {
            memcpy(logs[index], a2[a2_index], ITEM_LEN*sizeof(int));
            index++, a2_index++;
        }
    }

    while (a1_index < a1Size) {
        memcpy(logs[index], a1[a1_index], ITEM_LEN*sizeof(int));
        index++, a1_index++;
    }

    while (a2_index < a2Size) {
        memcpy(logs[index], a2[a2_index], ITEM_LEN*sizeof(int));
        index++, a2_index++;
    }
    return;
}

static void merge_sort(int **logs, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(logs, head, middle);
        merge_sort(logs, middle+1, end);
        merge_operation(logs, head, middle, end);
    }
    return;
}

static void count_activities(struct id_tracker *record, int **logs, int logsSize) {

    for (int i = 0; i < logsSize; i++) {

        if (record->cur_id != logs[i][ID_INDEX]) {
            record->cur_id = logs[i][ID_INDEX];
            record->count++;
            if (record->activities)
                record->result[record->activities-1]++;
            record->activities = 0;
        }

        if (record->table[logs[i][TIME_INDEX]] < record->count) {
            record->table[logs[i][TIME_INDEX]] = record->count;
            record->activities++;
        }

        if (record->activities && i == logsSize-1)
            record->result[record->activities-1]++;
    }
    return;
}

int* findingUsersActiveMinutes(int** logs, int logsSize, int* logsColSize, int k, int* returnSize) {

    int *time_table = NULL;
    int *result = NULL;
    struct id_tracker record = {.cur_id = -1};

    if (logsSize) {

        time_table = (int *) calloc(TABLE_SIZE, sizeof(int));
        result = (int *) calloc(k, sizeof(int));
        *returnSize = k;

        record.table = time_table;
        record.result = result;
#if 0
        for (int i = 0; i < logsSize; i++) {
            printf("[%d, %d] ", logs[i][ID_INDEX], logs[i][TIME_INDEX]);
        }
        putchar('\n');
#endif
        merge_sort(logs, 0, logsSize-1);
        count_activities(&record, logs, logsSize);

#if 0
        for (int i = 0; i < logsSize; i++) {
            printf("[%d, %d] ", logs[i][ID_INDEX], logs[i][TIME_INDEX]);
        }
        putchar('\n');
#endif
        free(record.table);
    }
    return record.result;
}

