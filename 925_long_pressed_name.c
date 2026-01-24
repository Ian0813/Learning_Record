/*
 * =====================================================================================
 *
 *       Filename:  925_long_pressed_name.c
 *
 *    Description:  long pressed name
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

typedef enum {false, true} bool;

#define IS_EQUAL(a, b) ((a) == (b))

static bool check_letter(char *name, char *typed, int *times) {

    bool rc = false;

    if (*name == *typed) {

        rc = true;
        *times += 1;

        while (*name == typed[*times]) {
            *times += 1;
        }
    }

    return rc;
}

bool isLongPressedName(char* name, char* typed) {

    int times = 0, name_len = 0, tlen = 0, index = 0, tindex = 0;
    bool rc = false;

    name_len = strlen(name);
    tlen = strlen(typed);

    if (name_len > tlen)
        return rc;

    while (index < name_len) {

        if (index && IS_EQUAL(name[index], name[index-1])) {

            if (!times)
                break;

            times--;
            index++;
            continue;
        }

        times = 0;

        if (!check_letter(&name[index], &typed[tindex], &times)) {
            break;
        }

        tindex += times;
        times--;
        index++;
    }

    if (index == name_len) {
        rc = true;

        for (int i = tindex; i < tlen; i++) {
            if (typed[i] != name[index-1]) {
                rc = false;
                break;
            }
        }
    }
    return rc;
}

int main(void) {

    char name[] = "saeed", typed[] = "ssaaedd";

    printf("isLongPressedName : %d\n", isLongPressedName(name, typed));

    return EXIT_SUCCESS;
}
