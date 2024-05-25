/*
 * =====================================================================================
 *
 *       Filename:  2058_find_the_minimum_and_maximum_number_of_nodes_between_critical_points.c
 *
 *    Description:  A critical point in a linked list is defined as either a local maxima or a local minima.
 *
 *                  A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
 *                  
 *                  A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
 *                  
 *                  Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
 *                  
 *                  Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the 
 *                  minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. 
 *                  If there are fewer than two critical points, return [-1, -1].
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
#include <limits.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define CPOINTS_SIZE 100001
#define RESULT_SIZE 2

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode *NodePtr;
int find_cpoints(NodePtr head, int *cpoints, int *cpindex) {

    int node_counter = 0, minimal = 0, maximal = 0;
    NodePtr prev = NULL;

    while (head) {

        node_counter++;

        if (prev) {
            if (head->val < prev->val) {
                minimal = 1; 
            } else if (head->val > prev->val) {
                maximal = 1;
            }
        }

        if (head->next) {
            if (head->val < head->next->val && minimal) {
                cpoints[*cpindex] = node_counter;
                *cpindex += 1;
            } else if (head->val > head->next->val && maximal) {
                cpoints[*cpindex] = node_counter;
                *cpindex += 1;
            }
        }
		minimal = maximal = 0;
		prev = head;
        head = head->next;
    }
    return node_counter;
}

int find_minimal(int *cpoints, int cpindex) {

    int minimal = INT_MAX;

    for (int i = 0; i < (cpindex-1); i++) {
       if ((cpoints[i+1] - cpoints[i]) < minimal) {
          minimal = cpoints[i+1] - cpoints[i];
       }

	   if (minimal == 1) {
           break;
	   }
    }
    return minimal;
}

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {

    int cpoints[CPOINTS_SIZE] = {0}, cpindex = 0, node_count = 0;
    int *result = calloc(RESULT_SIZE, sizeof(int));

    memset(result, -1, sizeof(int) * RESULT_SIZE);
    node_count = find_cpoints(head, cpoints, &cpindex);

    if (node_count > 1) {
        result[0] = find_minimal(cpoints, cpindex);
        result[1] = cpoints[cpindex-1] - cpoints[0];
    }
    *returnSize = RESULT_SIZE;

    return result;
}
