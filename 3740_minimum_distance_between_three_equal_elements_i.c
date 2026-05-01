/*
 * =====================================================================================
 *
 *       Filename:  3740 minimum distance between three equal elements i.c
 *
 *    Description:  minimum distance between three equal elements i
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX_ROW 100
#define TRIPLE_SET 3

typedef enum {false, true} bool;

typedef struct node {
    int value;
    struct node *next; 
} NodePtr;

typedef struct {
    NodePtr **nodes;
    int *chain_lens;
    int size;
} NodeChain;

static NodeChain *chain_allocate(int size) {

    NodeChain *ptr = NULL;

    ptr = (NodeChain *) calloc(1, sizeof(NodeChain));

    if (ptr) {
        ptr->size = size;
        ptr->nodes = (NodePtr **) calloc(size, sizeof(NodePtr)); 
        ptr->chain_lens = (int *) calloc(size, sizeof(int));
    }
    return ptr;
}

static NodePtr *chain_append(NodePtr *node, int target, int value) {

    NodePtr *temp = NULL;

    if (!node) {
        temp = (NodePtr *) calloc(1, sizeof(*node)); 
        temp->value = value;
        temp->next = NULL;
        node = temp;
    } else { node->next = chain_append(node->next, target, value); }

    return node;
}

static bool chain_display(NodePtr *node) {

    if (!node)
        return false;

    while (node) {
        printf("%d ", node->value);
        node = node->next;
    }
    return true;
}

static int chain_getdistance(NodePtr *node) {

    int x = 0, y = 0, z = 0, count = 0, distance = INT_MAX, val = 0;

    while (node) {

        count++;

        switch (count) {
            case 1:
                x = node->value;
            break;
            case 2:
                y = node->value;
            break;
            default: 
                z = node->value;
            break;
        }    

        if (count >= TRIPLE_SET) {
            val = abs(x-y) + abs(y-z) + abs(z-x);
            distance = val > distance ? distance : val;
            x = y;
            y = z;
        }
        node = node->next;
    }

    return distance;
}



static void chain_free(NodePtr *node) {

    if (!node)
        return;

    chain_free(node->next);
    free(node);

    return;
}    

int minimumDistance(int* nums, int numsSize) {

    int mini_distance = INT_MAX, distance = 0;
    NodeChain *chain = NULL;

    chain = chain_allocate(MAX_ROW+1);

    for (int i = 0; i < numsSize; i++) {
        chain->nodes[nums[i]] = chain_append(chain->nodes[nums[i]], nums[i], i);
        chain->chain_lens[nums[i]]++;
    }

    for (int i = 0; i < numsSize; i++) {
        if (chain->nodes[nums[i]]) {
            fprintf(stdout, "Chain number : %d\n", nums[i]);
            chain_display(chain->nodes[nums[i]]);
            putchar('\n');
        }
    }

    for (int i = 1; i < MAX_ROW+1; i++) {
        if (chain->nodes[i] && chain->chain_lens[i] >= TRIPLE_SET) {
            distance = chain_getdistance(chain->nodes[i]);
            mini_distance = distance < mini_distance ? distance : mini_distance;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        chain_free(chain->nodes[nums[i]]); 
        chain->nodes[nums[i]] = NULL;
    }

    return mini_distance == INT_MAX ? -1 : mini_distance; 
}
