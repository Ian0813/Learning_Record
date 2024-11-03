/*
 * =====================================================================================
 *
 *       Filename:  1433_check_if_a_string_can_break_another_string.c
 *
 *    Description:  check if a string can break another string
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
#include <sys/time.h>
#include <stdint.h>

typedef enum {false, true} bool;

static void swap(char *ch1, char *ch2) {
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
    return;
}

void quick_sort(char *str, int head, int end) {

    int front = head, last = head, tail = end - 1;

    if (front < tail) {

        while (last < tail) {
            if (str[front] > str[tail]) {
                last++;
                swap(&str[last], &str[tail]);
                continue;
            }
            tail--;
        }
        swap(&str[front], &str[last]);
        quick_sort(str, head, last);
        quick_sort(str, last+1, end);
    }
    return;
}

bool check_break(char *s1, char *s2) {

    bool rc = true;

    for (int i = 0; i < strlen(s1); i++) {
        if (!(s1[i] >= s2[i])) {
            rc = false; 
            break;
        }
    }
    return rc;
}


static void merge_process(char *str, int head, int middle, int end) {

    int half1_size = (middle-head+1), half2_size = (end-middle);
    int half1[half1_size], half2[half2_size];
    int h1_index = 0, h2_index = 0, str_index = head;

    for (h1_index; h1_index < half1_size; h1_index++) {
        half1[h1_index] = str[head+h1_index];
    }

    for (h2_index; h2_index < half2_size; h2_index++) {
        half2[h2_index] = str[middle+h2_index+1];
    }

    h1_index = h2_index = 0;

    while (h1_index < half1_size && h2_index < half2_size) {
        if (half1[h1_index] > half2[h2_index]) {
            str[str_index++] = half2[h2_index++];
        } else {
            str[str_index++] = half1[h1_index++];
        }
    }

    while (h1_index < half1_size) {
        str[str_index++] = half1[h1_index++];
    }

    while (h2_index < half2_size) {
        str[str_index++] = half2[h2_index++];
    }
    return;
}

static void merge_sort(char *str, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(str, head, middle);
        merge_sort(str, middle+1, end);
        merge_process(str, head, middle, end);
    }
    return;
}    

bool checkIfCanBreak(char* s1, char* s2) {

    bool rc = true; 

    merge_sort(s1, 0, strlen(s1)-1);
    merge_sort(s2, 0, strlen(s2)-1);

    if (!(rc = check_break(s1, s2))) {
        rc = check_break(s2, s1);
    }
    return rc;
}

#define TEST_AMOUNT 30

int main(void) {

    char str1[] = "abe", str2[] = "acd";
    struct timeval tinfo = {0};
    int8_t arr[TEST_AMOUNT] = {0};

    gettimeofday(&tinfo, NULL);

    srand(tinfo.tv_sec+tinfo.tv_usec);

    for (int i = 0; i < TEST_AMOUNT; i++) {
        arr[i] = rand() % 255;
        printf("%d ", arr[i]);
    }
    putchar('\n');

    merge_sort(arr, 0, TEST_AMOUNT-1);

    for (int i = 0; i < TEST_AMOUNT; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');

    printf("break: %d\n", checkIfCanBreak(str1, str2));

    return EXIT_SUCCESS;
}
