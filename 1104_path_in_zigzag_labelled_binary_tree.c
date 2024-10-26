/*
 * =====================================================================================
 *
 *       Filename:  1104_path_in_zigzag_labelled_binary_tree.c
 *
 *    Description:  path in zigzag labelled binary tree
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
#include <stdint.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static void reverse(int *arr, int start, int end) {

    int temp = 0;

    for (int i = start, j = end; i < j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    return;
}

static int get_amount(int label, int *height) {

    int amount = 1;
    int increase = 2;

    while (amount < label) {
        amount += increase;
        increase *= 2;
        *height += 1;
    }
    return amount;
}

static int get_2power(int exp) {

    static int base = 2;
    int val = 1;

    while (exp--) {
        val *= 2;     
    }
    return val;
}

static void form_array(int *nodes_arr, int height) {

    int level = 1;
    int level_head = 0;
    int level_end = 0;

    while (level <= height) {

       if (!(level%2)) {
           reverse(nodes_arr, level_head, level_end);
       }
       level_head += get_2power(level-1);
       level_end += get_2power(level);
       level++;
    }
    return; 
}

static void fill_array(int *nodes_arr, int amount) {

    for (int i = 0; i < amount; i++) {
        nodes_arr[i] = i+1;
    }
    return;
}

static int get_label_index(int *nodes_arr, int size, int label) {

    int index = 0;

    for (int i = 0; i < size; i++) {
        if (nodes_arr[i] == label) {
            index = i;
            break;
        }
    }
    return index;
}

static void get_path_to_root(int *nodes_arr, int *path, int label_index, int *index) {

    while (label_index) {
        path[*index] = nodes_arr[label_index]; 
        if (!(label_index%2)) {
            label_index = label_index/2;  
            label_index = label_index ? label_index-1 : label_index;
        } else {
            label_index /= 2;
        }
        *index += 1;
    }
    path[*index] = nodes_arr[label_index];
    return;
}

int* pathInZigZagTree(int label, int* returnSize) {

    int32_t *nodes_arr = NULL;
    int32_t amount = 0;
    int height = 1;
    int *path = NULL, pindex = 0; 
    int label_index = 0;

    amount = get_amount(label, &height);
    nodes_arr = (int *) calloc(amount, sizeof(int));
    path = (int *) calloc(height, sizeof(int));

    fill_array(nodes_arr, amount);
    form_array(nodes_arr, height);

    for (int i = 0; i < amount; i++) {
        printf("%d(%d) ", nodes_arr[i], i);
    }
    putchar('\n');

    label_index = get_label_index(nodes_arr, amount, label);
    printf("label_index: %d\n", label_index);
    get_path_to_root(nodes_arr, path, label_index, &pindex);

    reverse(path, 0, pindex);
    *returnSize = pindex+1;

    free(nodes_arr);
    return path;
}

int main(void) {

    int size = 0;
    int *arr = NULL;

    arr = pathInZigZagTree(26, &size);

    for (int i = 0; i < size; i++) {
        printf("%d(%d) ", arr[i], i);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
