/*
 * =====================================================================================
 *
 *       Filename:  1614_maximum_nesting_depth_of_the_parentheses.c
 *
 *    Description:  Maximum nesting depth of the parentheses  
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

typedef unsigned int bool;
enum BOOL {false, true};

char queue[BUFSIZ] = {0};
int read_index = 0, write_index = 0;

bool is_empty(void) {
    if (read_index == write_index) {
        return true;
	}
	return false;
}

void enqueue(char ch) {
    if ((write_index+1) != read_index) {
        queue[write_index++] = ch;
		write_index %= BUFSIZ;
	}
	return;
}

char dequeue(void) {
    if (read_index != write_index) {
        return queue[read_index++];
	}
	return '\0';
}

int maxDepth(char* s) {

	unsigned int matched = 0, counter = 0;
	char ch = '\0';

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == ')') {
            enqueue(s[i]);
		}
	}

	while (!is_empty()) {
        ch = dequeue(); 
		if (ch == '(') {
            if (!matched) {
                counter++;
			} else {
                matched--;
			}
		} else if (ch == ')') {
            matched++;
		}
	}
	return counter;
}

int main(void) {

    char *test_str = "8*((1*(5+6))*(8/6))";
	char *test_str2 = "(1+(2*3)+((8)/4))+1";

    printf("max depth: %d\n", maxDepth(test_str));
    printf("max depth: %d\n", maxDepth(test_str2));

	return 0;
}

