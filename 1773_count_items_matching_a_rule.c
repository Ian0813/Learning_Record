/*
 * =====================================================================================
 *
 *       Filename:  1773_count_items_matching_a_rule.c
 *
 *    Description:  count items matching a rule
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

typedef enum {
    INDEX_NONE = -1,
    INDEX_TYPE = 0,
    INDEX_COLOR = 1,
    INDEX_NAME = 2,
} index_map_t;

static int get_type_mapping(char *key) {

    if (!strcmp(key, "type"))
       return INDEX_TYPE;
    else if (!strcmp(key, "color"))
       return INDEX_COLOR;
    else if (!strcmp(key, "name"))
       return INDEX_NAME;
    return INDEX_NONE;
}

int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey, char* ruleValue) {

    int type_index = 0, count = 0;

    type_index = get_type_mapping(ruleKey);

    if (type_index == INDEX_NONE)
        return count;

    for (int i = 0; i < itemsSize; i++) {
        if (!strcmp(items[i][type_index], ruleValue)) 
            count++;
    }
    return count;
}
