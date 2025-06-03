/*
 * =====================================================================================
 *
 *       Filename:  551_student_attendance_record_i.c
 *
 *    Description:  student attendance record i
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

#define CH_TO_INT(ch) ((ch)-'A') 
#define TABLE_SIZE 26 

enum {
    MAX_ABSENT = 2,
    MAX_LATE = 3
};

bool checkRecord(char* s) {

    int tracker[TABLE_SIZE] = {0};    
    bool rc = true; 

    for (int i = 0; i < strlen(s); i++) {

        tracker[CH_TO_INT(s[i])]++;

        if (tracker[CH_TO_INT('A')] >= MAX_ABSENT) {
            rc = false;
            break;
        } else if (tracker[CH_TO_INT('L')] >= MAX_LATE) {
            rc = false;
            break;
        } else if (s[i] != 'L' && tracker[CH_TO_INT('L')]) {
            tracker[CH_TO_INT('L')] = 0;
        }
    }
    return rc;
}
