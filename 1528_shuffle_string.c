/*
 * =====================================================================================
 *
 *       Filename:  1528_shuffle_string.c
 *
 *    Description:  shuffle string
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

static void swap_int(int *v1, int *v2) {

    int temp = *v1;    
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void swap(char *c1, char *c2) {

    char ch = '\0';

    ch = *c1; 
    *c1 = *c2;
    *c2 = ch;

    return;
}

static void quick_sort(int *indices, int head, int end, char *s) {

    int last = head, tail = end;

    if (head < tail) {

        while (last < tail) {

            if (indices[head] > indices[tail]) {
                last++;
                swap_int(&indices[last], &indices[tail]); 
                swap(&s[last], &s[tail]); 
                continue;
            }
            tail--;
        }

        swap_int(&indices[head], &indices[last]);
        swap(&s[head], &s[last]);
        quick_sort(indices, head, last-1, s);
        quick_sort(indices, last+1, end, s);
    }

    return;
}

char* restoreString(char* s, int* indices, int indicesSize) {

    quick_sort(indices, 0, indicesSize-1, s);

    return s;
}
