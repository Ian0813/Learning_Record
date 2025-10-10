/*
 * =====================================================================================
 *
 *       Filename:  28 find the index of the first occurrence in a string.c
 *
 *    Description:  find the index of the first occurrence in a string
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
#include <limits.h>
#include <stdint.h>

typedef enum {false, true} bool;

#define CH_TO_VAL(ch) ((ch)-'a'+1)
#define CHAR_SET_SIZE 256

static int get_exponent(int base, int exp, int prime) {

    if (!exp)
        return 1;
    return (base * get_exponent(base, exp-1, prime)) % prime;
}

static bool is_prime(int value) {
    for (int i = 2; (i * i) <= value; i++) {
        if (value % i) return false;
    }
    return true;
}

static int choose_random_base(int size) {
    return (rand() % 10) + size + 1; 
}

static int choose_random_prime(int min, int max) {

    int value = 0;

    do {
        value = (rand() % (max-min) + 1) + min;
    } while (!is_prime(value));

    return value;
}

static int poly_hash(char *pattern, int plen, int prime, int base) {

    int value = 0, multiplicand = 0;

    for (int i = plen-1; i >= 0; i--) {
        multiplicand = i ? base : 1;
        value = ((value * multiplicand) + (CH_TO_VAL(pattern[i]) * multiplicand)) % prime; 
    }

    return value;
}

static int pattern_search(char *content, char *pattern, int prime, int base) {

    int clen = 0, plen = 0, index = -1, thash = 0, phash = 0;
    long long power = 0L, temp = 0L, subtract_term = 0L;

    if (!content || !pattern) {
        return index; 
    }

    clen = strlen(content);
    plen = strlen(pattern);
    power = get_exponent(base, plen, prime);

    phash = poly_hash(pattern, plen, prime, base);

    for (int i = (clen-plen); i >= 0; i--) {

        if (!thash) {
            thash = poly_hash(&content[i], plen, prime, base);  
        } else {
            subtract_term = (power * CH_TO_VAL(content[i+plen])) % prime; 
            temp = (thash * base) % prime;
            thash = ((thash - subtract_term) + CH_TO_VAL(content[i])) % prime;
        }

        if (thash == phash) {
            index = i;
            break;
        }
    }

    return index; 
}

int strStr(char* haystack, char* needle) {

    int prime = 0, base = 0, index = 0;

    prime = choose_random_prime(10000, 20000);
    base = choose_random_base(CHAR_SET_SIZE);

    return pattern_search(haystack, needle, prime, base);
}
