/*
 * =====================================================================================
 *
 *       Filename:  1404_number_of_steps_to_reduce_a_number_in_binary_representation_to_one.c
 *
 *    Description:  number of steps to reduce a number in binary representation to one
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

typedef enum {false, true} bool;

#define IS_ONE(ch) ((ch) == '1')

typedef enum {
    NUM_UNKNOWN = -1,
    NUM_ODD = 0,
    NUM_EVEN = 1,
} number_attr;

typedef enum {
    OP_ADDONE = 0,
    OP_DIVTWO = 1
} operation_t;

static number_attr get_num_attr(char *s) {

    int len = strlen(s);

    if (!s)
        return NUM_UNKNOWN;

    return IS_ONE(s[len-1]) ? NUM_ODD : NUM_EVEN;
}    

static bool is_one(char *s) {

    int len = 0;
    bool rc = true;

    if (s) {
        len = strlen(s);

        for (int i = 0; i < len; i++) {
            if (IS_ONE(s[i]) && (i != (len-1))) {
                rc = false;
                break;
            }    
        }
    }
    return rc;
}

static void do_operation(char **s, operation_t op) {

    int len = 0, carry_in = false;
    char *ptr = NULL;

    if (s) {

        len = strlen(*s);

        switch(op) {
            case OP_ADDONE:
                for (int i = len-1; i >= 0; i--) {
                    if (IS_ONE((*s)[i])) {
                        carry_in = true;
                        (*s)[i] = '0';
                    } else {
                        carry_in = false;
                        (*s)[i] = '1';
                        break;
                    }
                }

                if (carry_in) {
                    ptr = (char *) calloc(len + 2, sizeof(char));
                    memset(ptr, '0', sizeof(char) * (len+1));
                    *ptr = '1';
                    *s = ptr;
                }
            break;
            case OP_DIVTWO:
                ptr = strdup(*s);
                **s = '0';
                memmove(&(*s)[1], ptr, (len-1) * sizeof(char));
            break; 
        }

        if (!carry_in)
            free(ptr);
    }
    return;
}

int numSteps(char* s) {

    number_attr attr = NUM_UNKNOWN;
    int step_count = 0; 

    while (!is_one(s)) {
       attr = get_num_attr(s); 

       if (attr == NUM_ODD) {
           do_operation(&s, OP_ADDONE); 
       } else if (attr == NUM_EVEN) {
           do_operation(&s, OP_DIVTWO);
       }

       step_count++;
    }

    return step_count;
}
