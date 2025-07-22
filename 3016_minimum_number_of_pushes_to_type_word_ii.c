/*
 * =====================================================================================
 *
 *       Filename:  3016_minimum_number_of_pushes_to_type_word_ii.c
 *
 *    Description:  Minimum number of pushed to type word ii  
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

#define ALPHABET_SIZE 26
#define CH_TO_INDEX(ch) ((ch)-'a')
#define GET_FREQUENCY(freq, ch) freq[CH_TO_INDEX(ch)]

enum {
    LAYER_ONE = 1, 
    LAYER_TWO = 2,
    LAYER_THREE = 3,
    LAYER_FOUR = 4,
};

void get_frequency(char *word, int *frequencies, char *restrict_series, int *len) {

    int length = strlen(word);

    for (int i = 0; i < length; i++) {

        if (!frequencies[CH_TO_INDEX(word[i])]) {
            restrict_series[*len] = word[i]; 
            *len += 1;
        }    

        frequencies[word[i]-'a']++;
    }
    return;
}

static void merge_operation(char *series, int *frequencies, int head, int middle, int end) {

    char str1Size = (middle-head) + 1, str2Size = (end-middle);
    char str1[str1Size], str2[str2Size];
    int str1_index = 0, str2_index = 0, index = head;

    for (int i = 0; i < str1Size; i++) {
        str1[i]= series[head + i];
    }

    for (int i = 0; i < str2Size; i++) {
        str2[i]= series[middle + i + 1];
    }

    while (str1_index < str1Size && str2_index < str2Size) {
        if (GET_FREQUENCY(frequencies, str1[str1_index]) > GET_FREQUENCY(frequencies, str2[str2_index])) {
            series[index++] = str1[str1_index++];
        } else {
            series[index++] = str2[str2_index++];
        }    
    }

    while (str1_index < str1Size) {
        series[index++] = str1[str1_index++];
    }

    while (str2_index < str2Size) {
        series[index++] = str2[str2_index++];
    }

    return;
}

static void merge_sort(char *series, int *frequencies, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(series, frequencies, head, middle);    
        merge_sort(series, frequencies, middle+1, end);    
        merge_operation(series, frequencies, head, middle, end);
    }

    return;
}

static int segment_counter(int *frequencies, int *segment_count, int *max_index) {

    int index = 0, segment = 8, max_count = 0;

    for (int i = 0; i < segment; i++) {
        segment_count[index] += frequencies[i];
    }

    max_count = segment_count[index];
    *max_index = index;
    index++;

    for (index; index < ALPHABET_SIZE; index++) {
        segment_count[index] = (segment_count[index-1] - frequencies[index-1]) + frequencies[(segment+(index-1))%ALPHABET_SIZE];

        if (max_count < segment_count[index]) {
            max_count = segment_count[index];  
            *max_index = index; 
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%d ", segment_count[i]);
    }

    putchar('\n');
    return max_count;
}

int minimumPushes(char* word) {

    int minimum = 0;
    int frequencies[ALPHABET_SIZE] = {0};
    char restrict_series[ALPHABET_SIZE] = "";
    int layer = LAYER_ONE, segment = 8, len = 0;

    get_frequency(word, frequencies, restrict_series, &len);
    merge_sort(restrict_series, frequencies, 0, len-1);

    for (int i = 0; i < len; i++) {

        if (i && !(i % segment)) {
            layer++;
        }
        minimum += (GET_FREQUENCY(frequencies, restrict_series[i]) * layer);
    }

    return minimum;
}
