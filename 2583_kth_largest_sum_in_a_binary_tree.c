/*
 * =====================================================================================
 *
 *       Filename:  2583_kth_largest_sum_in_a_binary_tree.c
 *
 *    Description:  kth largest sum in a binary tree
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
#define BUFSIZ 100001
#endif

#define MAX_SIZE (100001)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct TreeNode *NodePtr;
typedef struct queue *Queue;

struct queue {
    NodePtr *buffer;    
    int windex;
    int rindex;
    int size;
};

static void swap(long long *val1, long long *val2) {

    long long temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return;
}

static void quick_sort(long long *array, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {

        while (last < tail) { 
            if (array[head] > array[tail]) {
                last++; 
                swap(&array[last], &array[tail]);
                continue;
            }
            tail--;
        }

        swap(&array[head], &array[last]);
        quick_sort(array, head, last);
        quick_sort(array, last+1, end);
    }
    return;
}

static void merge_process(long long *array, int head, int middle, int end) {

    int a1size = (middle-head)+1, a2size = end-middle;  
    long long arr1[a1size], arr2[a2size];
    int a1index = 0, a2index = 0, index = head;

    while (a1index < a1size) {
        arr1[a1index] = array[head+a1index];
        a1index++; 
    }

    while (a2index < a2size) {
        arr2[a2index] = array[middle+a2index+1];
        a2index++;
    }

    a1index = a2index = 0; 

    while (a1index < a1size && a2index < a2size) {
        if (arr1[a1index] > arr2[a2index]) {
            array[index++] = arr2[a2index++];
        } else {
            array[index++] = arr1[a1index++];
        }
    }

    while (a1index < a1size) {
        array[index++] = arr1[a1index++];
    }

    while (a2index < a2size) {
        array[index++] = arr2[a2index++];
    }
    return;
}

static void merge_sort(long long *array, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(array, head, middle);
        merge_sort(array, middle+1, end);
        merge_process(array, head, middle, end);
    }
    return;
}

Queue create_queue(int size) {

    Queue obj = NULL;

    if (size) {
        obj = (Queue) malloc(sizeof(struct queue));
        obj->buffer = (NodePtr *) calloc(size, sizeof(NodePtr));
        obj->windex = obj->rindex = 0;
        obj->size = size;
    }
    return obj;
}

bool enqueue(Queue obj, NodePtr node) {

    bool rc = true;

    if (obj) {
        if ((obj->windex+1)%obj->size != obj->rindex) {
            obj->buffer[obj->windex++] = node;
            obj->windex %= obj->size;
        } else {
            rc = false;  
        }
    } else {
        rc = false;
    }
    return rc;
}

bool dequeue(Queue obj) {

    bool rc = true;

    if (obj) {
        if (obj->rindex%obj->size != obj->windex) {
            obj->rindex++;
            obj->rindex %= obj->size;
        } else {
            rc = false;  
        }
    } else {
        rc = false;
    }
    return rc;

}

NodePtr peek(Queue obj) {
    NodePtr node = NULL;         

    if (obj) {
        if (obj->rindex != obj->windex) {
            node = obj->buffer[obj->rindex];
        }    
    }
    return node;
}

void release_queue(Queue obj) {
    if (obj) {
        free(obj->buffer);
        free(obj);
    }
    return;
}

int get_height(NodePtr root) {

    int lheight = 0, rheight = 0;

    if (root) {
        lheight = get_height(root->left);
        rheight = get_height(root->right);
        return 1 + (MAX(lheight, rheight));
    }
    return 0;
}

static void sort_sum_array(long long *array, int size) {

    if (size > 1) {
        for (int i = size-1; i > 0; i--) {
            if (array[i] < array[i-1]) {
                swap(&array[i], &array[i-1]);   
            } else {
                break;    
            }
        }
    }
    return;
}

long long kthLargestLevelSum(struct TreeNode* root, int k) {

    Queue q = NULL;
    NodePtr node = NULL;
    int height = 0, index = 0;
    long long sum_array[MAX_SIZE] = {0LL};

    if (root) {

        height = get_height(root); 

        if (height < k)
            return -1;

        q = create_queue(BUFSIZ);

        enqueue(q, root);

        while (peek(q) != NULL) {

            enqueue(q, NULL);  

            while ((node = peek(q)) != NULL) {
                dequeue(q);

                if (node->left)
                    enqueue(q, node->left);

                if (node->right)
                    enqueue(q, node->right);
                sum_array[index] += node->val;
            }
            dequeue(q);
            index++;

        }
        release_queue(q);
        merge_sort(sum_array, 0, index-1);
    }
    return sum_array[index-k];
}
