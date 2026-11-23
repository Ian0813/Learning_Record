/*
 * =====================================================================================
 *
 *       Filename:  1496_path_crossing.c
 *
 *    Description:  1496 path crossing
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct coordinate_node {
    int x_point;
    int y_point;
    struct coordinate_node *next; 
} coordinate_node;

static bool **map_allocate(int row, int col) {

    bool **map = NULL;

    if (!row || !col)
        return map;

    if ((map = calloc(row, sizeof(bool *)))) {
        for (int i = 0; i < row; i++) {
            map[i] = calloc(col, sizeof(bool));     
        }
    }
    return map;
}

static bool node_get_coordinate(int *row_index, int *col_index, char direction) {

    bool rc = true;
    coordinate_node *new = NULL;

    switch (direction) {
        case 'N':
            *row_index += 1;
        break;   
        case 'S':
            *row_index -= 1;
        break;   
        case 'E':
            *col_index += 1; 
        break;   
        case 'W':
            *col_index -= 1; 
        break;  
        default:
            fprintf(stdout, "[%s] Unknown direction %hhd\n", __func__, direction);
            rc = false;
        break;
    }
    return rc;
}

static void map_free(bool **map, int row, int col) {

    if (!map)
        return;

    for (int i = 0; i < row; i++)
        free(map[i]);

    free(map);
    return;
}

static bool node_append(coordinate_node **head, coordinate_node **tail, int row_index, int col_index) {

    coordinate_node *new = NULL, *temp = NULL;
    bool rc = false;

    temp = *head;

    while (temp) {
        if (temp->x_point == row_index && temp->y_point == col_index) {
            return rc;
        }
        temp = temp->next;
    }

    new = calloc(1, sizeof(*new));

    if (!new)
        return rc;

    new->x_point = row_index; 
    new->y_point = col_index; 
    rc = true;

    if (*head) {
        (*tail)->next = new;
        (*tail) = new;
    } else {
        *head = *tail = new;
    }
    return rc;
}

static void node_free(coordinate_node *head) {

    if (head)
        node_free(head->next);

    free(head);
    return;
}

bool isPathCrossing(char* path) {

    bool **map = NULL;
    size_t plen = 0;
    int row_index = 0, col_index = 0, offset = 0;
    bool rc = false;
    coordinate_node *head = NULL, *tail = NULL;

    if (path) {
        plen = strlen(path);

        node_append(&head, &tail, 0, 0);

        for (int i = 0; i < plen && !rc; i++) {

            node_get_coordinate(&row_index, &col_index, path[i]);

            if (!node_append(&head, &tail, row_index, col_index)) {
                rc = true;
                break;
            }
        }
        node_free(head);
    }
    return rc;
}
