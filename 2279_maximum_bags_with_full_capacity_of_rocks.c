/*
 * =====================================================================================
 *
 *       Filename:  2279_maximum_bags_with_full_capacity_of_rocks.c
 *
 *    Description:  maximum bags with full capacity of rocks
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

#define GET_SPACE(capacity, item) ((capacity)-(item))

struct collection {
    int *capacity;
    int *rocks;
};

static void swap(int *a, int *b) {

    int temp = *a;    
    *a = *b; 
    *b = temp;
    return;
}

static void quick_sort(struct collection *ptr, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {

        while (last < tail) {
            if (GET_SPACE(ptr->capacity[head], ptr->rocks[head]) > GET_SPACE(ptr->capacity[tail], ptr->rocks[tail])) {
                last++;
                swap(&ptr->capacity[last], &ptr->capacity[tail]);
                swap(&ptr->rocks[last], &ptr->rocks[tail]);
                continue;
            }
            tail--;
        }
        swap(&ptr->capacity[last], &ptr->capacity[head]);
        swap(&ptr->rocks[last], &ptr->rocks[head]);
        quick_sort(ptr, head, last);
        quick_sort(ptr, last+1, end);
    }
    return;
}

static void merge_process(struct collection *ptr, int head, int middle, int end) {

    int presize = (middle-head)+1, postsize = (end-middle); 
    int pre_c[presize], pre_r[presize], post_c[postsize], post_r[postsize];
    int pre_index = 0, post_index = 0, index = head;

    while (pre_index < presize) {
        pre_c[pre_index] = ptr->capacity[head+pre_index];
        pre_r[pre_index] = ptr->rocks[head+pre_index];
        pre_index++;
    }

    while (post_index < postsize) {
        post_c[post_index] = ptr->capacity[middle+post_index+1];
        post_r[post_index] = ptr->rocks[middle+post_index+1];
        post_index++;
    }

    post_index = pre_index = 0;

    while (pre_index < presize && post_index < postsize) {
        if (GET_SPACE(pre_c[pre_index], pre_r[pre_index]) < GET_SPACE(post_c[post_index], post_r[post_index])) {
            ptr->capacity[index] = pre_c[pre_index];  
            ptr->rocks[index] = pre_r[pre_index];  
            index++, pre_index++;
        } else {
            ptr->capacity[index] = post_c[post_index];  
            ptr->rocks[index] = post_r[post_index];  
            index++, post_index++;
        }
    }

    while (pre_index < presize) {
        ptr->capacity[index] = pre_c[pre_index];  
        ptr->rocks[index] = pre_r[pre_index];  
        index++, pre_index++;
    }

    while (post_index < postsize) {
        ptr->capacity[index] = post_c[post_index];  
        ptr->rocks[index] = post_r[post_index];  
        index++, post_index++;
    }
    return;
}

static void merge_sort(struct collection *ptr, int head, int end) {

    int middle = (end+head)/2;

    if (head < end) {
        merge_sort(ptr, head, middle);
        merge_sort(ptr, middle+1, end);
        merge_process(ptr, head, middle, end);
    }
    return;
}

int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks) {

    struct collection stuff_info = {NULL};
    int result = 0, space = 0;

    if (capacitySize) {

        stuff_info.capacity = capacity;    
        stuff_info.rocks = rocks;

        merge_sort(&stuff_info, 0, capacitySize-1);

        for (int i = 0; i < capacitySize; i++) {
            if (!(space = GET_SPACE(capacity[i], rocks[i]))) {
                ;
            } else if (additionalRocks-space >= 0) {
                additionalRocks -= space;  
            } else {
                break;
            }
            result++;
        }
    }
    return result;
}
