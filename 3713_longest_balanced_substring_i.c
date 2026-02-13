/*
 * =====================================================================================
 *
 *       Filename:  3713_longest_balanced_substring_i.c
 *
 *    Description:  3713 longest balanced substring i
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

/* 

  Example 1:
 
  Input: s = "abbac"
  Output: 4
    
  Explanation:
  The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times. 
*/

#define TABLE_SIZE 26
#define CH_TO_INDEX(ch) ((ch)-'a')

static bool check_is_balance(bool *ch_set, int *count_table) {

    int index = 0, value = 0;
    bool rc = true;

    for (index; index < TABLE_SIZE; index++)
        if (ch_set[index]) {
            value = count_table[index];
            break;
        }

    for (index; index < TABLE_SIZE; index++) {
        if (count_table[index] && count_table[index] != value) {
            rc = false;
            break;
        }    
    }

    return rc;
}

int longestBalanced(char* s) {

    int count_table[TABLE_SIZE] = {0};
    int maximum = 0, temp_len = 0, slen = 0, cindex = 0;
    bool ch_set[TABLE_SIZE] = {0};

    slen = strlen(s);

    for (int i = 0; i < slen; i++) {

        for (int j = i; j < slen; j++) {

            cindex = CH_TO_INDEX(s[j]);

            if (!ch_set[cindex]) {
                ch_set[cindex] = true;
            }

            count_table[cindex]++;

            if (check_is_balance(ch_set, count_table)) {
                temp_len = (j + 1) - i;
            }

            maximum = maximum < temp_len ? temp_len : maximum; 
        }

        if (maximum == (slen - i))
            break; 

        memset(count_table, 0, sizeof(int) * TABLE_SIZE);
        memset(ch_set, 0, sizeof(bool) * TABLE_SIZE);
    }
    return maximum;
}
