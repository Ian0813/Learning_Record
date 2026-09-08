/*
 * =====================================================================================
 *
 *       Filename:  4043_count_rotations_with_exactly_k_equal_adjacent_pairs.c
 *
 *    Description:  count rotations with exactly k equal adjacent pairs
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
#include <limits.h>

static int get_count_by_rotation(char *buffer, int len, int rotate_times, int cond_k) {

    int count = 0, index = 1, seq_number = 0;

    while (rotate_times) {
        for (int i = index; i < (len + (index-1)); i++) {
            if (buffer[i] == buffer[i-1])
                seq_number++; 

        }

        if (seq_number == cond_k)
            count++;

        buffer[len + (index-1)] = buffer[index-1];
        rotate_times--;
        index += 1;
        seq_number = 0;
    }
    return count;
}

int countRotations(char* s, int k) {

    int slen = 0, count = 0;
    char *buffer = NULL;

    if (s) {
        slen = strlen(s);
        buffer = calloc(slen * 2, sizeof(char));
        if (!buffer)
            return count; 
        memcpy(buffer, s, slen);
        count = get_count_by_rotation(buffer, slen, slen, k);
        free(buffer);
    }
    return count;
}
