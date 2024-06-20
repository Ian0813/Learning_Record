/*
 * =====================================================================================
 *
 *       Filename:  23_merge_k_sorted_lists.c
 *
 *    Description:  merge k sorted lists  
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
#include <limits.h>

struct ListNode {
    int val; struct ListNode *next;
};
typedef struct ListNode *NodePtr;

struct list_node {
    int val;
    struct list_node *prev;
    struct list_node *next;
};

typedef enum {false, true} bool;
typedef struct list_node *node_ptr;

struct prio_queue {
    node_ptr front;
    node_ptr tail;
    int amount;
};

struct prio_queue *prioq_create(void) {

    struct prio_queue *q = NULL;

    q = (struct prio_queue *) malloc(sizeof(struct prio_queue));

    if (q) {
        q->front = NULL;
        q->tail = NULL;
        q->amount = 0;
    }
    return q;
}

bool isempty(struct prio_queue *q) {

    if (q->front == NULL && q->tail == NULL) {
        return true;
    }
    return false;
}

void prioq_insert(struct prio_queue *q, int val) {

    struct list_node *new = NULL, *probe = NULL, *last = NULL;

    if (q) {

        probe = q->front;

        new = (struct list_node *) malloc(sizeof(struct list_node)); 
        new->val = val;
        new->prev = new->next = NULL; 

        if (!q->front) {
            q->front = q->tail = new;
        } else  {
            if (val <= q->front->val) {
                new->next = q->front;
                q->front->prev = new;
                q->front = new;
            } else if (val >= q->tail->val) {
                new->prev = q->tail;
                q->tail->next = new;
                q->tail = new;
            } else {

                while (probe->val < val) {
                    last = probe;
                    probe = probe->next;
                }
                last->next = new;
                new->prev = last;
                probe->prev = new;
                new->next = probe;
            }
        }
    }
    return; 
}

void prioq_remove(struct prio_queue *q, int val) {

    node_ptr probe = NULL;

    if (q) {

        if (q->front->val == val) {
        
            probe = q->front; 
            q->front = q->front->next;
            q->front->prev = NULL;

            if (probe == q->tail) {
                q->tail = NULL;
            }
        } else if (q->tail->val == val) {

            probe = q->tail; 
            q->tail = q->tail->prev;
            q->tail->next = NULL;

            if (probe == q->front) {
                q->front = NULL;
            }
        } else {

            probe = q->front->next;

            while (probe && probe->val != val) {
                probe = probe->next;          
            }

            if (probe) {
                probe->prev->next = probe->next;
                probe->next->prev = probe->prev;
            }
        }
        free(probe);
    }
    return;
}

void prioq_delete(struct prio_queue *q) {

    node_ptr node = NULL; 
    if (q) {
        while (q->front) {
            node = q->front;
            //printf("node: %p, %d\n", node, node->val);
            q->front = q->front->next;
            free(node);
        }
        free(q);
    }
    return;
}

void print_queue(struct prio_queue *q) {

    node_ptr node = NULL;
    int prev_val = 0, check = 0;

    if (q) {
        node = q->front;
        prev_val = node->val;

        if (node) {
            while (node) {
                //printf("[%s] node: %p\n", __func__, node);
                printf("%3d ", node->val);
                if (node->val < prev_val) {
                    check = 1;
                    break;
                }
                prev_val = node->val;
                node = node->next;
            }
            printf("\n");
            if (check) {
                printf("[%s] The sequence in wrong order.\n", __func__);
            }
        }
    }
    return;
}

int main(void) {

    struct prio_queue *pq = NULL;
    srand(time(NULL));

    pq = prioq_create();

    for (int i = 0; i < 50000; i++) {
        prioq_insert(pq, rand() % INT_MAX);
    }
    print_queue(pq);
    //for (int i = 0; i < 60; i++) {
    //    prioq_remove(pq, rand() % 1000);
    //}
    //print_queue(pq);
#if 0
    prioq_insert(pq, 1);
    prioq_insert(pq, 2);
    prioq_insert(pq, 3);
    prioq_insert(pq, 4);
    prioq_insert(pq, 5);
    prioq_remove(pq, 5);
    print_queue(pq->front);
    prioq_remove(pq, 3);
    print_queue(pq->front);
    prioq_remove(pq, 1);
    print_queue(pq->front);
    prioq_insert(pq, 102);
    prioq_insert(pq, 103);
    prioq_insert(pq, 1999);
    prioq_insert(pq, 105);
    print_queue(pq->front);
    prioq_remove(pq, 30);
    prioq_insert(pq, 30);
    prioq_remove(pq, 103);
    prioq_remove(pq, 105);
    print_queue(pq->front);
    prioq_insert(pq, 2000);
    print_queue(pq->front);
#endif
    prioq_delete(pq);

    return EXIT_SUCCESS;
}
#if 0
NodePtr remove_node(NodePtr *head, NodePtr target) {

    if (*head == target) {
        *head = (*head)->next;
    } else {
        while ((*head)->next != target) {
            *head = (*head)->next;  
        }
        (*head)->next = target->next;
    }
    target->next = NULL;
    return target;
}

NodePtr append_node(NodePtr head, NodePtr node) {

    NodePtr temp = head;

    if (!head) {
        head = node;
    } else {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = node; 
    }
    return head;
}

NodePtr merge_list(NodePtr list1, NodePtr list2) {

    NodePtr result = NULL, temp = NULL;

    if (list1 == list2) {
        list2 = NULL;
    }

    while (list1 && list2) {

        if (list1->val <= list2->val) {
            temp = remove_node(&list1, list1);
            result = append_node(result, temp);
        } else {
            temp = remove_node(&list2, list2);
            result = append_node(result, temp);
        }
    }

    while (list1) {
        result = append_node(result, remove_node(&list1, list1));
    }

    while (list2) {
        result = append_node(result, remove_node(&list2, list2));
    }
    return result;
}

void merge(NodePtr *result, NodePtr *lists, int head, int min, int end, int *table) {

    NodePtr l1 = NULL;
    NodePtr l2 = NULL;
    NodePtr node = *result, last = NULL, temp = NULL;

    for (int i = head; i <= min; i++) {
        if (!table[i]) {
            l1 = merge_list(l1, lists[i]);
            table[i] = 1;
        }
    }

    for (int i = min+1; i <= end; i++) {
        if (!table[i]) {
            l2 = merge_list(l2, lists[i]);
            table[i] = 1;
        }
    }

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            temp = remove_node(&l1, l1);         
        } else {
            temp = remove_node(&l2, l2);         
        }
        *result = append_node(*result, temp);
    }

    while (l2) {
        *result = merge_list(*result, l2);
    }
    return;
}

void split_merge(NodePtr *result, NodePtr *lists, int head, int end, int *table) {

    int mid = (head+end)/2;

    if (head < end) {
        split_merge(result, lists, head, mid, table);
        split_merge(result, lists, mid+1, end, table);
        merge(result, lists, head, mid, end, table);
    }    
    return; 
}
#endif

#define MAX_NODES 500001

NodePtr remove_front(NodePtr *head) {

    NodePtr node = NULL;

    if (*head) {
        node = (*head);
        (*head) = node->next;
        node->next = NULL;
    }
    return node;
}

void arrange_elements(NodePtr *arr, int size) {

    NodePtr node = NULL;

    for (int i = size - 1; i > 0; i--) {
        if (arr[i-1]->val > arr[i]->val) {
            node = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = node;
        } else {
            break;
        }
    }
    return;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    NodePtr sort_list[MAX_NODES] = {NULL};
    NodePtr node = NULL;
    NodePtr result = NULL;
    int index = 0, loop = true;

    while (loop) {
        for (int i = 0; i < listsSize; i++) {
           if (lists[i]) {
               node = remove_front(&lists[i]);
               sort_list[index++] = node;
               loop = false;
           }
           arrange_elements(sort_list, index);
        }
        loop = !loop;
    }

    for (int i = 0; i < (index-1); i++) {
        if (!result) {
            node = result = sort_list[i];
        } else {
            node->next = sort_list[i];
            node = node->next;
        }
    }
    return result;
}
