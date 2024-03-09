/*
 * =====================================================================================
 *
 *       Filename:  739_daily_temperatures.c
 *
 *    Description:  Daily temperatures  
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
#include <limits.h>

#define TEMP_TABLE 101
#define MAX_SIZE 18000

struct node {
    int index;
    int sub_table[MAX_SIZE]; 
};

#if 0
void free_list(struct node *node) {

    struct node *temp = node;

    while (temp != NULL) {
        free(temp); 
        temp = node;
    }
    return;
}
#endif

struct node *create_node(struct node *node, int index) {

    if (node == NULL) {
        node = (struct node *) malloc(sizeof(struct node));
        node->index = 0;
		node->sub_table[node->index++] = index;
    }
    return node;
}

void binary_search(struct node *node, int cur, int *after, int head, int end) {

	int diff = 0;
	int middle = (head+end)/2;

    if (head < end) {
        if (node->sub_table[middle] > cur) {
            if (*after > (diff = node->sub_table[middle] - cur))
                *after = diff;
			binary_search(node, cur, after, head, middle);
		} else {
			binary_search(node, cur, after, middle+1, end);
		}
	}
    return; 
}

void check_warmer_day(struct node *node, int cur, int *after) {

    int diff = 0, flag = 0;

    binary_search(node, cur, after, 0, node->index);

    return;
}

int get_after(struct node *table[], int temperature, int cur) {

    int after = INT_MAX;

    for (int i = temperature + 1; i < TEMP_TABLE; i++) {
        if (table[i] != NULL && table[i]->sub_table[table[i]->index-1] > cur) {
            check_warmer_day(table[i], cur, &after); 
        }
        if (after == 1)
            break;
    }
    return after == INT_MAX ? 0 : after;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {

    struct node *table[TEMP_TABLE] = {NULL};
    int index = 0;
    int *result = (int *) calloc(temperaturesSize, sizeof(int));

    for (int i = 0; i < temperaturesSize; i++) {
        if (table[temperatures[i]] == NULL)
            table[temperatures[i]] = create_node(table[temperatures[i]], i);
		else
            table[temperatures[i]]->sub_table[table[temperatures[i]]->index++] = i; 
    }

    for (int i = 0; i < temperaturesSize; i++) {
        result[index++] = get_after(table, temperatures[i], i);
    }

    for (int i = 0; i < TEMP_TABLE; i++) {
        if (table[i] != NULL)
            free(table[i]);
    }

    *returnSize = index;
    return result;  
}


int main(void) {

    int temperatures[] = {73,74,75,71,69,72,76,73};
    int *result = NULL; 
    int index = 0;

    result = dailyTemperatures(temperatures, sizeof(temperatures)/sizeof(int), &index);

    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    putchar('\n');

    free(result);    

    return EXIT_SUCCESS;
}
