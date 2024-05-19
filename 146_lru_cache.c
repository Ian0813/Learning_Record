/*
 * =====================================================================================
 *
 *       Filename:  146_lru_cache.c
 *
 *    Description:  least recently cache  
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

/* Example 
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
*/

typedef enum {false, true} bool;

#define MAX_KEYVAL 10001

struct node {
    int key;
    int value;
    struct node *prev;
    struct node *next;
};

typedef struct {
    struct node *table[MAX_KEYVAL];
    struct node *head;
    struct node *tail;
    int num_entries;
    int max_size;
} LRUCache;

enum UPDATE_TYPE {
    D1_UPDATE,
    D2_UPDATE,
};

static void update_location(LRUCache *obj, int key, enum UPDATE_TYPE type) {

    struct node *prev = NULL, *temp = NULL;

    if (type == D1_UPDATE) {
        temp = obj->head;
        obj->head = obj->head->next;
        obj->head->prev = NULL;
        temp->prev = obj->tail;
        temp->next = NULL;
        obj->tail->next = temp;
        obj->tail = obj->tail->next;
    } else if (type == D2_UPDATE) {
        temp = obj->table[key]->next;
        prev = obj->table[key]->prev;
        prev->next = temp;
        temp->prev = prev;
        obj->table[key]->prev = obj->tail;
        obj->table[key]->next = obj->tail->next;
        obj->tail->next = obj->table[key];    
        obj->tail = obj->tail->next;
    }
    return;
}    

void print_list(struct node *node) {

    printf("\n%s start\n", __func__);

    while (node) {
        fprintf(stdout, "%d, %d\n", node->key, node->value);
        node = node->next;
    }

    printf("\n%s end\n", __func__);
    return;
}

LRUCache* lRUCacheCreate(int capacity) {

    LRUCache *obj = NULL;

    obj = (LRUCache *) malloc(sizeof(LRUCache));

    if (obj) {
        memset(obj->table, 0, sizeof(struct node *) * MAX_KEYVAL);
        obj->head = obj->tail = NULL;
        obj->num_entries = 0;
        obj->max_size = capacity;
    }
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {

    int rc = -1, flag = 0;

    if (obj) {
        if (obj->table[key]) {
            rc = obj->table[key]->value; 
        }        
    }

    if (rc != -1) {

        if (obj->tail->key != key) {
            if (obj->head->key == key) {
                update_location(obj, key, D1_UPDATE);
            } else {
                update_location(obj, key, D2_UPDATE);
            }
        }    
    }
    return rc;
}

void lRUCachePut(LRUCache* obj, int key, int value) {

    struct node *temp = NULL;

    if (obj) {

        if (obj->table[key]) {

            if (obj->tail->key != key) {

                obj->table[key]->value = value;   

                if (obj->head->key != key) {
                    update_location(obj, key, D2_UPDATE);
                } else {
                    update_location(obj, key, D1_UPDATE);
                }
            } else {
                obj->tail->value = value; 
            }

        } else {

            obj->num_entries++; 

            temp = (struct node *) malloc(sizeof(struct node));
            temp->key = key; 
            temp->value = value; 
            temp->next = temp->prev = NULL;

            if (!obj->head) {
                obj->table[key] = obj->head = obj->tail = temp;
            } else {
                obj->table[key] = temp;
                temp->prev = obj->tail;
                obj->tail->next = temp;
                obj->tail = obj->tail->next;
            }

            if (obj->num_entries > obj->max_size) {
                obj->table[obj->head->key] = NULL;
                temp = obj->head;
                if (obj->head == obj->tail) {
                    obj->tail = NULL; 
                }
                obj->head = obj->head->next;
                free(temp);
            }
        }
    }
    return; 
}

void lRUCacheFree(LRUCache* obj) {

    struct node *temp = NULL;

    if (obj) {
        while (obj->head) {
            temp = obj->head;
            obj->head = obj->head->next;
            free(temp); 
        }
        free(obj);
    }
    return;
}

int main(void) {

    LRUCache *obj = NULL;

    obj = lRUCacheCreate(2);

    lRUCachePut(obj, 1, 1);
    lRUCachePut(obj, 2, 2);
    printf("head: %d, %d\n", obj->head->key, obj->head->value);
    printf("tail: %d, %d\n", obj->tail->key, obj->tail->value);
    printf("lRUCacheGet(%d): %d\n", 1, lRUCacheGet(obj, 1));
    lRUCachePut(obj, 3, 3);
    printf("head: %d, %d\n", obj->head->key, obj->head->value);
    printf("tail: %d, %d\n", obj->tail->key, obj->tail->value);
    printf("lRUCacheGet(%d): %d\n", 2, lRUCacheGet(obj, 2));
    lRUCachePut(obj, 4, 4);
    printf("lRUCacheGet(%d): %d\n", 1, lRUCacheGet(obj, 1));
    printf("lRUCacheGet(%d): %d\n", 3, lRUCacheGet(obj, 3));
    printf("lRUCacheGet(%d): %d\n", 4, lRUCacheGet(obj, 4));
    printf("head: %d, %d\n", obj->head->key, obj->head->value);
    printf("tail: %d, %d\n", obj->tail->key, obj->tail->value);

#if 0
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
#endif
    lRUCacheFree(obj);

    return EXIT_SUCCESS;
}



/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/

