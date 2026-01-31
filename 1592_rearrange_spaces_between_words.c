/*
 * =====================================================================================
 *
 *       Filename:  1592_rearrange_spaces_between_words.c
 *
 *    Description:  rearrange spaces between words
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
#include <ctype.h>

static int count_string(char *text) {

    char *ptr = NULL;
    int count = 0;

    if (text) {
        ptr = strtok(text, " ");

        while (ptr) {
            count++;
            ptr = strtok(NULL, " ");
        }
    }

    return count;
}

static int count_character(char *text, char ch) {

    int len = 0, count = 0;

    if (text) {
        len = strlen(text);
        for (int i = 0; i < len; i++) {
            count = text[i] == ch ? (count + 1) : count; 
        }
    }

    return count;

}

static char *reorder_process(char *text, int average, int remain, int str_count) {

    int len = 0, rlen = 0, count = 0;
    char *result = NULL, *ptr = NULL;

    if (text) {

        len = strlen(text);
        result = (char *) calloc(len+1, sizeof(char));

        ptr = strtok(text, " ");  

        while (ptr) {
            count++;
            len = strlen(ptr);
            memcpy(&result[rlen], ptr, len);
            rlen += len; 

            if (count < str_count) {
                memset(&result[rlen], ' ', average);
                rlen += average;
            }
            ptr = strtok(text, " ");
        }

        while (remain) {
            result[rlen++] = ' '; 
            remain--;
        }
    }

    return result;
}

char* reorderSpaces(char* text) {

    int average = 0, str_count = 0, space_count = 0, remain = 0;
    char *result = NULL, *dup = NULL;

    str_count = count_string((dup = strdup(text)));
    free(dup);

    space_count = count_character(text, ' ');

    if (str_count > 1) {
        average = space_count / (str_count - 1);
        remain = space_count % (str_count - 1);
    } else {
        remain = space_count;  
	}

    if (average)
        result = reorder_process(text, average, remain, str_count);
    else
        result = text; 

    return result; 
}
