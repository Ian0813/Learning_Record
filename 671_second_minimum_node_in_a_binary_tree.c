/*
 * =====================================================================================
 *
 *       Filename:  671_second_minimum_node_in_a_binary_tree.c
 *
 *    Description:  Second minimum node in a binary tree 
 *
 *         Author:  Ian
 * =====================================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 1000

/* Definition for a binary tree node. */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void swap(int *i1, int *i2) {

    int temp = *i1;

	*i1 = *i2;
	*i2 = temp;
	return;
}

void quick_sort(int *numbers, int front, int tail) {

    int head = front, end = tail - 1, last = front;

	if (head < end) {
        while (last < end) {
            if (numbers[head] > numbers[end]) {
                last++; 
				swap(&numbers[last], &numbers[end]);
				continue;
			}
			end--;
		}
		swap(&numbers[head], &numbers[end]);
		quick_sort(numbers, front, last);
		quick_sort(numbers, last + 1, tail);
	}
	return;

}

void inorder(struct TreeNode *root, int *numbers, int *index) {

    if (root != NULL) {
        inorder(root->left, numbers, index);
		numbers[(*index)++] = root->val;
        inorder(root->right, numbers, index);
	}
	return;
}

int findSecondMinimumValue(struct TreeNode* root) {

    int *numbers = (int *) calloc(MAX, sizeof(int));
	int index = 0, mini = 0, sec_mini = 0;

	inorder(root, numbers, &index);
	quick_sort(numbers, 0, index);
	mini = numbers[0];

	for (int i = 0; i < index; i++) {
        if (numbers[i] > mini) {
            sec_mini = numbers[i];
			break;
		}
	}
	free(numbers);
	return sec_mini;
}

int main(void) {
    return 0;
}
