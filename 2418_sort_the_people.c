/*
 * =====================================================================================
 *
 *       Filename:  2418_sort_the_people.c
 *
 *    Description:  Sort the people
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
void bubble_sort(int *arr, int size, char **names) {

    char *temp_str = NULL;
    int temp_int = 0;
	int flag = 0;

    for (int i = 0; i < size; size--) {
        for (int j = i; j < (size-1); j++) {
            if (arr[j] < arr[j+1]) {
                temp_str = names[j];
                names[j] = names[j+1];
                names[j+1] = temp_str;
                temp_int = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp_int;
				flag = 1;
            }
        }
		if (!flag)
            break;
        flag = 0;
    }
    return;
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {

    char **result = (char **) calloc(namesSize, sizeof(char *));

    bubble_sort(heights, heightsSize, names);

    memcpy(result, names, sizeof(char *) * namesSize);

    *returnSize = namesSize;

    return result;
}

int main(void) {
    return 0;
}
