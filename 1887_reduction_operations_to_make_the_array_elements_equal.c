/*
 * =====================================================================================
 *
 *       Filename:  1887_reduction_operations_to_make_the_array_elements_equal.c
 *
 *    Description:  Reduction operations to make the array elements equal  
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

static void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void quick_sort(int *arr, int head, int end) {

    
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

static void merge_oper(int *arr, int front, int middle, int tail) {

    int fsize = (middle-front)+1;
    int tsize = (tail-middle);
    int aindex = front, findex = 0, tindex = 0;

    int front_half[fsize], tail_half[tsize];

    memset(front_half, 0, sizeof(int)*fsize);
    memset(tail_half, 0, sizeof(int)*fsize);

    for (findex; findex < fsize; findex++) {
        front_half[findex] = arr[aindex+findex];
    }

    for (int tindex = 0; tindex < tsize; tindex++) {
        tail_half[tindex] = arr[middle+tindex+1];
    }

    findex = tindex = 0;

    while (findex < fsize && tindex < tsize ) {

         if (front_half[findex] > tail_half[tindex]) {
              arr[aindex] = front_half[findex++];
         } else {
              arr[aindex] = tail_half[tindex++];
         }
         aindex++;
    }

    while (findex < fsize) {
        arr[aindex++] = front_half[findex++];
    }

    while (tindex < tsize) {
        arr[aindex++] = tail_half[tindex++];
    }
    return;
}

static void merge_sort(int *arr, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(arr, head, middle);
        merge_sort(arr, middle+1, end);
        merge_oper(arr, head, middle, end);
    }
    return;
}

int reductionOperations(int* nums, int numsSize) {

    int flag = 0;
    int count = 0;
    int *greater = NULL;
    int gindex = 0;

    if (numsSize) {

        greater = (int *) calloc(numsSize, sizeof(int)); 

        merge_sort(nums, 0, numsSize-1);

        for (int i = numsSize-2; i >= 0; i--) {
            if (nums[i] > nums[i+1]) {
                count += (greater[gindex] + 1);      
                gindex++;
                greater[gindex] = greater[gindex-1]+1;
            } else if (nums[i] == nums[i+1]) {
                count += greater[gindex];
                greater[gindex+1] = greater[gindex];
                gindex++;
            }
        }
        free(greater);
    }
    return count;
}

int main(void) {

    int arr[] = {1,1,1};
    int count = 0;

    count = reductionOperations(arr, sizeof(arr)/sizeof(*arr));

    printf("count: %d\n", count);

    return EXIT_SUCCESS; 
}
