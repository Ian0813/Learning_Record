/*
 * =====================================================================================
 *
 *       Filename:  459_repeated_substring_pattern.c
 *
 *    Description:  repeated_substring_pattern
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

typedef enum {false, true} bool;

#define CH_TO_VAL(ch) ((ch)-'a'+1)

#define BASE_INIT 16
#define PRIME_INIT 65599

static bool is_prime(int value) {

    for (int i = 2; (i * i) <= value; i++) {
        if (!(value % i)) return false;
    }

    return true;
}

static int get_random_base(int modular) {
    return rand() % modular + 1;
}

static int get_random_prime(int lower_bound) {

    int prime = lower_bound + 1;

    for (int i = lower_bound + 1; !is_prime(i); i++)
        prime = i;
    return prime;
}

static long long get_exponent(int base, int exp, int modular) {

    if (!exp)
        return 1;
    return (base * get_exponent(base, exp-1, modular)) % modular;
}

static int poly_hash(char *pattern, int plen, int prime, int base) {

    int multiplicand = 0, hash = 0;

    for (int i = plen-1; i >= 0; i--) {
        multiplicand = i ? base : 1;
        hash = ((hash * multiplicand) + (CH_TO_VAL(pattern[i]) * multiplicand)) % prime;
    }

    return hash;
}

static bool pattern_repeated(char *content, char *pattern, int prime, int base) {

    int clen = 0, plen = 0;
    long long power = 0L, subtract_term = 0L, temp = 0L, thash = 0L, phash = 0L;

    if (!content || !pattern) {
        return false;
    }

    clen = strlen(content);
    plen = strlen(pattern);
    phash = poly_hash(pattern, plen, prime, base);
    power = get_exponent(base, plen, prime);

    printf("[%s] pattern: %s\n", __func__, pattern);

    for (int i = (clen - plen); i >= 0; i--) {

        if (!thash) {
            thash = poly_hash(&content[i], plen, prime, base);
        } else {
            subtract_term = (power * CH_TO_VAL(content[i+plen])) % prime;
            temp = thash * base;
            thash = (((temp - subtract_term) % prime) + CH_TO_VAL(content[i])) % prime;
        }

        if (i % plen)
            continue;
        //printf("[%s] phash: %d, thash: %d (%d)\n", __func__, phash, thash, i);
        if (thash != phash) {
            return false;
        }
    }
    return true;
}

#if 0 
bool repeatedSubstringPattern(char* s) {

    bool rc = false;
    int len = 0, base = 0, prime = 0, sub_len = 0;
    char pattern[BUFSIZ] = {0};

    len = strlen(s);
    sub_len = len/2;
    base = get_random_base(BASE_INIT);
    prime = get_random_prime(PRIME_INIT);

    while (sub_len) {

        if (!(len % sub_len)) {
            memcpy(pattern, s, sub_len);
            rc = pattern_repeated(s, pattern, prime, base);
            memset(pattern, 0, sub_len);
        }

        if (rc)
            break;
        sub_len--;
    }

    return rc;
}
#endif

static bool is_repeated(char *s, char *pattern, int slen, int plen) {

    int index = plen;

    for (index; index < slen; index += plen) {
        if (memcmp(&s[index], pattern, plen)) {
            return false;
        }
    }

    return true;
}

bool repeatedSubstringPattern(char* s) {

    bool rc = false;
    int len = 0, sub_len = 0;
    char pattern[BUFSIZ] = {0};

    len = strlen(s);
    sub_len = len/2;

    while (sub_len && !rc) {
        if (!(len % sub_len)) {
            memcpy(pattern, s, sub_len);
            rc = is_repeated(s, pattern, len, sub_len);
            memset(pattern, 0, sub_len);
        }
        sub_len--;
    }

    return rc;
}
