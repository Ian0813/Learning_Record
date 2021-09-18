/*
 * =====================================================================================
 *
 *       Filename:  830_positions_of_large_groups.c
 *
 *    Description:  positions of large groups  
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

#define MAX 1000

int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes) {

    int i = 0, j = 0, index = 0;
    int **group = NULL;

    group = (int **) calloc(MAX, sizeof(int *));

    for (index = 0; index < MAX; index++) {
        group[index] = (int *) calloc(2, sizeof(int));
    }
	index = 0;


    for (; i < strlen(s); i++) {
        for (; j < strlen(s); j++) {
            if (s[i] != s[j]) {
                if ((j - i) > 2) {
                    group[index][0] = i;
                    group[index][1] = j-1;
					index++;
					i = j - 1;
                }
				break;
			}
		}
	}

    *returnSize = index;
	**returnColumnSizes = 2;

    return group;
}

void release(int **group) {

    for (int index = 0; index < MAX; index++) {
        free(*(group+index));
	}
	free(group);

	return;
}

int main(void) {

    char *s = "abcdddeeeeaabbbcd";
	int row = 0, column = 0;
	int *ptr = &column;
	int **group = NULL; 

	group = largeGroupPositions(s, &row, &ptr);

	for (int i = 0; i < row; i++) {
        printf("%d, %d\n", group[i][0], group[i][1]);
	}

	release(group);

	return 0;
}
