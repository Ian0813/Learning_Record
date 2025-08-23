/*
 * =====================================================================================
 *
 *       Filename:  1061_lexicographically_smallest_equivalent_string.c
 *
 *    Description:  lexicographically smallest equivalent string
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

typedef enum {false, true} bool;

#define TABLE_SIZE 26
#define CH_TO_INDEX(ch) (islower((ch)) ? ((ch) - 'a') : '\0')
#define INT_TO_CH(val) ((val) + 'a') 
#define MINIMUM_CH(ch1, ch2) ((ch1) < (ch2) ? (ch1) : (ch2))

typedef enum {
    TABLE_INIT = 0,
    TABLE_UPDATE = 1,
} table_option_t;

struct alphabet_group {
    char **groups;
    int group_size;
    int tracker[TABLE_SIZE];
};

static bool table_operation(char *s1, char *s2, struct alphabet_group *collection, int length, table_option_t opt) {

    int index1 = 0, index2 = 0, index = 0;
    char smaller = '\0';
    bool rc = false;

    switch (opt) {

        case TABLE_INIT:
            for (int i = 0; i < length; i++) {

                index1 = collection->tracker[CH_TO_INDEX(s1[i])];
                index2 = collection->tracker[CH_TO_INDEX(s2[i])];

                if (index1 == -1 && index2 == -1) {
                    if (s1[i] < s2[i]) {
                        collection->groups[collection->group_size][0] = s1[i];
                    } else {
                        collection->groups[collection->group_size][0] = s2[i];
                    }
                    collection->tracker[CH_TO_INDEX(s1[i])] = collection->group_size;
                    collection->tracker[CH_TO_INDEX(s2[i])] = collection->group_size;
                    collection->group_size++;
                } else if (index1 == -1 && index2 != -1) {
                    if (s1[i] < s2[i] && s1[i] < collection->groups[index2][0]) {
                        collection->groups[index2][0] = s1[i];
                    }
                    collection->tracker[CH_TO_INDEX(s1[i])] = index2; 
                } else if (index1 != -1 && index2 == -1) {
                    if (s2[i] < s1[i] && s2[i] < collection->groups[index1][0]) {
                        collection->groups[index1][0] = s2[i];
                    }
                    collection->tracker[CH_TO_INDEX(s2[i])] = index1; 
                }
            }
            rc = true;
        break; 

        case TABLE_UPDATE:
            for (int i = 0; i < length; i++) {

                index1 = collection->tracker[CH_TO_INDEX(s1[i])];
                index2 = collection->tracker[CH_TO_INDEX(s2[i])];

                smaller = collection->groups[index1][0] < collection->groups[index2][0] ?
                          collection->groups[index1][0] : collection->groups[index2][0]; 

                index = smaller == collection->groups[index1][0] ? index1 : index2;

                if (collection->groups[index1][0] > smaller) {
                    collection->tracker[CH_TO_INDEX(s1[i])] = index; 
                    rc = true;
                }

                if (collection->groups[index2][0] > smaller) {
                    collection->tracker[CH_TO_INDEX(s2[i])] = index; 
                    rc = true;
                }
            }
        break;
    }

    return rc;
}

char* smallestEquivalentString(char* s1, char* s2, char* baseStr) {

    char *result = NULL;
    int length = strlen(s1), base_length = strlen(baseStr);
    struct alphabet_group str_collection = {.groups = NULL, .group_size = 0, .tracker = {0}};

    str_collection.groups = (char **) calloc(TABLE_SIZE, sizeof(char *));
    result = (char *) calloc(base_length+1, sizeof(char)); 

    for (int i = 0; i < TABLE_SIZE; i++) {
        str_collection.groups[i] = (char *) calloc(TABLE_SIZE+1, sizeof(char));
        str_collection.tracker[i] = -1;
    }

    table_operation(s1, s2, &str_collection, length, TABLE_INIT);

    while (table_operation(s1, s2, &str_collection, length, TABLE_UPDATE))
        ;

    for (int i = 0; i < base_length; i++) {
        if (str_collection.tracker[CH_TO_INDEX(baseStr[i])] != -1)    
            result[i] = str_collection.groups[str_collection.tracker[CH_TO_INDEX(baseStr[i])]][0];
        else
            result[i] = baseStr[i];
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        free(str_collection.groups[i]);
    }
    free(str_collection.groups);

    return result;
}
