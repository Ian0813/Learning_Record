/*
 * =====================================================================================
 *
 *       Filename:  3330_find_the_original_typed_string_i.c
 *
 *    Description:  find the original typed string i
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

static void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end;

    if (front < tail) {

        while (last < tail) {
            if (arr[head] < arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[last], &arr[head]);
        quick_sort(arr, head, last-1);
        quick_sort(arr, last+1, end);
    }

    return;
}

static void get_consecutives(int *consecutives, int *len, char *word) {

    int count = 1;

    for (int i = 0; i < strlen(word); *len += 1, i++) {
        for (int j = i+1; word[i] == word[j]; j++) {
            count++;
            i = j;
        }
        consecutives[*len] = count;
        count = 1;
    }
    return;
}

int possibleStringCount(char* word) {

    int *consecutives = NULL, len = 0;
    int possibleCount = 0;

    if (strlen(word)) {

       consecutives = (int *) calloc(strlen(word), sizeof(int));
       get_consecutives(consecutives, &len, word);
       quick_sort(consecutives, 0, len-1);

       for (int i = 0; i < len; i++) {
           possibleCount = !i ? possibleCount + consecutives[i] : possibleCount + (consecutives[i]-1);
       }
    }
    return possibleCount;
}
