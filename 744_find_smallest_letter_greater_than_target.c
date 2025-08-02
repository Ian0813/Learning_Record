/*
 * =====================================================================================
 *
 *       Filename:  744_find_smallest_letter_greater_than_target.c
 *
 *    Description:  find smallest letter greater than target
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

static int binary_search(char *letters, int head, int end, char target) {

    int middle = (head+end)/2;
    int rc = middle;

    if (head < end) {
        if (letters[middle] == target) {
            return rc; 
        } else if (letters[middle] < target) {
            rc = binary_search(letters, middle+1, end, target);
        } else if (letters[middle] > target) {
            rc = binary_search(letters, head, middle, target);
        }
    }

    return rc;
}

char nextGreatestLetter(char* letters, int lettersSize, char target) {

    char result = letters[0]; 
    int index = 0;

    if (result < target) {

        index = binary_search(letters, 0, lettersSize, target); 

        if (index < lettersSize)
            result = letters[index];
    }

    if (result == target) {
        for (int i = index; i < lettersSize; i++) {
            if (letters[i] > result) {
                result = letters[i];
                break; 
            }
        }

        if (result == letters[index])
            result = letters[0];
    }
    return result; 
}
