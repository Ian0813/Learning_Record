/*
 * =====================================================================================
 *
 *       Filename:  3227_vowels_game_in_a_string.c
 *
 *    Description:  vowels game in a string
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

#define CH_TO_INDEX(ch) ((ch)-'a')
#define TABLE_SIZE 26
#define IS_VOWEL(ch) ((ch) == 'a' || (ch) == 'e' || (ch) == 'i' || (ch) == 'o' || (ch) == 'u')

typedef enum {
    VOWEL_ODD = 0,
    VOWEL_EVEN = 1,
    VOWEL_CLASS_LEN
} vowel_class;

typedef struct textbase {
    int table[TABLE_SIZE];
    int vowel_count;
} textbase;

static void textbase_init(char *s, textbase *t) {

    int len = strlen(s);

    if (!s || !t)
        return;

    for (int i = 0; i < len; i++) {
        t->table[CH_TO_INDEX(s[i])]++;
        t->vowel_count = IS_VOWEL(s[i]) ? (t->vowel_count + 1) : t->vowel_count;
    }

    return;
}

static bool substring_with_vowels(char *s, vowel_class class, char **remain, textbase *t) {

    int len = 0, count = 0;
    bool rc = true;

    if (s)
        len = strlen(s);

    do {
        if (class == VOWEL_ODD) {

            if (!len || !t->vowel_count) {
                rc = false;
                break;
            }

            if (t->vowel_count == len && (t->vowel_count%2)) {
                count = len;
                break;
            }

            count = (t->vowel_count % 2) ? t->vowel_count : (t->vowel_count-1);
            t->vowel_count -= count;

        } else if (class == VOWEL_EVEN) {

            if (!len || (IS_VOWEL(*s) && (t->vowel_count == 1))) {
                rc = false;
                break;
            }

            count = (t->vowel_count % 2) ? (t->vowel_count-1) : t->vowel_count; 
            t->vowel_count -= count;
        }

        if (rc) {
            for (int i = 0; count; i++, len--) {
                t->table[CH_TO_INDEX(s[i])]--;
                count = IS_VOWEL(s[i]) ? (count-1) : count;
                *remain = s + (i+1);
            }

            s = *remain;

            for (int i = 0; len && !IS_VOWEL(s[i]); i++, len--) {
                t->table[CH_TO_INDEX(s[i])]--;
                *remain = s + (i+1);
            }
        }

    } while (0);    

    return rc;
}

// "yliehnzlf"

bool doesAliceWin(char* s) {

    vowel_class class = VOWEL_ODD; 
    bool rc = true;
    char *remain = NULL;
    textbase t = {0};

    textbase_init(s, &t);

    while (substring_with_vowels(s, class, &remain, &t)) {
        class = (class + 1) % VOWEL_CLASS_LEN;
        s = remain; 
    };
    
    rc = class == VOWEL_ODD ? false : true;

    return rc;
}

