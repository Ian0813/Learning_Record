/*
 * =====================================================================================
 *
 *       Filename:  2287_rearrange_characters_to_make_target_string.c
 *
 *    Description:  Rearrange characters to make target string  
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

/*
 * input: s = "ilovecodingonleetcode", target = "code"
 * output: 2
 * explanation:
 * for the first copy of "code", take the letters at indices 4, 5, 6, and 7.
 * for the second copy of "code", take the letters at indices 17, 18, 19, and 20.
 * the strings that are formed are "ecod" and "code" which can both be rearranged into "code".
 * we can make at most two copies of "code", so we return 2.
*/

#define SIZE 26

typedef unsigned int bool;
enum BOOL {false, true};

void fill_table(int *table, char *s) {
    for (int i = 0; i < strlen(s); i++) {
        table[s[i] - 97]++;
	}
	return;
}

bool target_check(int *table, char *target) {

    int target_count[SIZE] = {0};

    for (int i = 0; i < strlen(target); i++) {
        target_count[target[i]-97]++;
    }

    for (int i = 0; i < strlen(target); i++) {
        if (table[target[i]-97] >= target_count[target[i]-97]) {
            table[target[i]-97] -= target_count[target[i]-97];
			target_count[target[i]-97] = 0;
		} else if (table[target[i]-97] < target_count[target[i]-97]) {
            return false;
		}
	}
    return true;
}

int rearrangeCharacters(char* s, char* target) {

    int table[SIZE] = {0};
	int max = 0;

	fill_table(table, s);

	while (target_check(table, target))
        max++;

	return max;
}

int main(void) {

    char *s1 = "ilovecodingonleetcode", *target1 = "code";
	char *s2 = "abcba", *target2 = "abc";
	char *s3 = "abbaccaddaeea", *target3 = "aaaaa";

	printf("rearrange: %d\n", rearrangeCharacters(s1, target1));
	printf("rearrange: %d\n", rearrangeCharacters(s2, target2));
	printf("rearrange: %d\n", rearrangeCharacters(s3, target3));

	return 0;
}

