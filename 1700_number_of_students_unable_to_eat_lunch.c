/*
 * =====================================================================================
 *
 *       Filename:  1700_number_of_students_unable_to_eat_lunch.c
 *
 *    Description:  number of students unable to eat lunch
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

typedef enum {false, true} bool; 

typedef enum {
    DQ_APPEND = 0,
    DQ_PREPEND = 1,
    DQ_REMOVE = 2,
} dq_option;

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct dqueue {
    node *head;
    node *tail;
    node *cur;
    int length;
} double_queue; 

double_queue *create_dqueue(int *value) {

    double_queue *obj = NULL;    

    obj = (double_queue *) malloc(sizeof(double_queue));
    memset(obj, 0, sizeof(double_queue));

    if (value) {
        obj->cur = obj->head = obj->tail = (node *) malloc(sizeof(node));
        obj->head->value = *value; 
        obj->head->next = NULL;
        obj->length = 1;
    }
    return obj;
}

bool add_dqueue(double_queue *q, int value, dq_option option) {

    node *temp = NULL;

    if (!q)
        return false;

    if (option != DQ_APPEND && option != DQ_PREPEND)
        return false;

    temp = (node *) malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;

    if (!q->cur)
        q->cur = temp;

    switch (option) {
        case DQ_APPEND:
            if (q->tail)
                q->tail->next = temp; 
            q->tail = temp;
            q->head = !q->head ? temp : q->head;
        break;
        case DQ_PREPEND:
            temp->next = q->head;
            q->head = temp;
            q->tail = !q->tail ? temp : q->tail;
        break;
    }

    q->length++;
    return true;
}

bool del_dqueue(double_queue *q, dq_option option) {

    node *temp = NULL;

    if (!q)
        return false;

    if (option != DQ_REMOVE)
        return false;

    switch (option) {
        case DQ_REMOVE:
            temp = q->head;
            q->cur = q->cur == q->head ? q->head->next : q->cur; 
            q->head = q->head->next;
        break;
    }

    q->length--;
    return true;
}

void display_dqueue(double_queue *q) {

    node *temp = NULL;

    if (!q)
        return;

    temp = q->head;

    while (temp) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    putchar('\n');
    return; 
}

void free_dqueue(double_queue *q) {

    node *temp = NULL; 

    if (!q)
        return;

    temp = q->head; 

    while (temp) {
        q->head = q->head->next; 
        free(temp);
        temp = q->head;
    }

    return;
}

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {

    double_queue *person = NULL, *sandwich = NULL;
    int result = 0, count = 0;

    person = create_dqueue(NULL);
    sandwich = create_dqueue(NULL);

    for (int i = 0; i < studentsSize; i++) {
        add_dqueue(person, students[i], DQ_APPEND);
    }

    for (int i = 0; i < sandwichesSize; i++) {
        add_dqueue(sandwich, sandwiches[i], DQ_APPEND);
    }

    while (person->cur && sandwich->cur) {

        if (person->cur->value == sandwich->cur->value) {
            del_dqueue(person, DQ_REMOVE);
            del_dqueue(sandwich, DQ_REMOVE);
            count = 0;
            continue;
        } else {
            add_dqueue(person, person->cur->value, DQ_APPEND);
            del_dqueue(person, DQ_REMOVE);
            count++;
        }

        person->cur = person->head;

        if (count == person->length)
            break;
    }

    result = person->length;
    free_dqueue(person);
    free_dqueue(sandwich);


    return result;
}
