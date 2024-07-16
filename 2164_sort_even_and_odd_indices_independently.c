/*
 * =====================================================================================
 *
 *       Filename:  2164_sort_even_and_odd_indices_independently.c
 *
 *    Description:  Sort even and odd indices independently  
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

typedef enum {false, true} bool;

typedef enum {
    INCREASING = 0,
    DECREASING = 1,
} compare_opts;

bool comparison_func(int a, int b, compare_opts opt) {

    bool rc = true;

    if (opt == INCREASING) {
        if (a <= b) {
            rc = false; 
        }
    } else if (opt == DECREASING) {
        if (a > b) {
            rc = false;  
        }
    }
    return rc;
}

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void quick_sort(int *arrs, int head, int end, bool (*comparison)(int, int, compare_opts), compare_opts opt) {

    int front = head, last = head, tail = end - 1;

    if (head < tail) {

        while (last < tail) {
            if ((*comparison)(arrs[front], arrs[tail], opt)) {
                last++;
                swap(&arrs[last], &arrs[tail]);
                continue;
            }
            tail--;
        }
        swap(&arrs[front], &arrs[last]);
        quick_sort(arrs, head, last, comparison, opt);
        quick_sort(arrs, last+1, end, comparison, opt);
    }
    return;
}

int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {

    int odd_arr[(numsSize/2)+1];
    int even_arr[(numsSize/2)+1];
    int odd_index = 0, even_index = 0;
    int *result = (int *) calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (i%2) {
            odd_arr[odd_index++] = nums[i];
        } else {
            even_arr[even_index++] = nums[i]; 
        }
    }

    quick_sort(odd_arr, 0, odd_index, comparison_func, DECREASING);
    quick_sort(even_arr, 0, even_index, comparison_func, INCREASING);

    for (int i = 0, j = 0, k = 0; j < odd_index || k < even_index; i++) {
        if (i%2) {
            result[i] = odd_arr[j++];
        } else {
            result[i] = even_arr[k++];
        }
    }

    *returnSize = numsSize;
    return result;
}

#define TEST_AMOUNT 10

int main(void) {

    int arrs[TEST_AMOUNT] = {0};
    int *result = NULL, index = 0; 
    srand(time(NULL));

    printf("Original sequence: \n");
    for (int i = 0; i < TEST_AMOUNT; i++) {
        arrs[i] = rand()%101; 
        printf("%3d ", arrs[i]);
    }
    putchar(10);

    result = sortEvenOdd(arrs, TEST_AMOUNT, &index);
    printf("Result: \n");
    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    putchar('\n');
    free(result);
#if 0
    quick_sort(arrs, 0, TEST_AMOUNT, comparison_func, INCREASING);

    printf("Increasing sequence: \n");
    for (int i = 0; i < TEST_AMOUNT; i++) {
        printf("%3d ", arrs[i]);
    }
    putchar(10);

    quick_sort(arrs, 0, TEST_AMOUNT, comparison_func, DECREASING);

    printf("Decreasing sequence: \n");
    for (int i = 0; i < TEST_AMOUNT; i++) {
        printf("%3d ", arrs[i]);
    }
    putchar(10);
#endif
    return EXIT_SUCCESS;
}
