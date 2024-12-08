/*
 * =====================================================================================
 *
 *       Filename:  2446_determine_if_two_events_have_conflict.c
 *
 *    Description:  determine if two events have conflict
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

typedef enum {false, true} bool;

enum {
    START_INDEX = 0,
    END_INDEX = 1,
};

struct time_seconds {
    unsigned int start;
    unsigned int end;
};

int convert_to_sec(char *str) {

    int sec = 0;
    char *ptr = NULL, *remain = NULL;

    ptr = strtok_r(str, ":", &remain);

    sec += strtol(ptr, NULL, 10);
    sec *= 60;
    sec += strtol(remain, NULL, 10);

    printf("sec: %d\n", sec);

    return sec;
}

static void event_second(char **event, int size, struct time_seconds *sec) {

    for (int i = 0; i < size; i++) {
        if (i == START_INDEX) {
            sec->start = convert_to_sec(event[i]);  
        } else {
            sec->end = convert_to_sec(event[i]);  
        }
    }
    return;
}    

bool haveConflict(char** event1, int event1Size, char** event2, int event2Size) {

    struct time_seconds e1 = {0}, e2 = {0};
    bool result = false;

    event_second(event1, event1Size, &e1);
    event_second(event2, event2Size, &e2);

    if (e1.end >= e2.start && e2.end >= e1.start)
        result = true;
    else if (e2.start < e1.end && e2.end >= e1.start)
        result = true;    

    return result;
}

