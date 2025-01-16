/*
 * =====================================================================================
 *
 *       Filename:  3340_check_balanced_string.c
 *
 *    Description:  check balanced string
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
#include <ctype.h>

typedef enum {false, true} bool;

#define CH_TO_INT(ch) ((ch)-'0')

bool isBalanced(char* num) {

    int odd = 0, even = 0;

    for (int i = 0; i < strlen(num); i++) {
        if (isdigit(num[i])) {
            if (!(i%2)) {
                even += CH_TO_INT(num[i]);
            } else {
                odd += CH_TO_INT(num[i]);
            }
        }
    }
    return even == odd ? true : false;
}

