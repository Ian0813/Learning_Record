/*
 * =====================================================================================
 *
 *       Filename:  1249_minimum_remove_to_make_valid_parentheses.c
 *
 *    Description:  minimum remove to make valid parentheses
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

static int comp(const void *v1, const void *v2) {
    return (*(int *) v1) > (*(int *) v2);    
}    

static void collect(char *s, int slen, int *lindices, int *lsize, int *rindices, int *rsize) {

    for (int i = 0; i < slen; i++) {
        if (s[i] == '(') {
            lindices[*lsize] = i;  
            *lsize += 1;
        } else if (s[i] == ')') {
            rindices[*rsize] = i;  
            *rsize += 1;
        }
    }
    return;
}

static void collect_keep(int *lindices, int lsize, int *rindices, int rsize, int *keep_set, int *ksize) {

    int lindex = 0, rindex = 0;

    while (lindex < lsize && rindex < rsize) {
        if (lindices[lindex] < rindices[rindex]) {
            keep_set[*ksize] = lindices[lindex]; 
            *ksize += 1; 
            keep_set[*ksize] = rindices[rindex]; 
            lindex++;
            *ksize += 1;
        }
        rindex++;
    }

    return;
}

char* minRemoveToMakeValid(char* s) {

    int *lindices = NULL, *rindices = NULL, *keep_set = NULL; 
    int lsize = 0, rsize = 0, ksize = 0, len = 0, pindex = 0, kindex = 0;
    char *ptr = NULL;

    if (s) {

        len = strlen(s);
        lindices = (int *) calloc(len, sizeof(int));
        rindices = (int *) calloc(len, sizeof(int));
        keep_set = (int *) calloc(len, sizeof(int));
        ptr = (char *) calloc(len+1, sizeof(char));

        collect(s, len, lindices, &lsize, rindices, &rsize);

        collect_keep(lindices, lsize, rindices, rsize, keep_set, &ksize);
        qsort(keep_set, ksize, sizeof(int), comp);

        for (int i = 0; i < len; i++) {
            if ((s[i] == '(' || s[i] == ')') && (keep_set[kindex] == i && ksize)) {
                ptr[pindex++] = s[i];
                kindex++;
                ksize--;
            } else if (isalpha(s[i])) {
                ptr[pindex++] = s[i];
            }
        }

        free(lindices);
        free(rindices);
        free(keep_set);
    }

    return ptr;
}
