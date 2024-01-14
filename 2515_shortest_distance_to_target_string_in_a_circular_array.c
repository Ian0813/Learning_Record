/*
 * =====================================================================================
 *
 *       Filename:  2515_shortest_distance_to_target_string_in_a_circular_array.c
 *
 *    Description:  Shortest distance to target string in a circular array  
 *
 *       Compiler:  gcc (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>

int closetTarget(char** words, int wordsSize, char* target, int startIndex) {

    int mini = INT_MAX, flag = 0, distance = 0;

    if (!strcmp(words[startIndex], target)) {
        return 0;    
    }

    for (int i = startIndex + 1; i != startIndex; i = ++i % wordsSize) {
        if (!strcmp(words[i], target)) {

            flag = 1;

            if (startIndex > i) {
                distance = (i + (wordsSize - startIndex)) < (startIndex - i) ? (i + (wordsSize - startIndex)) : (startIndex - i);
            } else if (startIndex < i) {
                distance = (startIndex + (wordsSize - i)) < (i - startIndex) ? (startIndex + (wordsSize - i)) : (i - startIndex);
            }
            if (distance < mini)
                mini = distance;
        }
    }

    if (!flag)
        mini = -1;
    return mini;
}

int main(void) {
    return 0;
}

