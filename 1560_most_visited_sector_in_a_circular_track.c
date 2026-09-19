/*
 * =====================================================================================
 *
 *       Filename:  1560_most_visited_sector_in_a_circular_track.c
 *
 *    Description:  most visited sector in a circular track
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int *visit_count;
    int vsize;
    int max_visits;
    int max_count; 
} visitor_table;

static visitor_table *table_init(int size) {

    visitor_table *obj = NULL;

    obj = calloc(1, sizeof(*obj));

    if (obj) {
        obj->visit_count = calloc(size, sizeof(int));
        obj->vsize = size;
        obj->max_visits = 0;
    }
    return obj;
}

static void table_display(visitor_table *obj) {

    if (!obj)
        return;

    for (int i = 0; i < obj->vsize; i++) {
        printf("value : %d, count : %d\n", i, obj->visit_count[i]);
    }
   
    return;
}

static void table_expand(visitor_table *obj, int *rounds, int roundsSize, int boundary) {

    int *expand = NULL, eindex = 0, last = -1, start = 0, end = 0;

    if (!obj)
        return;

    expand = (int *) calloc(10000, sizeof(int));

    for (int i = 0; i < roundsSize-1; i++) {

        start = rounds[i];
        end = rounds[i+1];

        while (start != end) {
            expand[eindex++] = start;
            start = !((start+1)%boundary) ? 1 : (start+1);
        }
    }

    expand[eindex++] = end;

    for (int i = 0; i < eindex; i++) {
        printf("%d ", expand[i]); 
        obj->visit_count[expand[i]]++;

        if (obj->max_visits == obj->visit_count[expand[i]])
            obj->max_count++;

        if (obj->max_visits < obj->visit_count[expand[i]]) {
            obj->max_visits = obj->visit_count[expand[i]];
            obj->max_count = 1;
        }

    }
    putchar('\n');

    free(expand);

    return; }

static int *table_get_maxlist(visitor_table *obj) {

    int *ptr = NULL, pindex = 0;

    if (!obj)
        return ptr;

    ptr = calloc(obj->max_count, sizeof(int));

    for (int i = 0; i < obj->vsize; i++) {
        if (obj->visit_count[i] == obj->max_visits) {
            ptr[pindex++] = i; 
        }
    }
    return ptr;
}

static void table_free(visitor_table *obj) {

    if (!obj)
        return;

    free(obj->visit_count);
    free(obj);

    return;
}

int* mostVisited(int n, int* rounds, int roundsSize, int* returnSize) {

    visitor_table *obj = NULL;  
    int *result = NULL;

    obj = table_init(n+1);

    table_expand(obj, rounds, roundsSize, n+1);
    result = table_get_maxlist(obj);
    *returnSize = obj->max_count; 

    table_free(obj);

    return result;
}
