/*
 * =====================================================================================
 *
 *       Filename:  763_partition_labels.c
 *
 *    Description:  Partition labels   
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_SIZE 501

int find_last(char ch, char *s) {

    int index = 0; 

    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == ch) {
            index = i;
            break;
        }    
    }
    return index;
}

int* partitionLabels(char* s, int* returnSize) {

    int *result = (int *) malloc(sizeof(int) * MAX_SIZE);
    int index = 0;
    int delimit = 0, temp = 0;
    char cur = '\0'; 

    for (int i = 0; i < strlen(s);) {

        delimit = find_last(s[i], s);

        cur = s[i];

        for (int j = delimit-1; j > i; j--) {
            if (s[j] != cur && (temp = find_last(s[j], s)) > delimit) {
                cur = s[j];
                delimit = temp;
                j = temp;
            }
        }

        result[index++] = delimit+1;
        i = delimit + 1;
    }

    for (int i = index - 1; i > 0; i--) {
        result[i] = result[i] - result[i-1];
	}

    *returnSize = index;

    return result;
}

int main(void) {

    char str[BUFSIZ] = "eaedcaaadedaacb"; 
    int *arr = NULL, index = 0;

    arr = partitionLabels(str, &index);

    for (int i = index-1; i > 0; i--) {
        arr[i] = arr[i] - arr[i-1]; 
    }

    for (int i = 0; i < index; i++) {
        printf("[%d] %d\n", i, arr[i]); 
    }

    free(arr);

    return EXIT_SUCCESS;
}

