/*
 * =====================================================================================
 *
 *       Filename:  1598_crawler_log_folder.c
 *
 *    Description:  Crawler log folder  
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

const char *op_strs[] = {"../", "./"};  

typedef enum {
    PARENT_FOLDER = 0,
    CUR_FOLDER, 
    DIRECT_FOLDER,
} op_types;

static op_types getop(char *str) {

    if (!strcmp(str, op_strs[PARENT_FOLDER])) {
        return PARENT_FOLDER;
    } else if (!strcmp(str, op_strs[CUR_FOLDER])) {
        return CUR_FOLDER;
    }
    return DIRECT_FOLDER;
}

int minOperations(char** logs, int logsSize) {

    int distance = 0; 

    if (logsSize) {

        for (int i = 0; i < logsSize; i++) {
            switch (getop(logs[i])) {
                case PARENT_FOLDER: {
                    if (distance)
                        distance--;  
                }
                break;
                case CUR_FOLDER:
                break;
                case DIRECT_FOLDER: {
                    distance++;  
                }
                break;
            }
        }    

    }
    return distance;
}
