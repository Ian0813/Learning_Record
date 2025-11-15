/*
 * =====================================================================================
 *
 *       Filename:  811_subdomain_visit_count.c
 *
 *    Description:  subdomain visit count
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define DOMAIN_LEVEL_SIZE 3
#define DOMAIN_LEVEL_UNIT 1
#define BASE_DECIMAL 10 
#define BACKWARD_LOCATE(boundary, ptr, break_notation) while (ptr != boundary) { if (*ptr == break_notation) break; ptr--; }

typedef enum {
    TOP_LEVEL = 0,
    SUB_LEVEL = 1,
    THIRD_LEVEL = 2,
} level_type;

typedef struct domain_name {
    char *name;
    int count;
    struct domain_name *next;
} domain_name;

typedef struct domain_name_grp {
    domain_name *names[DOMAIN_LEVEL_SIZE]; 
    int names_size; 
} domain_name_grp;

static bool domain_lookup(domain_name *name_node, char *name, int occurrence) {

    bool rc = false;

    if (!name_node)
        return rc;

    while (name_node) {
        if (!strcmp(name_node->name, name)) {
            name_node->count += occurrence;
            rc = true;
            break;
        }
        name_node = name_node->next;
    }

    return rc;
}

static domain_name *domain_add(domain_name *name_node, char *name, int occurrences) {

    domain_name *temp = NULL; 

    if (!name_node) {
        name_node = (domain_name *) malloc(sizeof(*name_node));
        name_node->name = strdup(name);
        name_node->count = occurrences; 
        name_node->next = NULL; 
    } else {
        name_node->next = domain_add(name_node->next, name, occurrences);
    }

    return name_node;
}

static void domain_free(domain_name *name_node) {

    domain_name *temp = name_node;

    while (temp) {
        name_node = name_node->next; 
        free(temp->name);
        free(temp);
        temp = name_node;
    }

    return;
}

static void domain_display(domain_name *name_node) {

    domain_name *temp = name_node; 

    while (temp) {
        printf("[%s] name : %s, coutn : %d\n", __func__, temp->name, temp->count);
        temp = temp->next;
    }    
    return;
}

static void domain_name_process(char **cpdomains, int cpdomainsSize, domain_name_grp *grp) {

    char *ptr = NULL, *remain = NULL, *temp = NULL, *dup = NULL;
    int occurrences = 0;
    level_type level = TOP_LEVEL;

    if (!grp)
        return;

    for (int i = 0; i < cpdomainsSize; i++) {

        ptr = strtok_r(cpdomains[i], " ", &remain);

        if (!ptr)
            continue;

        occurrences = (int) strtol(ptr, NULL, BASE_DECIMAL);
        dup = strdup(remain);
        remain = dup;
        temp = strrchr(remain, '.');

        while (*temp == '.') {

            if (!domain_lookup(grp->names[level], temp + 1, occurrences)) {
                grp->names[level] = domain_add(grp->names[level], temp + 1, occurrences);
                grp->names_size++;
            }

            level += DOMAIN_LEVEL_UNIT; 
            temp--;
            BACKWARD_LOCATE(remain, temp, '.');
        }

        if (!domain_lookup(grp->names[level], remain, occurrences)) {
            grp->names[level] = domain_add(grp->names[level], remain, occurrences);
            grp->names_size++;
        }

        free(dup);
        level = TOP_LEVEL;
    }
    return;    
}

static void generate_result(domain_name_grp *grp, char **result, int *returnSize) {

    char buffer[BUFSIZ] = {0};
    domain_name *temp = NULL;

    if (!grp)
        return;

    *returnSize = 0;

    for (int i = 0; i < DOMAIN_LEVEL_SIZE; i++) {

        temp = grp->names[i];

        while (temp) {
            sprintf(buffer, "%d %s", temp->count, temp->name); 
            temp = temp->next;
            result[*returnSize] = strdup(buffer);
            *returnSize += 1;     
        }
    }

    return;  
}

char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize) {

    char **result = NULL;
    char *ptr = NULL, *remain = NULL;
    domain_name_grp grp = {0};

    domain_name_process(cpdomains, cpdomainsSize, &grp);

    //printf("The number of domain name : %d\n", grp.names_size);

    if (grp.names_size)
        result = (char **) calloc(grp.names_size, sizeof(char *));

    generate_result(&grp, result, returnSize);

    for (int i = 0; i < DOMAIN_LEVEL_SIZE; i++) {
        //domain_display(grp.names[i]);
        domain_free(grp.names[i]);
    }

    return result;
}
