/*
 * =====================================================================================
 *
 *       Filename:  2053_kth_distinct_string_in_an_array.c
 *
 *    Description:  Kth distinct string in an array  
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
#include <limits.h>

long long gethash(char *str) {

    static unsigned int p = 31;
    static unsigned long long m = LLONG_MAX;
    unsigned int p_pow = 1;
    long long hvalue = 0;

    for (int i = 0; i < strlen(str); i++) {
        hvalue += (str[i] - 'a' + 1) * (p*p_pow) % m;
        p_pow *= p;
        p_pow %= m;
    }
    return hvalue;
}

void compute_hash(char **arr, int arrSize, long long *hash_value) {

    for (int i = 0; i < arrSize; i++) {
        hash_value[i] = gethash(arr[i]); 
    }
    return;
}

char* kthDistinct(char** arr, int arrSize, int k) {

    long long *hash_values = (long long *) calloc(arrSize, sizeof(long long));
    int distinct_set[BUFSIZ] = {0}, dindex = 0, no_duplicate = 1;
    char *result = NULL;

    if (arrSize) {
        compute_hash(arr, arrSize, hash_values);
    }

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (j == i)
                continue; 
            if (hash_values[i] == hash_values[j]) {
                no_duplicate = 0;         
                break;
            }        
        }
        if (no_duplicate) {
            distinct_set[dindex++] = i;    
        }
        no_duplicate = 1;
    }

    free(hash_values);

    if (dindex >= k) {
        result = arr[distinct_set[k-1]];
    } else {
        result = (char *) calloc(1, sizeof(char));
    }
    return result; 
}
