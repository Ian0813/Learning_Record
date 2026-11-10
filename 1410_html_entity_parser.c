/*
 * =====================================================================================
 *
 *       Filename:  1410_html_entity_parser.c
 *
 *    Description:  1410 html entity parser
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
#include <stdbool.h>

#define MAX_ITEMS_SIZE 32
#define MAX_PATTERN_LEN 128

typedef struct {
    char *entity;
    char symbol;
} item_sym_t;

typedef struct item_collection {
    item_sym_t *items;
    int cur_size;
    int items_size;
} item_collection;

static item_collection *items_init(int size) {

    item_collection *collection = NULL;

    if (!size)
        return collection;

    if (size > MAX_ITEMS_SIZE)
        return collection;

    collection = malloc(sizeof(item_collection));

    if (collection) {
        collection->items = calloc(size, sizeof(item_sym_t));
        collection->cur_size = 0;
        collection->items_size = size;
    }
    return collection;
}

static bool items_add_item(item_collection *collection, char *entity, char symbol) {

    if (!collection || !entity)
        return false;

    if (collection->cur_size == MAX_ITEMS_SIZE)
        return false;

    collection->items[collection->cur_size].entity = entity;
    collection->items[collection->cur_size].symbol = symbol;
    collection->cur_size++;
    return true;
}

static void items_free(item_collection *collection) {

    if (collection) {
        free(collection->items);
        free(collection);
    }
    return;
}

static bool items_entity_map_symbol(item_collection *collection, char *pattern, char *symbol) {

    bool rc = false;

    if (!pattern || !symbol)
        return rc;

    for (int i = 0; i < collection->cur_size; i++) {
        if (!strcmp(pattern, collection->items[i].entity)) {
            *symbol = collection->items[i].symbol;
            rc = true;
            break;
        }
    }
    return rc;
}

char* entityParser(char* text) {

    item_collection *obj = NULL;
    char pattern[MAX_PATTERN_LEN] = {0}, *result = NULL, sym = '\0';
    int tlen = 0, plen = 0, rindex = 0;

    if (!text)
        return result;

    tlen = strlen(text);
    result = calloc(tlen+1, sizeof(char));
    obj = items_init(MAX_ITEMS_SIZE);

    if (obj && result) {

        items_add_item(obj, "quot", '"');
        items_add_item(obj, "apos", '\'');
        items_add_item(obj, "amp", '&');
        items_add_item(obj, "gt", '>');
        items_add_item(obj, "lt", '<');
        items_add_item(obj, "frasl", '/');

        for (int i = 0; i < tlen; i++) {
            if (text[i] == '&') {
                sscanf(&text[i], "&%[a-z];", pattern);

                if (items_entity_map_symbol(obj, pattern, &sym)) {
                    plen = strlen(pattern);
                    if ((i + plen + 1) < tlen && text[i + plen + 1] == ';') {
                        result[rindex++] = sym;
                        i += (strlen(pattern) + 1);
                        continue;
                    }
                }
            }
            result[rindex++] = text[i];
        }
        items_free(obj);
    }
    return result;
}
