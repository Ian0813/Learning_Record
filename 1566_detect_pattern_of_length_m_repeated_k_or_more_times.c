/*
 * =====================================================================================
 *
 *       Filename:  1566_detect_pattern_of_length_m_repeated_k_or_more_times.c
 *
 *    Description:  detect pattern of length m repeated k or more times
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

typedef enum {false, true} bool;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int *pattern;
    int count;
    int max;
    int size;
} pattern_pool;    

static void pool_allocate(pattern_pool *pool, int m) {

    if (!pool)
        return;

    pool->pattern = (int *) calloc(m, sizeof(int));

    return;
}

static bool pool_iscontain(pattern_pool *pool, int m, int k) {

    bool rc = false;

    if (!pool)
        return rc;

    if (pool->max >= k)
        rc = true;

    return rc;
}

static void pool_free(pattern_pool *pool) {

    if (!pool || (!pool->pattern))
        return;

    free(pool->pattern);

    return;
}

static void check_pattern(pattern_pool *pool, int *arr, int index, int m) {

    if (!pool)
        return;

    if (!memcmp(pool->pattern, &arr[index], sizeof(int) * m)) {
        pool->count++;  
    } else {
        pool->count = 0;     
    }

    if (!pool->count) {
        memcpy(pool->pattern, &arr[index], sizeof(int) * m);
        pool->count = 1;
    }

    pool->max = MAX(pool->count, pool->max);
    return;
}    

bool containsPattern(int* arr, int arrSize, int m, int k) {

    pattern_pool pool = {0};
    bool rc = false;

    pool_allocate(&pool, m); 

    for (int i = 0; i < (arrSize - (m-1)); i++) {

        for (int j = i; j < (arrSize - (m-1)); j += m) {
            check_pattern(&pool, arr, j, m);
        }

        rc = pool_iscontain(&pool, m, k);
        memset(pool.pattern, 0, sizeof(int) * m);
        pool.count = pool.max = 0;

        if (rc)
            break; 
    }

    pool_free(&pool);

    return rc;
}
