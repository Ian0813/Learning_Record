/*
 * =====================================================================================
 *
 *       Filename:  1358_number_of_substrings_containing_all_three_characters.c
 *
 *    Description:  number of substrings containing all three characters
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

#define BASE_LEN 3
#define CH_TO_VAL(ch) ((ch)-'a')
#define IS_CONTAIN_ABC(table) (table[0]&&table[1]&&table[2])

static bool find_valid_str(char *s, int start, int *index, int *table) {

    bool rc = false;

    if (start < strlen(s)) {
        for (int i = start; i < strlen(s); i++) {

            table[CH_TO_VAL(s[i])]++;

            if (IS_CONTAIN_ABC(table)) {
                rc = true;
                *index = i;
                break;
            }
        }
    } else if (IS_CONTAIN_ABC(table)) {
        rc = true;
    }
    return rc;
}

int numberOfSubstrings(char* s) {

    int count = 0;
    long long total = 0LL;
    int index = 0, start = 0;
    int table[BASE_LEN] = {0};

    if (strlen(s) >= BASE_LEN) {
        for (int i = 0; i < strlen(s)-(BASE_LEN-1); i++) {
            if ((i+(BASE_LEN-1)) <= index && IS_CONTAIN_ABC(table)) {
                count = 1+(strlen(s)-(index+1));
                total += count;
            } else if (find_valid_str(s, start, &index, table)) {
                count = 1+(strlen(s)-(index+1));
                total += count;
                start = index+1;
            } else {
                break;
            }
            table[CH_TO_VAL(s[i])]--;
        }
    }
    return total;
}
