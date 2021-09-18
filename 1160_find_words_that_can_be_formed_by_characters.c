/*
 * =====================================================================================
 *
 *       Filename:  1160_find_words_that_can_be_formed_by_characters.c
 *
 *    Description:  find words that can be formed by characters
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

#define SIZE 26

typedef unsigned int bool;

enum BOOL {false, true};

void fill_table(int *table, char *chars) {

    for (int i = 0; i < strlen(chars); i++) {
        table[chars[i]-97]++;
	}
    return;
}

bool check_formed(int *table, char *word) {

    int alpha_count[SIZE] = {0};

    for (int i = 0; i < strlen(word); i++) {
        alpha_count[word[i] - 97]++;
	}

	for (int i = 0;i < strlen(word); i++) {
        if (table[word[i] - 97] < alpha_count[word[i] - 97]) {
            return false;
		}
	}
	return true;
}

int countCharacters(char** words, int wordsSize, char* chars) {

    int table[SIZE] = {0};
    int len = 0;

    fill_table(table, chars);

    for (int i = 0; i < wordsSize; i++) {
        if (check_formed(table, words[i])) {
            len += strlen(words[i]); 
		}
	}
	return len;
}

int main(void) {

    char *words[BUFSIZ] = {"hello","world","leetcode"}, *chars = "welldonehoneyr";

    printf("%d\n", countCharacters(words, 3, chars));

    return 0;
}
