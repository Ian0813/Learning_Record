/*
 * =====================================================================================
 *
 *       Filename:  3692_majority_frequency_characters.c
 *
 *    Description:  majority frequency characters
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
#include <sys/param.h>

#define ALPHABET_SIZE 26
#define CH_TO_INDEX(ch) ((ch)-'a') 
#define VAL_TO_CH(val) ((val)+'a')

typedef struct {
    int *counts;
    int *count_sizes;
    int max_freq;
    int max_gsize;
    int max_count;
} frequency_recorder;

static void freq_process(char *s, int slen, frequency_recorder *recorder) {

    if (!recorder)
        return;

    for (int i = 0; i < slen; i++) {
        recorder->counts[CH_TO_INDEX(s[i])]++; 
        recorder->max_freq = MAX(recorder->max_freq, recorder->counts[CH_TO_INDEX(s[i])]);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (recorder->counts[i])
            recorder->count_sizes[recorder->counts[i]]++;
        recorder->max_gsize = MAX(recorder->max_gsize, recorder->count_sizes[recorder->counts[i]]);
    }

    for (int i = 0; i <= slen; i++) {
        if (recorder->max_gsize == recorder->count_sizes[i])
            recorder->max_count++; 
    }

    if (recorder->max_count > 1) {
        recorder->max_freq = 0; 
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (recorder->count_sizes[recorder->counts[i]] == recorder->max_gsize) {
                recorder->max_freq = MAX(recorder->max_freq, recorder->counts[i]);
            }
        }
    }
    return;
}

static void fill_result(frequency_recorder *recorder, char *result) {

    if (!recorder || !result)
        return;

    int rindex = 0;

    if (recorder->max_count == 1) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (recorder->count_sizes[recorder->counts[i]] == recorder->max_gsize) {
                result[rindex++] = VAL_TO_CH(i);
            }
        }    
    } else if (recorder->max_count > 1) {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (recorder->count_sizes[recorder->counts[i]] == recorder->max_gsize && recorder->counts[i] == recorder->max_freq) {
                result[rindex++] = VAL_TO_CH(i);
            }
        }
    }
    return;
}

char* majorityFrequencyGroup(char* s) {

    int slen = 0, final_freq = 0;
    frequency_recorder recorder = {0};
    char *result = NULL;

    if (s) {
        slen = strlen(s);
        result = calloc(slen+1, sizeof(char));
        recorder.counts = calloc(ALPHABET_SIZE, sizeof(int)); 
        recorder.count_sizes = calloc(slen+1, sizeof(int));

        freq_process(s, slen, &recorder);
        fill_result(&recorder, result);

        if (recorder.counts)
            free(recorder.counts);  
        if (recorder.count_sizes)
            free(recorder.count_sizes);  
    }
    return result;
}
