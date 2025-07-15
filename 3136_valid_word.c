/*
 * =====================================================================================
 *
 *       Filename:  3136_valid_word.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2025年07月15日 21時34分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef enum {false, true} bool;

#define ADD_CONDITIONS(name, id) \
    VALID_##name = id,

#define VOWELS "aeiou"

typedef enum valid_conditions {
    ADD_CONDITIONS(MINIMUM, 0)
    ADD_CONDITIONS(CHECK_CONTAIN, 1)
    ADD_CONDITIONS(VOWEL, 2)
    ADD_CONDITIONS(CONSONANT, 3)
    VALID_CONDS_LENGTH
} valid_conds_t;

typedef enum valid_letter {
    VALID_LETTER_VOWEL = 0,
    VALID_LETTER_CONSONANT = 1
} valid_letter_t;

static bool check_contain(char *word) {

    bool rc = true;

    for (int i = 0; i < strlen(word); i++) {
        if (!isdigit(word[i]) && !isalpha(word[i])) {
            rc = false;
            break;
        }
    }
    return rc;
}

static bool check_letter(char *word, valid_letter_t type) {

    char *vowels = VOWELS;
    bool rc = false;

    if (type == VALID_LETTER_VOWEL) {
        for (int i = 0; i < strlen(word); i++) {
            for (int j = 0; j < strlen(VOWELS); j++) {
                if (tolower(word[i]) == vowels[j]) {
                    return true;
                }
            }
        }
    } else if (type == VALID_LETTER_CONSONANT) {
        for (int i = 0; i < strlen(word); i++, rc = false) {
            for (int j = 0; j < strlen(VOWELS); j++) {
                if (tolower(word[i]) == vowels[j] || isdigit(word[i])) {
                    rc = true;
                    break;
                }
            }
            if (!rc) {
                rc = true;
                break;
            }
        }
    }
    return rc;
}

static bool check_condition(char *word, valid_conds_t cond) {

    bool rc = false;

    switch (cond) {
        case VALID_MINIMUM: {
            rc = strlen(word) >= 3 ? true : false;
        }
        break;
        case VALID_CHECK_CONTAIN: {
            rc = check_contain(word);
        }
        break;
        case VALID_VOWEL: {
            rc = check_letter(word, VALID_LETTER_VOWEL);
        }
        break;
        case VALID_CONSONANT: {
            rc = check_letter(word, VALID_LETTER_CONSONANT);
        }
        break;
    }
    return rc;
}

bool isValid(char* word) {

    bool rc = true;

    for (int i = 0; i < VALID_CONDS_LENGTH; i++) {
        if (!(rc = check_condition(word, i))) {
            break;
        }
    }
    return rc;
}
