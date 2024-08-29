/*
 * =====================================================================================
 *
 *       Filename:  506_relative_ranks.c
 *
 *    Description:  Relative ranks 
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

#define INDEX_TABLE_SIZE 1000001
#define STRLENGTH 20

typedef struct {
    int *order_list;
    int *index_table;
    char **result;
} RelativeRanksTool;

const char *prize_strs[] = {"Gold Medal", "Silver Medal", "Bronze Medal"};   

static RelativeRanksTool *RrtoolInit(RelativeRanksTool *tool, int *score, int list_len) {

    int longer_size = STRLENGTH; 

    if (!tool) {
        tool = (RelativeRanksTool *) malloc(sizeof(RelativeRanksTool));    
        tool->order_list = (int *) calloc(list_len, sizeof(int));
        tool->index_table = (int *) calloc(INDEX_TABLE_SIZE, sizeof(int));
        tool->result = (char **) calloc(list_len, sizeof(char *));

        memcpy(tool->order_list, score, sizeof(int)*list_len);

        for (int i = 0; i < list_len; i++) {
            tool->index_table[score[i]] = i;
        }

        for (int i = 0; i < list_len; i++) {
            tool->result[i] = (char *) calloc(longer_size, sizeof(char));
        }
    }
    return tool;
}

static void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end - 1;

    if (front < tail) {

        while (last < tail) {
            if (arr[head] < arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

void numtostr(char *str, int num) {

    int index = 0;
    char temp = '\0';

    if (!num) {
        strcpy(str, "0");
    } else {
        while (num) {
            str[index++] = num%10 + '0';
            num /= 10;
        }
    }

    for (int i = 0, j = index-1; i <= j; i++, j--) {
        temp = str[i]; 
        str[i] = str[j];
        str[j] = temp;
    }
	str[index] = '\0';
    return;
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {

    RelativeRanksTool *tool = NULL; 
    int target_index = 0;

    tool = RrtoolInit(tool, score, scoreSize);

    if (scoreSize) {
        quick_sort(tool->order_list, 0, scoreSize);

        for (int i = 0; i < scoreSize; i++) {

            target_index = tool->index_table[tool->order_list[i]];     

            if ((i+1) <= 3) {
                strcpy(tool->result[target_index], prize_strs[i]);
            } else {
                numtostr(tool->result[target_index], i+1);
            }
        }
        *returnSize = scoreSize;
        free(tool->order_list);
        free(tool->index_table);
    }
    return tool->result;
}

int main(void) {

    int scores[] = {5, 4, 3, 2, 1};
    int len = sizeof(scores)/sizeof(*scores);
    int rlen = 0; 
    char **ptr = NULL;

    ptr = findRelativeRanks(scores, len, &rlen);

    for (int i = 0; i < rlen; i++) {
        printf("[%d] %s\n", i, ptr[i]);
        free(ptr[i]);
    }
    free(ptr);
    return EXIT_SUCCESS;
}
