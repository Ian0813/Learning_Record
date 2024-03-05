/*
 * =====================================================================================
 *
 *       Filename:  2785_sort_vowels_in_a_string.c
 *
 *    Description:  Sort vowels in a string 
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

#define ASCII_SIZE 128
#define MAX_LEN 100001
#define CHECK_VOWEL(ch, result) for (int k = 0; k < strlen(vowels); k++) { if (ch == vowels[k]) result = true; }

typedef enum {false, true} bool;
const char *vowels = "AEIOUaeiou";

void swap(char *ch1, char *ch2) {

    char temp = 0;

    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;

    return;
}

void quick_sort(char *arr, int head, int end) {

    int front = head, tail = end - 1, last = head;

    if (front < tail) {

        while (last < tail) {
            if (arr[front] > arr[tail]) {
                last++;         
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[front], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

char * sortVowels(char * s){

    bool check = false;
    char vowel_array[MAX_LEN] = {0};
    int counter[ASCII_SIZE] = {0}, occurs[strlen(vowels)]; 
    int index = 0;

    memset(occurs, 0, sizeof(int) * (strlen(vowels)+1));

    for (int i = 0; i < strlen(s); i++) {
        CHECK_VOWEL(s[i], check);
        if (check)
            counter[s[i]]++;
        check = false;
    }

    for (int i = 0; i < ASCII_SIZE; i++) {
        CHECK_VOWEL(i, check);
        if (check) {
            if (counter[i] > 0)
                occurs[index++] = counter[i];
            else
                occurs[index++] = 0;
        }
        check = false; 
    }

    index = 0;

    for (int i = 0; i < strlen(s); i++) {
        CHECK_VOWEL(s[i], check);
        while (check) {
            if (occurs[index] > 0) {
                s[i] = vowels[index];
                occurs[index]--;
                if (!occurs[index])
                    index++;
				break;
            } else if (!occurs[index])
                index++;
        }
        check = false;
    }
    return s;
}

int main(void) {

    char s[BUFSIZ] = "lEetcOde";

    sortVowels(s);

    printf("%s\n", s);
    return EXIT_SUCCESS;
}    
