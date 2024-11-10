/*
 * =====================================================================================
 *
 *       Filename:  455_assign_cookies.c
 *
 *    Description:  assign cookies
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

static void merge_process(int *arr, int head, int middle, int end) {

    int pre_size = (middle-head)+1, post_size = end-middle;
    int pre_arr[pre_size], post_arr[post_size];
    int pre_index = 0, post_index = 0, index = head;

    for (pre_index; pre_index < pre_size; pre_index++) {
        pre_arr[pre_index] = arr[head+pre_index];
    }

    for (post_index; post_index < post_size; post_index++) {
        post_arr[post_index] = arr[middle+post_index+1];
    }

    pre_index = post_index = 0;

    while (pre_index < pre_size && post_index < post_size) {
        if (pre_arr[pre_index] > post_arr[post_index]) {
            arr[index++] = pre_arr[pre_index++];
        } else {
            arr[index++] = post_arr[post_index++];
        }
    }

    while (pre_index < pre_size) {
        arr[index++] = pre_arr[pre_index++];
    }

    while (post_index < post_size) {
        arr[index++] = post_arr[post_index++];
    }
    return;
}

static void merge_sort(int *arr, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(arr, head, middle);
        merge_sort(arr, middle+1, end);
        merge_process(arr, head, middle, end);
    }
    return;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {

    int content_counter = 0;
    int greed_index = 0; 

    merge_sort(g, 0, gSize-1);
    merge_sort(s, 0, sSize-1);

    for (int i = 0; i < sSize; i++) {
        while (greed_index < gSize) {
            if (s[i] >= g[greed_index]) {
                content_counter++;
                greed_index++;
                break;
            }
            greed_index++;
        }
    }
    return content_counter;
}

int main(void) {

    int g[] = {1, 2}, s[] = {1, 2, 3};

    findContentChildren(g, sizeof(g)/sizeof(*g), s, sizeof(s)/sizeof(*s));

    return EXIT_SUCCESS;
}
