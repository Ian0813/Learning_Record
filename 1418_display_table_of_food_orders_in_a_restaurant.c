/*
 * =====================================================================================
 *
 *       Filename:  1418_display_table_of_food_orders_in_a_restaurant.c
 *
 *    Description:  display table of food orders in a restaurant
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define REMOVE_DUPLICATE(strs, head, end, length) for (int i = head; i < end-1 && (i+1) != length; i++) {\
    if (!strcmp(strs[i], strs[i+1])) {\
        memmove(&strs[i], &strs[i+1], sizeof(char *)*(end-(i+1)));\
        length--, i--;\
    }\
}

#define DIGIT_MAX 3
#define TABLE_SIZE 501
#define NAME_LENGTH 21

#define COMPARE_LEN(s1, s2) (strlen(s1) > strlen(s2))
#define COMPARE_VALUE(s1, s2) ((strlen(s1) == strlen(s2)) && strcmp(s1, s2) > 0)
#define CH_TO_INT(ch, base) ((ch)-base)
#define INT_TO_CH(value) ((value)+'0')

enum {
    NAME_INDEX = 0,
    TABLE_INDEX = 1,
    FOOD_INDEX = 2
};

struct item {
    char food[NAME_MAX+1];
    char table[DIGIT_MAX+1];
    int food_index;
};

struct table_container {
    struct item **items;
    int table_record[TABLE_SIZE];
    int table_indices[TABLE_SIZE];
    int table_count;
    int food_count;
};

static int str_to_int(char *str) {

    int value = 0;

    for (int i = 0; i < strlen(str); i++) {
        value *= 10;
        value += CH_TO_INT(str[i], '0');
    }
    return value;
}

static void int_to_str(int value, char *buffer) {

    int index = 0;
    char temp = '\0';

    memset(buffer, 0, DIGIT_MAX+1);

    while (value) {
        buffer[index++] = INT_TO_CH((value%10));
        value /= 10;
    }

    for (int i = 0, j = index-1; i < j; j--, i++) {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }
    return;
}

static void swap(struct item **item1, struct item **item2) {

    struct item *temp = NULL;

    temp = *item1;
    *item1 = *item2;
    *item2 = temp;

    return;
}

static void quick_sort(struct table_container *container, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {

        while (last < tail) {
            if (strcmp(container->items[head]->food, container->items[tail]->food) > 0) {
                last++;
                swap(&container->items[last], &container->items[tail]);
                continue;
            }
            tail--;
        }
        swap(&container->items[last], &container->items[head]);
        quick_sort(container, head, last);
        quick_sort(container, tail+1, end);
    }
    return;
}

static int sync_container(struct table_container *container, char ***orders, int ordersSize) {

    int length = 0, final_length = 0;

    for (int i = 0; i < ordersSize; i++) {
        strcpy(container->items[length]->food, orders[i][FOOD_INDEX]);
        strcpy(container->items[length]->table, orders[i][TABLE_INDEX]);

        if (!container->table_record[str_to_int(orders[i][TABLE_INDEX])]) {
            container->table_record[str_to_int(orders[i][TABLE_INDEX])] = 1;
            container->table_count++;
        }
        length++;
    }

    quick_sort(container, 0, ordersSize);

    // printf("%s\n", "After sorted:");

    container->items[0]->food_index = 0;
    container->food_count++;

    // printf("%s ", container->items[0]->food);
    for (int i = 1; i < ordersSize; i++) {
        if (strcmp(container->items[i]->food, container->items[i-1]->food)) {
            container->items[i]->food_index = container->food_count;
            // printf("%s ", container->items[i]->food);
            container->food_count++;
        } else {
            container->items[i]->food_index = container->items[i-1]->food_index;
        }
    }
    putchar('\n');

    final_length = length;

    //REMOVE_DUPLICATE(table_row, 0, length, final_length);

    //for (int i = final_length; i < length; i++) {
    //    free(table_row[i]);
    //}

    //for (int i = 0; i < length; i++) {
    //    printf("%s ", table_row[i]);
    //}
    //putchar('\n');

    return length;
}

static char ***allocate_result(int row, int column) {

    char ***result = NULL;

    result = (char ***) calloc(row+1, sizeof(char **));

    for (int i = 0; i < row+1; i++) {
        result[i] = (char **) calloc(column+1, sizeof(char *));
        for (int j = 0; j < column+1; j++) {
            result[i][j] = (char *) calloc(NAME_LENGTH, sizeof(char));
        }
    }
    return result;
}

static void fill_display_bar(char ***result, struct table_container *container, int ordersSize) {

    strcpy(result[0][0], "Table");

    for (int i = 0; i < ordersSize; i++) {
        strcpy(result[0][container->items[i]->food_index+1], container->items[i]->food);
        // printf("index: %d, %s\n", container->items[i]->food_index+1, container->items[i]->food);
    }

    // for (int i = 0; i < container->food_count+1; i++) {
    //     printf("food: %s\n", result[0][i]);
    // }
    return;
}

static void fill_tables_info(char ***result, struct table_container *container, int ordersSize) {

    int index = 1, number = 0;
    char buffer[DIGIT_MAX+1] = {0};
    char *ptr = NULL;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (container->table_record[i]) {
            container->table_indices[i] = index;
            int_to_str(i, buffer);
            // printf("table number: %d\n", i);
            strcpy(result[index][0], buffer);

            for (int j = 0; j < container->food_count; j++) {
                strcpy(result[index][j+1], "0");
            }
            index++;
        }
    }

    for (int j = 0; j < ordersSize; j++) {

        ptr = result[container->table_indices[str_to_int(container->items[j]->table)]][container->items[j]->food_index+1];
        number = str_to_int(ptr);
        // printf("%s, number: %d, index: %d\n", container->items[j]->table, number, container->items[j]->food_index+1);
        int_to_str(number+1, buffer);
        strcpy(ptr, buffer);
    }
    return;
}

static int *allocate_column(int row, int column) {

    int *columnsSize = NULL;

    columnsSize = (int *) calloc(row, sizeof(int));

    for (int i = 0; i < row; i++) {
        columnsSize[i] = column;
    }

    return columnsSize;
}


char *** displayTable(char *** orders, int ordersSize, int* ordersColSize, int* returnSize, int** returnColumnSizes){

    struct table_container container = {NULL};
    char ***result = NULL;
    char **display_bar = NULL;

    if (ordersSize) {

        container.items = (struct item **) calloc(ordersSize+1, sizeof(struct item *));

        for (int i = 0; i < ordersSize; i++) {
            container.items[i] = (struct item *) calloc(1, sizeof(struct item));
        }

        sync_container(&container, orders, ordersSize);
        result = allocate_result(container.table_count, ordersSize);

        fill_display_bar(result, &container, ordersSize);
        fill_tables_info(result, &container, ordersSize);

        // for (int i = 0; i < container.table_count+1; i++) {
        //     for (int j = 0; j < ordersSize+1; j++) {
        //         printf("%s ", result[i][j]);
        //     }
        //     putchar('\n');
        // }
        *returnSize = container.table_count+1;
        *returnColumnSizes = allocate_column(container.table_count+1, container.food_count+1);
    }
    return result;
}
