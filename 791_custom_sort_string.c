/*
 * =====================================================================================
 *
 *       Filename:  791_custom_sort_string.c
 *
 *    Description:  Custom sort string  
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

#define ALPHABET_LEN 26 

void swap(char *ch1, char *ch2) {

    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
    return;
}

void priority_sort(char *str, int head, int end, int *table) {

    int front = head, last = head, tail = end-1; 

    if (front < tail) {

        while (last < tail) {
            if (table[str[head]-'a'] && table[str[tail]-'a']) {
                if (table[str[head]-'a'] > table[str[tail]-'a']) {
                    last++;
                    swap(&str[last], &str[tail]);
                    continue;
                }
            }
            tail--;
        }

        if (table[str[head]-'a'] && table[str[tail]-'a']) 
            swap(&str[head], &str[last]);
        priority_sort(str, head, last, table);
        priority_sort(str, last+1, end, table);
    }    
    return;
}

char* customSortString(char* order, char* s) {

    int priority_table[ALPHABET_LEN] = {0};

    for (int i = 0; i < strlen(order); i++) {
        priority_table[order[i]-'a'] = i+1;
    }

    priority_sort(s, 0, strlen(s), priority_table);
    return s;
}

int main(void) {

    char order[BUFSIZ] = "cba", s[BUFSIZ] = "abcd";
    char *ptr = NULL;

    ptr = customSortString(order, s);
    printf("%s\n", ptr);

    return EXIT_SUCCESS;
}
