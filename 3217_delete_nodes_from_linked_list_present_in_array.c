/*
 * =====================================================================================
 *
 *       Filename:  3217_delete_nodes_from_linked_list_present_in_array.c
 *
 *    Description:  Delete nodes from linked list present in array  
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

#define TABLE_SIZE 100001

typedef enum {false, true} bool; 
typedef struct ListNode *NodePtr;

NodePtr remove_node(NodePtr head, int *table) {

    NodePtr prev = NULL, cur = NULL;

    cur = head;

    while (cur) {
        if (table[cur->val]) {
            if (prev) {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            } else {
                head = head->next;
                free(cur);
                cur = head;
            }
            continue;
        }
        prev = cur;
        cur = cur->next;
    }
    return head;
}    

static bool check_num(NodePtr head, int val) {

    bool rc = false;

    while (head) {
        if (head->val == val) {
            rc = true; 
            break;
        }
        head = head->next; 
    }
    return rc;
}

static void fill_table(int *table, int *nums, int size) {

    for (int i = 0; i < size; i++) {
        table[nums[i]]++;
    }
    return;
}

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {

    int count = 0;
    int table[TABLE_SIZE] = {0};

    fill_table(table, nums, numsSize);

    head = remove_node(head, table);
    return head;
}
