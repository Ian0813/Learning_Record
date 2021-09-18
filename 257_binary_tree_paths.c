/*
 * =====================================================================================
 *
 *       Filename:  257_binary_tree_paths.c
 *
 *    Description:  Traversal the binary tree  
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

#define MAX 100

typedef struct TreeNode *TreePtr;
typedef unsigned int bool;

enum BOOL {false, true};

int leafs[BUFSIZ] = {0};
int lindex = 0;

struct TreeNode {
    int val;
	TreePtr left;
	TreePtr right;
};

TreePtr create(TreePtr root, int val) {
    if (root == NULL) {
        root = (TreePtr) malloc(sizeof(struct TreeNode));
		root->val = val;
		root->left = root->right = NULL;
	} else if (root->val > val) {
        root->left = create(root->left, val); 
	} else if (root->val < val) {
        root->right = create(root->right, val); 
	}
	return root;
}

void traversal(TreePtr root) {

    if (root != NULL) {
        printf("%d ", root->val);
		if (root->left == NULL && root->right == NULL) {
            leafs[lindex++] = root->val;
		}
		traversal(root->left);
		traversal(root->right);
	}
	return;
}

bool is_exist(TreePtr root, int target) {

    bool rc = false;

    if (root != NULL) {
        if (root->val == target && root->left == NULL && root->right == NULL) {
            rc = true;
        }
        rc = rc == true ? rc : is_exist(root->left, target);
        rc = rc == true ? rc : is_exist(root->right, target);
	}
	return rc;
}

void create_path(TreePtr root, int target, char **paths, int *index) {

    char temp[BUFSIZ] = {0};

    if (root != NULL) {

        if (root->val == target && root->left == NULL && root->right == NULL) {
            sprintf(temp, "%d", root->val); 
		} else {
            sprintf(temp, "%d->", root->val); 
		}

        strcat(paths[*index], temp);

        if (is_exist(root->left, target) && is_exist(root->right, target)) {
            strcpy(paths[*index+1], paths[*index]);
			create_path(root->left, target, paths, index);
			*index = *index + 1;
			create_path(root->right, target, paths, index);
		} else if (is_exist(root->left, target)) {
			create_path(root->left, target, paths, index);
        } else if (is_exist(root->right, target)) {
		    create_path(root->right, target, paths, index);
		}
	}
	return;
}

void release(TreePtr root) {

    if (root != NULL) {
        release(root->left);
        release(root->right);
		free(root);
	}
	return;
}

void swap(int *a, int *b) {

    int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

void quick_sort(int *arr, int front, int tail) {

    int head = front, end = tail - 1, last = front;

	if (head < end) {
        while (last < end) {
            if (arr[head] > arr[end]) {
                last++;
				swap(&arr[last], &arr[end]);
				continue;
			}
			end--;
		}
		swap(&arr[head], &arr[last]);
		quick_sort(arr, front, last);
		quick_sort(arr, last + 1, tail);
    }
    return;
}

#if 0
bool is_dup(int *leafs, int index, int val) {

   for (int i = 0; i < index; i++) {
       if (leafs[i] == val) {
           return true; 
	   }
   }
   return false;
}
#endif

int main(void) {

    int value = 0, prev = 0;
    TreePtr root = NULL;
	//char *path = NULL, *backup = NULL;
	char *arrays[BUFSIZ] = {NULL};
	int aindex = 0;

	//int arr[6] = {7, 5, 9, 6, 11, 13};

	srand(time(NULL));

	for (int i = 0; i < 30; i++) {
        root = create(root, (value = rand()%1000)); 
        //root = create(root, (value = 1)); 
        //root = create(root, (value = arr[i])); 
	}

	traversal(root);
	printf("\n");

	//path = (char *) calloc(BUFSIZ, sizeof(char));
	//backup = (char *) calloc(BUFSIZ, sizeof(char));
    //memset(backup, 0, sizeof(char) * BUFSIZ);
	//printf("backup: %ld\n", strlen(backup));
	//arrays = (char **) calloc(BUFSIZ, sizeof(char *));

	for (int i = 0; i < BUFSIZ; i++) {
        arrays[i] = (char *) calloc(BUFSIZ, sizeof(char));
	}

    //quick_sort(leafs, 0, lindex); 

	for (int i = 0; i < lindex; i++) {
        if (leafs[i] == prev)
            continue;
        fprintf(stdout, "lead node: %d\n", leafs[i]);
		create_path(root, leafs[i], arrays, &aindex);
		aindex += 1;
		//printf("path: %s\n", path);
        //arrays[aindex++] = strdup(path);
		//if (strlen(backup) > 0) {
        //    arrays[aindex++] = strdup(backup); 
		//	memset(backup, 0, sizeof(char) * BUFSIZ);
		//}
		//memset(path, 0, sizeof(char) * BUFSIZ);
		prev = leafs[i];
	}

    //free(path);
	//free(backup);
    for (int i = 0; i < aindex; i++) {
        printf("%s\n", arrays[i]);
    }

    release(root);

    for (int i = 0; i < BUFSIZ; i++) {
        free(arrays[i]); 
    }

    return 0;
}
