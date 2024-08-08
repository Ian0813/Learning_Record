/*
 * =====================================================================================
 *
 *       Filename:  2024_08_08_1768_merge_strings_alternately.c
 *
 *    Description:  Merge merge strings alternately 
 *    Link       :  https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75
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

char * mergeAlternately(char * word1, char * word2){

    char *result = (char *) calloc(strlen(word1)+strlen(word2)+1, sizeof(char)); 
    int i = 0, j = 0, index = 0;

    for (i = 0, j = 0; word1[i] && word2[i]; i++, j++) {
        result[index++] = word1[i];
        result[index++] = word2[j];
    }

    while (i < strlen(word1)) {
        result[index++] = word1[i++];
    }

    while (j < strlen(word2)) {
        result[index++] = word2[j++];
    }
    return result;
}

