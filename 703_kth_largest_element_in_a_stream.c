/*
 * =====================================================================================
 *
 *       Filename:  703_kth_largest_element_in_a_stream.c
 *
 *    Description:  Kth kargest element in a stream   
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

#define BUFFER_SIZE 20000

typedef struct {
    int buffer[BUFFER_SIZE];    
    int kth_largest;
    int size;
} KthLargest;

void minheap(int *nums, int *size, int val) {

    int temp = 0;

    nums[*size] = val;
    *size += 1; 

    for (int i = *size-1; i > 0; i--) {
        if (nums[i] < nums[i-1]) {
            temp = nums[i];
            nums[i] = nums[i-1];
            nums[i-1] = temp;
        }        
    }
    return;
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {

    KthLargest *obj = NULL;    

    obj = (KthLargest *) malloc(sizeof(KthLargest));

    if (obj) {
        memset(obj->buffer, 0, sizeof(int) * BUFFER_SIZE);
        obj->kth_largest = k;
        obj->size = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        minheap(obj->buffer, &obj->size, nums[i]);
    }
    return obj; 
}

int kthLargestAdd(KthLargest* obj, int val) {

    int rc = 0;    

    minheap(obj->buffer, &obj->size, val);

    return obj->buffer[obj->size-obj->kth_largest]; 
}

void kthLargestFree(KthLargest* obj) {

    if (obj)
        free(obj);
    return;
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/

