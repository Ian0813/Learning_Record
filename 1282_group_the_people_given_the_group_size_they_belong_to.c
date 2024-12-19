/*
 * =====================================================================================
 *
 *       Filename:  1282_group_the_people_given_the_group_size_they_belong_to.c
 *
 *    Description:  group the people given the group size they belong to
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX_GROUPS 501
#define MAX_MEMBERS 501

struct group_cluster {
    int groups[MAX_GROUPS][MAX_MEMBERS];
    int g_length[MAX_GROUPS];
};

static void group_distribute(int *groupSizes, int groupSizesSize, struct group_cluster *cluster) {

    for (int i = 0; i < groupSizesSize; i++) {
        cluster->groups[groupSizes[i]][cluster->g_length[groupSizes[i]]++] = i;        
    }
    return;
}

int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes) {

    int **result = NULL, *r_length = NULL;
    int rindex = 0, tindex = 0, copy_len = 0;
    struct group_cluster cluster = {0};

    result = (int **) calloc(MAX_GROUPS, sizeof(int *));
    r_length = (int *) calloc(MAX_GROUPS, sizeof(int));

    group_distribute(groupSizes, groupSizesSize, &cluster);

    for (int i = 0; i < MAX_GROUPS; i++) {
        while (cluster.g_length[i] > 0) {
            if (cluster.g_length[i] >= i) {
                copy_len = i; 
            } else {
                copy_len = cluster.g_length[i];
            }
            result[rindex] = (int *) calloc(copy_len, sizeof(int));
            r_length[rindex] = i;
            memcpy(result[rindex], &cluster.groups[i][tindex], sizeof(int) * copy_len);
            tindex += copy_len;
            cluster.g_length[i] -= copy_len;
            rindex++;
        }
        tindex = 0;
    }

    *returnColumnSizes = r_length;
    *returnSize = rindex;

    return result;
}

