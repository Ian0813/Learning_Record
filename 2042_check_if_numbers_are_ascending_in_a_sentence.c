/*
 * =====================================================================================
 *
 *       Filename:  2042_check_if_numbers_are_ascending_in_a_sentence.c
 *
 *    Description:  Check if numbers are ascending in a sentence
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

#define MAX 200

typedef unsigned int bool;

enum {false, true};

#define isdigit(ch) (ch >= 48 && ch <= 57) 

int convert(char *s) {

    int num = 0; 

    while (isdigit(*s)) {
        num = num * 10 + (*s - 48);
		s++;
	}
	return num;
}	

bool areNumbersAscending(char* s) {

    int nums[MAX] = {0}, index = 0;
	bool flag = true;

    while (*s) {
        if (isdigit(*s)) {
            nums[index++] = convert(s); 
            while (isdigit(*s)) s++;
		} else {
            s++;
		}
	}

	for (int i = 0; i < (index - 1); i++) {
        printf("[%s] nums[%d]: %d\n", __func__, i, nums[i]); 
        if (nums[i] >= nums[i+1]) {
            flag = false; 
			break;
		}
	}
	return flag;
}


int main(void) {

    printf("result: %d\n", areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles"));

	return 0;
}
