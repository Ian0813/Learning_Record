/*
 * =====================================================================================
 *
 *       Filename:  2526_find_consecutive_integers_from_a_data_stream.c
 *
 *    Description:  find consecutive integers from a data stream
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

typedef struct {
    int target_val;
    int occur_count;
    int consec_goal;
} DataStream;

DataStream* dataStreamCreate(int value, int k) {

    DataStream *obj = calloc(1, sizeof(DataStream));

    if (obj) {
        obj->consec_goal = k;
        obj->target_val = value;
        obj->occur_count = 0;
    }
    return obj;
}

bool dataStreamConsec(DataStream* obj, int num) {

    if (!obj)
        return false;

    if (obj->target_val == num) {
        obj->occur_count++;
    } else {
        obj->occur_count = 0;
    }

    if (obj->occur_count >= obj->consec_goal)
        return true;
    return false;
}

void dataStreamFree(DataStream* obj) {

    if (!obj)
        free(obj);
    return;
}

/**
 * Your DataStream struct will be instantiated and called as such:
 * DataStream* obj = dataStreamCreate(value, k);
 * bool param_1 = dataStreamConsec(obj, num);

 * dataStreamFree(obj);
*/
