/*
 * =====================================================================================
 *
 *       Filename:  1472_design_browser_history.c
 *
 *    Description:  Design browser history - use double-linked list  
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

/* Example:
 * Input:
 * ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
 * [["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
 * Output:
 * [null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]
 * 
 * Explanation:
 * BrowserHistory browserHistory = new BrowserHistory("leetcode.com");
 * browserHistory.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
 * browserHistory.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
 * browserHistory.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
 * browserHistory.back(1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
 * browserHistory.back(1);                   // You are in "facebook.com", move back to "google.com" return "google.com"
 * browserHistory.forward(1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
 * browserHistory.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
 * browserHistory.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
 * browserHistory.back(2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
 * browserHistory.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
*/

struct node {
    char *url;
    struct node *prev;
    struct node *next;
};

typedef struct node *NodePtr;
    
typedef struct {
    NodePtr head;
    NodePtr tail;
} BrowserHistory;

static NodePtr release_node(NodePtr node) {

    NodePtr temp = NULL;

    while (node) {
        temp = node; 
        node = node->next;
        free(temp->url);
        free(temp);
    }
    return NULL;
}    

static NodePtr create_node(NodePtr node, char *url) {

    NodePtr new = NULL; 

    new = (NodePtr) malloc(sizeof(struct node));            
    new->url = strdup(url);
    new->next = new->prev = NULL; 

    if (node == NULL) {
        node = new;
    } else {
        node->next = release_node(node->next);
        new->prev = node; 
        node->next = new;
        node = node->next;
    }
    return node;
}

BrowserHistory* browserHistoryCreate(char* homepage) {
    
    BrowserHistory *obj = (BrowserHistory *) malloc(sizeof(BrowserHistory));

    if (obj) {
        obj->tail = obj->head = NULL; 
        obj->tail = obj->head = create_node(obj->head, homepage);
    }
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {

    if (obj && url) {
        obj->tail = create_node(obj->tail, url);
    }
    return;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {

    if (obj) {
        while (obj->tail->prev && steps) {
            obj->tail = obj->tail->prev;                            
            steps--;
        }
    }
    return obj->tail->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {

    if (obj) {
        while (obj->tail->next && steps) {
            obj->tail = obj->tail->next;
            steps--;
        }
    }
    return obj->tail->url;
}

void browserHistoryFree(BrowserHistory* obj) {
    release_node(obj->head);
    free(obj);
    return;
}

int main(void) {

    BrowserHistory *obj = browserHistoryCreate("leetcode.com");
    char *url = NULL; 

    browserHistoryVisit(obj, "google.com");       // You are in "leetcode.com". Visit "google.com"
    browserHistoryVisit(obj, "facebook.com");     // You are in "google.com". Visit "facebook.com"
    browserHistoryVisit(obj, "youtube.com");      // You are in "facebook.com". Visit "youtube.com"
                                                  //
    url = browserHistoryBack(obj, 1);                   // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    fprintf(stdout, "url: %s\n", url);
    url = browserHistoryBack(obj, 1);                 // You are in "facebook.com", move back to "google.com" return "google.com"
    fprintf(stdout, "url: %s\n", url);
    url = browserHistoryForward(obj, 1);                // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    fprintf(stdout, "url: %s\n", url);
    browserHistoryVisit(obj, "linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
    url = browserHistoryForward(obj, 2);                // You are in "linkedin.com", you cannot move forward any steps.
    fprintf(stdout, "url: %s\n", url);
    url = browserHistoryBack(obj, 2);                   // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
    fprintf(stdout, "url: %s\n", url);
    url = browserHistoryBack(obj, 7);                   // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
    fprintf(stdout, "url: %s\n", url);

    browserHistoryFree(obj);

    return EXIT_SUCCESS;
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);

 * char* param_2 = browserHistoryBack(obj, steps);

 * char* param_3 = browserHistoryForward(obj, steps);

 * browserHistoryFree(obj);
*/
