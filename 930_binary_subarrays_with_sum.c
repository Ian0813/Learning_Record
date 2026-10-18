/*
 * =====================================================================================
 *
 *       Filename:  930_binary_subarrays_with_sum.c
 *
 *    Description:  binary subarrays with sum
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/* 
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]  
*/

enum {
    COUNT_ZERO = 0,
    COUNT_ONE = 1,
    COUNT_LEN
};

typedef struct {
    int windex;
    int rindex;
    int *buffer;
    int bsize;
} Queue;

static Queue *create_queue(int bsize) {

    Queue *obj = NULL;

    obj = calloc(1, sizeof(*obj));

    if (obj) {
        obj->buffer = calloc(bsize, sizeof(int));   

        if (!obj->buffer) {
            free(obj);
            return NULL;
        }
        obj->windex = obj->rindex = 0;
        obj->bsize = bsize;
    }
    return obj;
}

static bool en_queue(Queue *obj, int val) {

    if (!obj)
        return false;

    if ((obj->windex+1)%obj->bsize == obj->rindex)
        return false;

    obj->buffer[obj->windex] = val;
    obj->windex++;
    obj->windex %= obj->bsize;
    return true;
}

static bool de_queue(Queue *obj) {

    if (!obj)
        return false;

    if (obj->rindex == obj->windex)
        return false;

    obj->rindex++;
    obj->rindex = obj->rindex % obj->bsize;
    return true;
}

static int peek_queue(Queue *obj) {

    if (!obj)
        return -1;

    if (obj->rindex == obj->windex)
        return -1;

    return obj->buffer[obj->rindex];
}    

static void free_queue(Queue *obj) {
    if (obj) {
        free(obj->buffer);
        free(obj);
    }
    return;
}

static int prefix_calculate(Queue *obj, int goal, int value, int current_pos, int prelen) {

    int temp = 0, accumlator = 0;

    while ((temp = peek_queue(obj)) != -1 && (value-temp) >= goal) {
        if (goal == (value - temp))
            accumlator++;
        value -= temp;
        de_queue(obj);

        if ((accumlator+prelen) == current_pos)
            break;
    }
    return accumlator;
}

static int traversal_counter(int head, int tail, int *nums, int sum, int goal) {

    int count = 0;

    while (sum == goal && head <= tail) {
        count++;
        if (nums[head])
            sum--;
        head++;
    }
    return count;
}

int numSubarraysWithSum(int* nums, int numsSize, int goal) {

    int head = 0, tail = 0, sum = 0, count = 0;

    while (tail < numsSize) {

        if (nums[tail])
            sum++;

        while (sum > goal && head < tail) {
            if (nums[head])
                sum--;
            head++;
        }

        if (sum == goal) {
            count += traversal_counter(head, tail, nums, sum, goal);
            //fprintf(stdout, "[%s] count : %d\n", __func__, count);
        }
        tail++;
    }
    return count;
}

int main(void) {

    int arr[] = {0, 0, 0, 1, 0, 0, 1, 0, 0, 0};
    printf("%d\n", numSubarraysWithSum(arr, sizeof(arr)/sizeof(arr[0]), 2));

    //Queue *obj = NULL;
    //obj = create_queue(BUFSIZ);

    //for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    //    en_queue(obj, arr[i]);

    //while (peek_queue(obj) != -1) {
    //    printf("%d ", peek_queue(obj));
    //    de_queue(obj);
    //}

    //free_queue(obj);
    return EXIT_SUCCESS;
}
