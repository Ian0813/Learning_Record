/*
 * =====================================================================================
 *
 *       Filename:  11_container_with_most_water.c
 *
 *    Description:  container with most water
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

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct container_node {
    int src_value;
    int space;
} container_node;

static void node_init(container_node *node, int *nodes_len, int value, int index) {

    if (!node)
        return;

    if (sizeof(*node) == sizeof(container_node)) {
        node->src_value = value;
        *nodes_len += 1;
    }

    return;
}

static void node_calculate(container_node *nodes, int nodes_len, int dst, int dst_index) {

    int space = 0;

    for (int i = 0; i < nodes_len; i++) {
        space = MIN(nodes[i].src_value, dst) * abs(dst_index - i);
        nodes[i].space = space > nodes[i].space ? space : nodes[i].space;

        if (nodes[i].src_value >= dst)
            break;
    }

    return;
}

static int node_getmax(container_node *nodes, int nodes_len) {

    int max = 0;

    for (int i = 0; i < nodes_len; i++) {
        max = max < nodes[i].space ? nodes[i].space : max;   
    }

    return max;
}

int maxArea(int* height, int heightSize) {

    int max = 0;
    int nodes_len = 0; 
    container_node *nodes = NULL;

    if (height) {

        nodes = (container_node *) calloc(heightSize, sizeof(container_node));

        for (int i = 0; i < heightSize; i++) {
            node_init(&nodes[nodes_len], &nodes_len, height[i], i); 
            node_calculate(nodes, nodes_len, height[i], i);
        }

        max = node_getmax(nodes, nodes_len);

        if (nodes)
            free(nodes);
    }

    return max; 
}
