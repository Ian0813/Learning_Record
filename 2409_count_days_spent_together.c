/*
 * =====================================================================================
 *
 *       Filename:  2409_count_days_spent_together.c
 *
 *    Description:  count days spent together
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

#define DELIMITER "-"
#define MAX_MONTH 12
#define MARK_VISIT 1

typedef enum {
    ALICE_ARIVE = (1 << 1),
    ALICE_LEAVE = (1 << 2),
    BOB_ARIVE = (1 << 3),
    BOB_LEAVE = (1 << 4),
} visit_type;

typedef struct {
    int **months;
    int *month_days;
    int mlen;
} year_table;

static year_table *create_year_table(void) {

    const int days_info[MAX_MONTH] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    year_table *obj = NULL;

    obj = calloc(1, sizeof(year_table));
    obj->months = calloc(MAX_MONTH, sizeof(int *));
    obj->month_days = calloc(MAX_MONTH, sizeof(int));
    obj->mlen = MAX_MONTH;

    memcpy(obj->month_days, days_info, sizeof(days_info));

    for (int i = 0; i < MAX_MONTH; i++) {
        obj->months[i] = calloc(days_info[i], sizeof(int));         
    }
    return obj;
}

static bool day_register(year_table *obj, char *month_day, visit_type v) {

    if (!obj)
        return false;

    int m = 0, d = 0;
    char *ptr = NULL;

    ptr = strtok(month_day, DELIMITER);
    m = (int) strtoll(ptr, NULL, 10);
    ptr = strtok(NULL, DELIMITER);
    d = (int) strtoll(ptr, NULL, 10);
    obj->months[m-1][d-1] |= v;

    return true;
}

static int count_visit_day_range(year_table *obj) {

    int count = 0;
    bool alice_arrive = false, bob_arrive = false;

    if (!obj)
        return count;

    for (int i = 0; i < obj->mlen; i++) {
        for (int j = 0; j < obj->month_days[i]; j++) {
            alice_arrive = obj->months[i][j] & ALICE_ARIVE ? true : alice_arrive;
            bob_arrive = obj->months[i][j] & BOB_ARIVE ? true : bob_arrive;
            if (alice_arrive && bob_arrive)
                count++;
            alice_arrive = obj->months[i][j] & ALICE_LEAVE ? false : alice_arrive;
            bob_arrive = obj->months[i][j] & BOB_LEAVE ? false : bob_arrive;
        }
    }
    return count;
}

static void delete_year_table(year_table *obj) {

    if (obj) {

        for (int i = 0; i < obj->mlen; i++)
            free(obj->months[i]);
        free(obj->months);
        free(obj->month_days);
        free(obj);
    }
    return;
}

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {

    year_table *obj = NULL; 
    int result = 0;

    obj = create_year_table();  

    day_register(obj, arriveAlice, ALICE_ARIVE);
    day_register(obj, leaveAlice, ALICE_LEAVE);
    day_register(obj, arriveBob, BOB_ARIVE);
    day_register(obj, leaveBob, BOB_LEAVE);

    result = count_visit_day_range(obj); 

    delete_year_table(obj);

    return result;
}
