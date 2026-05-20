/*
 * =====================================================================================
 *
 *       Filename:  3913 sort vowels by frequency.c
 *
 *    Description:  sort vowels by frequency
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef enum {false, true} bool;

#define VOWEL_LEN 5 
#define ALPHA_LEN 26
#define VOWEL_TO_INDEX(ch) ((ch) - 'a')

typedef struct vowel_freq {
    char *ptr;
    char *full_str;
    int *freq;
    int *prior;
    int size;
    int type_count;
} vowel_freq;

static void swap(char *c1, char *c2) {

    char temp = *c1;

    *c1 = *c2;
    *c2 = temp;

    return;
}

static bool is_vowel(char ch) {
    char low = tolower(ch);
    return (low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u'); 
}

static bool is_prior(char c1, char c2, int *weight) {

    return weight[VOWEL_TO_INDEX(c1)] > weight[VOWEL_TO_INDEX(c2)];
}

static void quick_sort(vowel_freq *info, int head, int end) {

    int last = head, tail = end;

    if (!info)
        return;

    if (head < end) {

        while (last < tail) {
            if (info->freq[VOWEL_TO_INDEX(info->ptr[head])] < info->freq[VOWEL_TO_INDEX(info->ptr[tail])] ||
                ((info->freq[VOWEL_TO_INDEX(info->ptr[head])] == info->freq[VOWEL_TO_INDEX(info->ptr[tail])]) && is_prior(info->ptr[tail], info->ptr[head], info->prior))) {
                last++;
                swap(&info->ptr[last], &info->ptr[tail]);   
                continue;
            }    
            tail--;
        }    

        swap(&info->ptr[head], &info->ptr[last]);
        quick_sort(info, head, last-1);
        quick_sort(info, last+1, end);
    }

    return;
}

static void get_vowel_freq(vowel_freq *info, char *s, int slen) {

    if (!info)
        return;

    int weight = VOWEL_LEN;

    info->ptr = (char *) calloc(slen+1, sizeof(char));
    info->freq = (int *) calloc(ALPHA_LEN, sizeof(int));
    info->prior = (int *) calloc(ALPHA_LEN, sizeof(int));

    for (int i = 0; i < slen; i++) {
        if (is_vowel(s[i])) {
            info->ptr[info->size] = s[i];
            info->freq[VOWEL_TO_INDEX(s[i])]++;
            info->size++;

            if (!info->prior[VOWEL_TO_INDEX(s[i])]) {
                info->prior[VOWEL_TO_INDEX(s[i])] = weight;   
                info->type_count++;
                weight--;
            }
        }
    }
    return;
}

static void free_vowel_freq(vowel_freq *info) {

    if (!info)
        return;

    if (info->ptr)
        free(info->ptr);

    if (info->freq)
        free(info->freq);

    if (info->prior)
        free(info->prior);
    return;
}

static void merge_operation(vowel_freq *info, int head, int middle, int end) {

    int a1_size = middle - head + 1, a2_size = end - middle;
    int a1[a1_size], a2[a2_size];
    int a1_index = 0, a2_index = 0, index = head; 

    for (int i = 0; i < a1_size; i++) {
        a1[i] = info->ptr[i + head];
    }

    for (int i = 0; i < a2_size; i++) {
        a2[i] = info->ptr[i + middle + 1];
    }

    while (a1_index < a1_size && a2_index < a2_size) {
        if (info->freq[VOWEL_TO_INDEX(a1[a1_index])] > info->freq[VOWEL_TO_INDEX(a2[a2_index])] ||
            ((info->freq[VOWEL_TO_INDEX(a1[a1_index])] == info->freq[VOWEL_TO_INDEX(a2[a2_index])]) && is_prior(a1[a1_index], a2[a2_index], info->prior))) {
            info->ptr[index++] = a1[a1_index++]; 
        } else {
            info->ptr[index++] = a2[a2_index++]; 
        }
    }

    while (a1_index < a1_size) {
        info->ptr[index++] = a1[a1_index++]; 
    }

    while (a2_index < a2_size) {
        info->ptr[index++] = a2[a2_index++]; 
    }

    return;
}

static void merge_sort(vowel_freq *info, int head, int end) {

    int middle = (head+end) / 2;

    if (head < end) {
        merge_sort(info, head, middle);
        merge_sort(info, middle+1, end);
        merge_operation(info, head, middle, end);
    }

    return;
}

char* sortVowels(char* s) {

    vowel_freq vowel_info = {0};
    int len = 0, pindex = 0;
    char *ptr = NULL;

    if (s) {
            
        len = strlen(s);
        ptr = (char *) calloc(len+1, sizeof(char));

        get_vowel_freq(&vowel_info, s, len);
        merge_sort(&vowel_info, 0, vowel_info.size-1);

        for (int i = 0, j = 0; i < len; i++) {
            if (is_vowel(s[i])) {
                ptr[pindex++] = vowel_info.ptr[j++];    
            } else {
                ptr[pindex++] = s[i];
            }
        }
        free_vowel_freq(&vowel_info);
    }

    return ptr; 
}
