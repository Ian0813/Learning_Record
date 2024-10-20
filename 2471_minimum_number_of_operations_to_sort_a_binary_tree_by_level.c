/*
 * =====================================================================================
 *
 *       Filename:  2471_minimum_number_of_operations_to_sort_a_binary_tree_by_level.c
 *
 *    Description:  Minimum number of operations to sort a binary tree by level  
 * *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef enum {false, true} bool; 

#ifdef BUFSIZ
#undef BUFSIZ
#define BUFSIZ 100000
#endif

#define TABLE_SIZE 100001

typedef struct TreeNode *NodePtr;

typedef struct queue {
    NodePtr *buffer; 
    int size;
    int windex;
    int rindex;
} *Queue;

static void swap(int *v1, int *v2) {

    int temp = 0;

    temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end-1; 

    if (front < tail) {

        while (last < tail) {
            if (arr[head] > arr[tail]) {
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

static Queue queue_init(int size) {

    Queue q = NULL;

    if (size) {
        q = (Queue) malloc(sizeof(struct queue));
        q->buffer = (NodePtr *) calloc(size, sizeof(NodePtr)); 
        q->windex = q->rindex = 0;
        q->size = size;
    }
    return q;
}

static bool enqueue(Queue q, NodePtr node) {

    bool rc = true;   

    if (q) {
        if ((q->windex+1)%q->size != q->rindex) {
            q->buffer[q->windex++] = node; 
            q->windex %= q->size;
        } else {
            rc = false;
        }
    } else {
        rc = false;
    }
    return rc;
}

static bool dequeue(Queue q) {

    bool rc = true;

    if (q) {
        if (q->windex != q->rindex) {
            q->rindex++;
            q->rindex %= q->size;
        } else {
            rc = false;
        }
    } else {
        rc = false;
    }
    return rc;
}

static NodePtr peek(Queue q) {

    if (q) {
        if (q->rindex != q->windex) {
            return q->buffer[q->rindex]; 
        }
    } 
    return NULL;
}

static void queue_delete(Queue q) {

    if (q) {
        free(q->buffer);
        free(q);
    }
    return;
}

static int get_swap_times(int *sort_buffer, int *num_buffer, int size, int *table) {

    int times = 0;
    int origin = 0, target = 0; 

    for (int i = 0; i < size; i++) {

        if (num_buffer[i] == sort_buffer[i]) {
            continue; 
        } else {
            origin = table[num_buffer[i]];
            target = table[sort_buffer[i]];
            swap(&num_buffer[i], &num_buffer[target]);
            table[num_buffer[i]] = origin;
            table[num_buffer[target]] = target;
            times++;
        }
    }
    return times;
}

static void reset_table(int *nums, int *table, int nums_size) {

    for (int i = 0; i < nums_size; i++) {
        table[nums[i]] = 0;
    }
    return;
}

void merge_process(int *arr, int low, int middle, int high) {

    int a1_size = middle-low+1, a2_size = high-middle;
    int arr1[a1_size], arr2[a2_size];  
    int a1_index = 0, a2_index = 0, arr_index = low;

    for (a1_index = 0; a1_index < a1_size; a1_index++) {
        arr1[a1_index] = arr[low+a1_index];
    }

    for (a2_index = 0; a2_index < a2_size; a2_index++) {
        arr2[a2_index] = arr[middle+a2_index+1];
    }

    a1_index = 0;
    a2_index = 0;

    while (a1_index < a1_size && a2_index < a2_size) {
        if (arr1[a1_index] > arr2[a2_index]) {
            arr[arr_index] = arr2[a2_index++]; 
        } else {
            arr[arr_index] = arr1[a1_index++]; 
        }
        arr_index++;
    }

    while (a1_index < a1_size) {
        arr[arr_index++] = arr1[a1_index++]; 
    }

    while (a2_index < a2_size) {
        arr[arr_index++] = arr2[a2_index++]; 
    }
    return;
}

void merge_sort(int *arr, int low, int high) {

    int middle = (high+low)/2;

    if (low < high) {
        merge_sort(arr, low, middle);
        merge_sort(arr, middle+1, high);
        merge_process(arr, low, middle, high);
    }
    return;
}

int minimumOperations(struct TreeNode* root) {

    Queue q = NULL;   
    NodePtr node = NULL;
    int minimum = 0;
    int num_buffer[BUFSIZ] = {0};
    int sort_buffer[BUFSIZ] = {0};
    int table[TABLE_SIZE] = {0};
    int index = 0;

    if (root) {

        q = queue_init(BUFSIZ);
        enqueue(q, root);

        while ((node = peek(q)) != NULL) {

            enqueue(q, NULL);

            while ((node = peek(q)) != NULL) {

                dequeue(q);

                table[node->val] = index;
                num_buffer[index++] = node->val;

                if (node->left)
                    enqueue(q, node->left);
                if (node->right)
                    enqueue(q, node->right);
            }
            dequeue(q);
            memcpy(sort_buffer, num_buffer, sizeof(int) * index);
            merge_sort(sort_buffer, 0, index-1);
            minimum += get_swap_times(sort_buffer, num_buffer, index, table);
            reset_table(num_buffer, table, index);
            memset(num_buffer, 0, sizeof(int) * index);
            memset(sort_buffer, 0, sizeof(int) * index);
            index = 0;
        }
        queue_delete(q);
    }
    return minimum; 
}
