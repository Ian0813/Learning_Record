/*
 * =====================================================================================
 *
 *       Filename:  1357_apply_discount_every_n_orders.c
 *
 *    Description:  apply discount every n orders
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

typedef struct {
    int customer_number;
    int *products;
    int *prices;
    int productsSize;
    int pricesSize;
    int discount;
    int discount_time;
} Cashier;

typedef void func(int *v1, int *v2);

static void swap(int *v1, int *v2) {
    int temp = *v1;

    *v1 = *v2;
    *v2 = temp; 
    return;
}

static void quick_sort(int *arr, int head, int end, int *extra) {

    int last = head, tail = end; 
    func *f = swap;

    if (head < end) {

        while (last < tail) {

            if (arr[head] > arr[tail]) {
                last++;    
                (*f)(&arr[last], &arr[tail]);

                if (extra)
                    f(&extra[last], &extra[tail]); 
                continue;
            }
            tail--;
        }

        (*f)(&arr[head], &arr[last]);
        if (extra)
            f(&extra[head], &extra[last]);
        quick_sort(arr, head, last-1, extra);
        quick_sort(arr, last+1, end, extra);
    }

    return;
}

static int binary_search(int *arr, int start, int end, int key) {

    int middle = (start+end) / 2;
    int index = -1;

    if (start < end) {
        if (arr[middle] == key) {
            index = middle;    
        } else if (arr[middle] > key) {
            index = binary_search(arr, start, middle, key);
        } else {
            index = binary_search(arr, middle+1, end, key);
        }
    }

    return index;
}


Cashier* cashierCreate(int n, int discount, int* products, int productsSize, int* prices, int pricesSize) {

    Cashier *obj = NULL;    

    obj = (Cashier *) malloc(sizeof(*obj));

    if (!obj)
        return obj;

    quick_sort(products, 0, productsSize-1, prices);

    obj->products = products;
    obj->productsSize = productsSize;
    obj->prices = prices;
    obj->pricesSize = pricesSize;
    obj->customer_number = 0;
    obj->discount_time = n;
    obj->discount = discount;

    return obj;
}

double cashierGetBill(Cashier* obj, int* product, int productSize, int* amount, int amountSize) {

    double value = 0.0;
    int index = 0;

    if (obj) {

        obj->customer_number++;

        for (int i = 0; i < productSize; i++) {
            index = binary_search(obj->products, 0, obj->productsSize, product[i]);
            value += (obj->prices[index] * amount[i] * 1.0);
        }

        if (!(obj->customer_number % obj->discount_time)) {
            value *= ((100 - obj->discount) / 100.0);
        }
    }

    return value;
}

void cashierFree(Cashier* obj) {

    if (obj)
        free(obj);
    return;
}

/**
 * Your Cashier struct will be instantiated and called as such:
 * Cashier* obj = cashierCreate(n, discount, products, productsSize, prices, pricesSize);
 * double param_1 = cashierGetBill(obj, product, productSize, amount, amountSize);

 * cashierFree(obj);
*/
