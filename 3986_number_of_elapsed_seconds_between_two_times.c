/*
 * =====================================================================================
 *
 *       Filename:  3986_number_of_elapsed_seconds_between_two_times.c
 *
 *    Description:  number of elapsed seconds between two times
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
#include <stdbool.h>
#include <ctype.h>

#define CH_TO_VAL(ch) (isdigit((ch)) ? (ch-'0') : -1)

typedef struct {
    int hour;   
    int minute;
    int second;
} time_division;

static int str_to_val(char *ptr, int plen) {

    int val = 0;

    for (int i = 0; i < plen; i++) {
        val *= 10;
        if (CH_TO_VAL(ptr[i]) != -1) {
            val += CH_TO_VAL(ptr[i]); 
        }
    }
    return val;
}

static bool convert_to_time_division(char *timestr, time_division *obj) {

    char *ptr = NULL, *delimiter = ":";

    if (!obj)
        return false;

    ptr = strtok(timestr, delimiter);
    if (!ptr)
        return false;
    obj->hour = str_to_val(ptr, strlen(ptr));

    ptr = strtok(NULL, delimiter);
    if (!ptr)
        return false;
    obj->minute = str_to_val(ptr, strlen(ptr));

    ptr = strtok(NULL, delimiter);
    if (!ptr)
        return false;
    obj->second = str_to_val(ptr, strlen(ptr));

    return true;
}

int secondsBetweenTimes(char* startTime, char* endTime) {

    time_division start_obj = {0}, end_obj = {0};
    unsigned int start_sec = 0, end_sec = 0;

    convert_to_time_division(startTime, &start_obj);
    convert_to_time_division(endTime, &end_obj);

    start_sec += ((start_obj.hour * 60U * 60U) + (start_obj.minute * 60U) + start_obj.second);
    end_sec += ((end_obj.hour * 60U * 60U) + (end_obj.minute * 60U) + end_obj.second);

    return (int) (end_sec - start_sec);
}

