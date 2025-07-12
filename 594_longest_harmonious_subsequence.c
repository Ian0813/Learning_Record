/*
 * =====================================================================================
 *
 *       Filename:  594_longest_harmonious_subsequence.c
 *
 *    Description:  longest harmonious subsequence
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

struct node {
    int value;
    int frequency;
};

static void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp; 

    return;
}

static void quick_sort(int *nums, int head, int end) {

    int last = head, tail = end;

    if (head < tail) {
        while (last < tail) {
            if (nums[head] > nums[tail]) {
                last++;    
                swap(&nums[last], &nums[tail]);
                continue;
            }
            tail--;
        }
        swap(&nums[head], &nums[last]);
        quick_sort(nums, head, last-1);
        quick_sort(nums, last+1, end);
    }
    return; 
}

static void collect_frequency(int *nums, int numsSize, struct node *nodes, int *len) {

    nodes[*len].value = nums[0];
    nodes[*len].frequency = 1; 

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nodes[*len].value) {
            *len += 1;
            nodes[*len].value = nums[i];
            nodes[*len].frequency = 1;
        } else {
            nodes[*len].frequency++;
        }
    }

    *len += 1;

    return;
}

static int get_longest_sub(struct node *nodes, int len) {

    int max_count = 0, temp = 0;

    for (int i = 0; i < len-1; i++) {

        if (abs(nodes[i+1].value - nodes[i].value) == 1) {
            temp = nodes[i+1].frequency + nodes[i].frequency;
        }
        max_count = temp > max_count ? temp : max_count;
    }

    return max_count;
}

int findLHS(int* nums, int numsSize) {

    struct node nodes[numsSize];
    int LHS = 0, len = 0;

    memset(nodes, 0, sizeof(nodes));
    quick_sort(nums, 0, numsSize-1);
    collect_frequency(nums, numsSize, nodes, &len);

    LHS = get_longest_sub(nodes, len);

    fprintf(stdout, "[%s] LHS: %d\n", __func__, LHS);

    return LHS;
}
