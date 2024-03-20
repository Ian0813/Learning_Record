/*
 * =====================================================================================
 *
 *       Filename:  1290_convert_binary_number_in_a_linked_list_to_integer.c
 *
 *    Description:  Convert binary number in a linked list to integer  
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
int getDecimalValue(struct ListNode* head) {

    int result = 0;

    while (head) {
        result = ((result * 2) + head->val);
        head = head->next;
    }
    return result;
}
