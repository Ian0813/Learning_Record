/*
 * =====================================================================================
 *
 *       Filename:  406_queue_reconstruction_by_height.c
 *
 *    Description:  queue reconstruction by height
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define PAIRLEN 2

enum {
    INDEX_H = 0,
    INDEX_W = 1
};

typedef struct pointer_info {
    int *ptr; 
    struct pointer_info *next;
} pointer_info;

static void swap_ptr(int **p1, int **p2) {

    int *temp = *p1;

    *p1 = *p2;
    *p2 = temp;

    return;
}    

static void quick_sort(int **arr, int head, int end) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {

            if (arr[head][INDEX_W] > arr[tail][INDEX_W]) {
                last++;
                swap_ptr(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }

        swap_ptr(&arr[head], &arr[last]);
        quick_sort(arr, head, last - 1);
        quick_sort(arr, last + 1, end);
    }
    return;
}    

static int *allocate_list(int len, int fillin) {

    int *ptr = NULL;

    ptr = (int *) calloc(len, sizeof(int));

    for (int i = 0; i < len; i++) {
        ptr[i] = fillin;
    }

    return ptr;
}

static void pointer_insert(pointer_info **ptr, int *value) {

    pointer_info *temp = NULL, *value_ptr = NULL, *last_ptr = NULL;
    int count = 0;

    if (!ptr)
        return;  

    temp = *ptr;
    value_ptr = (pointer_info *) calloc(1, sizeof(pointer_info)); 

    value_ptr->ptr = value;
    value_ptr->next = NULL;

    if (!value[INDEX_W]) {

        while (!temp->ptr[INDEX_W] && temp->ptr[INDEX_H] < value[INDEX_H]) {

            last_ptr = temp;
            temp = temp->next; 

            if (!temp)
                break;
        }

        if (temp) {
            value_ptr->next = temp; 
        }

        if (temp == *ptr)
            *ptr = value_ptr;
        else
            last_ptr->next = value_ptr; 
    } else {

        count = value[INDEX_W];

        while (count && temp) {
            if (temp->ptr[INDEX_H] >= value[INDEX_H]) {
                count--;
            }
            last_ptr = temp;
            temp = temp->next;
        }    

        if (temp) {
            while (temp && temp->ptr[INDEX_H] < value[INDEX_H]) {
                last_ptr = temp;
                temp = temp->next; 
            }
        }

        last_ptr->next = value_ptr;

        if (temp) {
            value_ptr->next = temp;     
        }
    }
    return;
}

static void pointer_free(pointer_info *head) {

    if (head) {
        pointer_free(head->next);
        free(head);
    }
    return;
}

int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes) {

    pointer_info *head = NULL, *info = NULL;
    int **result = NULL, rindex = 0;

    if (peopleSize) {

        *returnSize = peopleSize; 
        result = (int **) calloc(peopleSize, sizeof(int *));
        *returnColumnSizes = allocate_list(peopleSize, PAIRLEN);
        quick_sort(people, 0, peopleSize - 1);

        head = (pointer_info *) malloc(sizeof(*head)); 
        head->ptr = people[0];
        head->next = NULL;

        for (int i = 1; i < peopleSize; i++) {
            pointer_insert(&head, people[i]);            
        }

        info = head; 

        while (info) {
            result[rindex++] = info->ptr; 
            info = info->next;
        }
        pointer_free(head);
    }
    return result;
}
