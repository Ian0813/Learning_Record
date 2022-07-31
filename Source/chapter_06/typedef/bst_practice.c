/*
 * =====================================================================================
 *
 *       Filename:  bst_practice.c
 *
 *    Description:  Implement a binary search tree. 
 *
 *        Version:  1.0
 *        Created:  2022年07月31日 16時35分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include <time.h>


void main(int argc, char *argv[]) {
		
	int nodes_num = 0, value = 0;
	Treeptr root = NULL;

	if (argc < 2) {
		fprintf(stdout, "Please enter the correct argument.\n");	
		fprintf(stdout, "Usage: %s \"the number of nodes\"\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	srand(time(NULL));
	nodes_num = atoi(argv[1]); 
	 
	for (int num = 1; num <= nodes_num; num++) {

		value = rand() % 100 + 1;	
		root = new_node(root, value);
	}
	printf("The root node value: %d\n", root->value);
	printf("The tree height: %d\n", tree_height(root));
	
	show_nodes(root);
	release_nodes(root);

	return;
}

Treeptr new_node(Treeptr node, int value) {

	if (node == NULL) {

		node = (Treeptr) malloc(sizeof(Treenode));
		if (node == NULL) {
			perror("malloc ");			
			exit(EXIT_FAILURE);
		}

		node->value = value;
		node->left = node->right = NULL;
		
	} else if (node->value < value) {
		node->right = new_node(node->right, value);
	} else if (node->value > value) {
		node->left = new_node(node->left, value);
	}	

	return node;
}

void show_nodes(Treeptr node) {

	if (node != NULL) {
		show_nodes(node->left);
		printf("val: %d\n", node->value);
	    show_nodes(node->right);
	} 
	
	return;
}

int tree_height(Treeptr node) {
	
	int left_num = 0, right_num = 0;

	if (node->left != NULL) {
		left_num += tree_height(node->left);
	} else if (node->right != NULL) {
		right_num += tree_height(node->right);
	}

	return left_num > right_num ? left_num + 1 : right_num + 1;
}	

void release_nodes(Treeptr node) {

	if (node != NULL) {
		release_nodes(node->left);
		release_nodes(node->right);
		free(node);
	}
	return;
}

