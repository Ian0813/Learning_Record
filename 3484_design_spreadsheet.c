/*
 * =====================================================================================
 *
 *       Filename:  3484_design_spreadsheet.c
 *
 *    Description:  design spreadsheet
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
#include <ctype.h>

typedef enum {false, true} bool;

#define DECIMAL 10
#define SET_VALUE(val) ((val) == -1 ? 0 : (val))

typedef struct {
    char *title;
    int value;
} Node;

typedef struct {
    Node *nodes;
    int size;
    int capacity;
} Spreadsheet;

static bool is_digits(char *str) {

    int len = 0;

    if (!str || *str == '\0')
        return false;

    len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

Spreadsheet* spreadsheetCreate(int rows) {

    Spreadsheet *obj = NULL;

    if (rows) {
        obj = (Spreadsheet *) malloc(sizeof(*obj));
        obj->nodes = (Node *) calloc(BUFSIZ, sizeof(Node));
        obj->size = 0;
        obj->capacity = BUFSIZ;
    }

    return obj;
}

void spreadsheetSetCell(Spreadsheet* obj, char* cell, int value) {

    int index = -1;

    if (obj) {

         for (int i = 0; i < obj->size; i++) {
             if (!strcmp(obj->nodes[i].title, cell)) {
                 index = i;
                 break;
             }     
         }

         if (index == -1 && obj->size < obj->capacity) {
             index = obj->size; 
             obj->size++;
         }

         if (index != -1) {
             (obj->nodes + index)->title = cell; 
             (obj->nodes + index)->value = value; 
         }
    }

    return;
}

void spreadsheetResetCell(Spreadsheet* obj, char* cell) {

    if (obj) {
        for (int i = 0; i < obj->size; i++) {
            if (!strcmp((obj->nodes + i)->title, cell)) {
                (obj->nodes + i)->value = 0;
                break;
            }
        }
    }
    return;
}

int spreadsheetGetValue(Spreadsheet* obj, char* formula) {

    char *x = NULL, *y = NULL, *copy = NULL, *saveptr = NULL; 
    int x_value = -1, y_value = -1;

    if (obj && formula) {

        copy = strdup(formula+1); 

        x = strtok_r(copy, "+", &saveptr);
        y = strtok_r(NULL, "+", &saveptr);

        if (is_digits(x)) {
            x_value = (int) strtol(x, NULL, DECIMAL);
        }

        if (is_digits(y)) {
            y_value = (int) strtol(y, NULL, DECIMAL);
        }

        if (x_value == -1 || y_value == -1) {
            for (int i = 0; i < obj->size; i++) {

                if (!strcmp(x, obj->nodes[i].title)) {
                    x_value = obj->nodes[i].value;
                }

                if (!strcmp(y, obj->nodes[i].title)) {
                    y_value = obj->nodes[i].value;
                }
            }
        }

        x_value = SET_VALUE(x_value);
        y_value = SET_VALUE(y_value);
        free(copy);
    }
    return (x_value + y_value); 
}

void spreadsheetFree(Spreadsheet* obj) {

    if (obj) {
        free(obj->nodes);
        free(obj);
    }

    return;
}

/**
 * Your Spreadsheet struct will be instantiated and called as such:
 * Spreadsheet* obj = spreadsheetCreate(rows);
 * spreadsheetSetCell(obj, cell, value);

 * spreadsheetResetCell(obj, cell);

 * int param_3 = spreadsheetGetValue(obj, formula);

 * spreadsheetFree(obj);
*/

