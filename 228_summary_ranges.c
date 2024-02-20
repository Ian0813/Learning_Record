/*
 * =====================================================================================
 *
 *       Filename:  228_summary_ranges.c
 *
 *    Description:  Summary tanges  
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

#define MIDDLE_STR "->"

#define STRINGIZE(buf, num, index) { \
    while (num > 0) { \
        buf[index] = (num%10)+48; num /= 10; index++; \
    }\
    for (int i = 0, j = index -1, temp = 0; i < j; i++, j--) { \
        temp = buf[i]; buf[i] = buf[j]; buf[j] = temp;\
    }\
    buf[index] = '\0'; index = 0;\
}

typedef enum {false, true} bool;

struct queue {
    int nums[BUFSIZ];
    int windex;
    int rindex;
};

void enqueue(struct queue *q, int value) {
    if ((q->windex+1)%BUFSIZ != q->rindex) {
        q->nums[q->windex] = value;              
        q->windex = (q->windex+1)%BUFSIZ;
    }
    return;
}

void dequeue(struct queue *q) {
    if (q->windex != q->rindex && (q->windex+1)%BUFSIZ != q->rindex) {
        q->rindex = (q->rindex+1)%BUFSIZ; 
    }
    return;
}

int is_empty(struct queue *q) {
    if (q->windex == q->rindex) {
        return true;
    }
    return false;
}

int get_value(struct queue *q) {
    return q->nums[q->rindex];
}

void stringize(char *buf, int num) { 

    int flag = 0;
    int index = 0;

    if (num < 0) {
        buf[index] = '-';
        index = flag = 1;
        num = -num;
    }

    while (num > 0) { 
        buf[index] = (num%10)+48; num /= 10; index++;
    }

    for (int i = flag, j = index -1, temp = 0; i < j; i++, j--) { 
        temp = buf[i]; 
        buf[i] = buf[j]; 
        buf[j] = temp;
    }

    buf[index] = '\0'; 
    index = 0;
    return;
}

void appending(char **list, int *begin, int *end, int *index) {

    char buf1[MAX_INPUT] = {0}, buf2[MAX_INPUT] = {0};

    int n1 = 0, n2 = 0;

    if (begin)
        n1 = *begin;

    if (end)
        n2 = *end;

    if (begin && n1 != 0) {
        stringize(buf1, n1);
    } else if (begin) {
        strcpy(buf1, "0");
    }

    if (end && n2 != 0) {
        stringize(buf2, n2);
    } else if (end) {
        strcpy(buf2, "0");
    }

    list[*index] = (char *) malloc(MAX_INPUT * sizeof(char));
    memset(list[*index], 0, sizeof(char) * MAX_INPUT);

    if (n1 != n2) {
        strcat(list[*index], buf1);
        strcat(list[*index], MIDDLE_STR);
        strcat(list[*index], buf2);
    } else {
        strcat(list[*index], buf1);
    }

    *index = *index + 1;
    return;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {

    char **list = (char **) calloc(BUFSIZ, sizeof(char *));
    int begin = 0, end = 0, index = 0, value = 0, flag = 0;
    struct queue *q = (struct queue *) malloc(sizeof(struct queue)); 

    if (numsSize) {

        value = nums[0];

        for (int i = 0; i < numsSize; i++) {
            enqueue(q, nums[i]);    
        }

        while (!is_empty(q)) {

            if (!flag) {
                begin = value;
                flag = 1;
            }

            if (get_value(q) == value) {
                dequeue(q);
                if (!is_empty(q)) {
                    value++; 
                }
                end = value;
            } else {
                 flag = 0;
                 end = value - 1;
                 appending(list, &begin, &end, &index);
                 value = get_value(q);
            }
         
        }

        if (begin == end) {
            appending(list, &begin, NULL, &index);
        } else {
            appending(list, &begin, &end, &index);
        }
    }

    free(q);
    *returnSize = index;

    return list;
}
