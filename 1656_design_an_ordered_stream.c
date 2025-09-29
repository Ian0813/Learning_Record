/*
 * =====================================================================================
 *
 *       Filename:  1656 design an ordered stream.c
 *
 *    Description:  design an ordered stream
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

typedef struct {
    char **values;
    int cur_pos;
    int len;
} OrderedStream;

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void swap_ptr(void **p1, void **p2) {

    void *temp = NULL;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    return;
}

static void quick_sort(int *arr, int head, int end, char **ext) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;   
                swap(&arr[last], &arr[tail]);
                swap_ptr((void *) &ext[last], (void *) &ext[tail]);
                continue;
            }
            tail--;
        }

        swap(&arr[head], &arr[last]);
        swap_ptr((void *) &ext[head], (void *) &ext[last]);
        quick_sort(arr, head, last-1, ext);
        quick_sort(arr, last+1, end, ext);
    }

    return;
}

static int search_id(int *ids, int len, int key) {

    int pos = -1;

    if (ids) {
        for (int i = 0; i < len; i++) {
            if (ids[i] == key) {
                pos = i;
                break;
            }
        }
    }

    return pos; 
}

OrderedStream* orderedStreamCreate(int n) {

    OrderedStream *obj = NULL;
    obj = (OrderedStream *) malloc(sizeof(*obj));

    if (obj) {
        memset(obj, 0, sizeof(*obj));
        obj->values = (char **) calloc(n, sizeof(char *));
        obj->len = n;
        obj->cur_pos = 0;
    }

    return obj;
}

char** orderedStreamInsert(OrderedStream* obj, int idKey, char* value, int* retSize) {

    char **ptr = NULL;

    if (obj) {

        obj->values[idKey-1] = value;
        ptr = &obj->values[obj->cur_pos];
        *retSize = 0;

        for (int i = obj->cur_pos; i < obj->len; i++) {
            if (obj->values[i]) {
                *retSize += 1;
                obj->cur_pos +=1;
                continue;
            }
            break;
        }
    }

    return ptr;
}

void orderedStreamFree(OrderedStream* obj) {

    if (obj) {
        free(obj->values);
        free(obj);
    }

    return;
}

/**
 * Your OrderedStream struct will be instantiated and called as such:
 * OrderedStream* obj = orderedStreamCreate(n);
 * char** param_1 = orderedStreamInsert(obj, idKey, value, retSize);

 * orderedStreamFree(obj);
*/
