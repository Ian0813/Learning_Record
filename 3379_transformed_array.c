/*
 * =====================================================================================
 *
 *       Filename:  3379_transformed_array.c
 *
 *    Description:  transformed array
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
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

typedef enum {
    PRINT_FORWARD = 0,
    PRINT_BACKWARD = 1
} print_direction;

typedef struct node {
    int value;
    struct node *prev;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int len;
} Dllist;

static Dllist *dll_insert(Dllist *dll_data, int value) {

    Node *node = NULL;
    Dllist *dll = NULL;

    node = (Node *) calloc(1, sizeof(Node));

    if (!node) {
        perror("calloc ");
        return NULL;
    }

    node->value = value;
    node->next = node->prev = NULL;

    if (!dll_data) {
        dll_data = (Dllist *) calloc(1, sizeof(Dllist));
        dll_data->tail = dll_data->head = node;
        dll_data->tail->next = dll_data->tail->prev = node;
        dll_data->head->next = dll_data->head->prev = node;
    } else {
        dll_data->tail->next = node;
        node->prev = dll_data->tail;
        dll_data->tail = node;
        dll_data->tail->next = dll_data->head;
        dll_data->head->prev = dll_data->tail;
    }

    dll_data->len++;
    return dll_data;
}

static void dll_display(Dllist *dll_data, print_direction direction) {

    Node *temp = NULL;

    if (dll_data) {

        if (direction == PRINT_FORWARD) {
            temp = dll_data->head;

            do {
                printf("%d ", temp->value);
                temp = temp->next;
            } while (temp != dll_data->head);
        } else {

            temp = dll_data->tail;
            do {
                printf("%d ", temp->value);
                temp = temp->prev;
            } while (temp != dll_data->tail);
        }
        putchar('\n');
    }
    return;
}

static int dll_get_value_by_offset(Dllist *dll_data, int index, int offset) {

    Node *node = NULL;

    if (dll_data) {

        node = dll_data->head;

        while (index) {
            node = node->next;
            index--;
        }

        if (offset > 0) {
            while (offset) {
                node = node->next;
                offset--;
            }
        } else if (offset < 0) {
            offset = -offset;
            while (offset) {
                node = node->prev;
                offset--;
            }
        }
    }
    return node ? node->value : 0;
}

static void dll_free(Dllist *dll_data) {

    Node *temp = NULL;

    if (dll_data) {

        temp = dll_data->head;

        while (dll_data->len) {
            dll_data->head = temp->next;
            free(temp);
            temp = dll_data->head;
            dll_data->len--;
        }
    }

    return;
}

int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {

    Dllist *dll_data = NULL;
    int *result = NULL, value = 0;

    result = (int *) calloc(numsSize, sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        dll_data = dll_insert(dll_data, nums[i]);
    }

    for (int i = 0; i < numsSize; i++) {
        value = dll_get_value_by_offset(dll_data, i, nums[i]);
        result[*returnSize] = value;
        *returnSize += 1;
    }

    dll_free(dll_data);

#if 0
    dll_display(dll_data, PRINT_FORWARD);
    dll_display(dll_data, PRINT_BACKWARD);
#endif

    return result;
}
