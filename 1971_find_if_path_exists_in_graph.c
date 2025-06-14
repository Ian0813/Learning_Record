/*
 * =====================================================================================
 *
 *       Filename:  1971_find_if_path_exists_in_graph.c
 *
 *    Description:  find if path exists in graph
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

typedef enum {
    false = 0,
    true = 1
} bool;

enum {
    S_INDEX = 0,
    D_INDEX = 1,
    E_SIZE
};

struct graph {
    int **nodes;
    int *lens;
    int *degree;
    uint8_t *visited;
};

static void swap_ptr(int **ptr1, int **ptr2) {

    int *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    return;
}

static bool search_path(struct graph *g_edges, int src, int dst, int last) {

    bool rc = false;

    g_edges->visited[src] = true;

    for (int i = 0; i < g_edges->lens[src]; i++) {
        if (g_edges->nodes[src][i] == dst) {
            rc = true;
        } else if (!g_edges->visited[g_edges->nodes[src][i]]) {
            rc = search_path(g_edges, g_edges->nodes[src][i], dst, src);
        }

        if (rc)
            break;
    }
    return rc;
}

static void get_degree(int *degree, int **edges, int edgesSize) {

    for (int i = 0; i < edgesSize; i++) {
        degree[edges[i][S_INDEX]]++;
        degree[edges[i][D_INDEX]]++;
    }
    return;
}

static void create_graph(struct graph *g_edges, int **edges, int edgesSize) {

    get_degree(g_edges->degree, edges, edgesSize);

    for (int i = 0; i < edgesSize; i++) {
        if (!g_edges->nodes[edges[i][S_INDEX]])
            g_edges->nodes[edges[i][S_INDEX]] = (int *) calloc(g_edges->degree[edges[i][S_INDEX]], sizeof(int));

        if (!g_edges->nodes[edges[i][D_INDEX]])
            g_edges->nodes[edges[i][D_INDEX]] = (int *) calloc(g_edges->degree[edges[i][D_INDEX]], sizeof(int));

        g_edges->nodes[edges[i][S_INDEX]][g_edges->lens[edges[i][S_INDEX]]++] = edges[i][D_INDEX];
        g_edges->nodes[edges[i][D_INDEX]][g_edges->lens[edges[i][D_INDEX]]++] = edges[i][S_INDEX];
    }
    return;
}

static void free_graph(struct graph *g_edges, int size) {

    for (int i = 0; i < size; i++) {
        if (g_edges->lens[i]) {
            free(g_edges->nodes[i]);
        }
    }

    free(g_edges->nodes);
    free(g_edges->degree);
    free(g_edges->lens);

    return;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {

    bool rc = true;
    struct graph g_edges = {NULL};

    if (edgesSize) {

        g_edges.nodes = (int **) calloc(n, sizeof(int *));
        g_edges.degree = (int *) calloc(n, sizeof(int));
        g_edges.lens = (int *) calloc(n, sizeof(int));
        g_edges.visited = (uint8_t *) calloc(n, sizeof(uint8_t));

        create_graph(&g_edges, edges, edgesSize);

        rc = search_path(&g_edges, source, destination, source);
        free_graph(&g_edges, n);
    }
    return rc;
}
