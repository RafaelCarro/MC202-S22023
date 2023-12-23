#include "priority_list.h"
#include <stdlib.h>

//defining structure of the heap for the priority list
#define ROOT(i) ((i-1)/2)
#define L_BRANCH(i) (2*i+1)
#define R_BRANCH(i) (2*i+2)

/*Switches a to b.*/
void change(p_dish *a, p_dish *b) {
    p_dish t = *a;
    *a = *b;
    *b = t;
}

/*Corrects the heap going upwards by switching any necessary nodes.
Starts on the k'th element.*/
void up(p_fp p_list, int k) {
    if (k > 0 && p_list->v[ROOT(k)]->key < p_list->v[k]->key) {
        change(&p_list->v[k], &p_list->v[ROOT(k)]);
        up(p_list, ROOT(k));
    }
}

/*Corrects the heap going downwards by switching any necessary nodes.
Starts on the k'th element.*/
void down(p_fp p_list, int k) {
    int max_branch;
    if (L_BRANCH(k) < p_list->n) {
        max_branch = L_BRANCH(k);
        if (R_BRANCH(k) < p_list->n && p_list->v[L_BRANCH(k)]->key < p_list->v[R_BRANCH(k)]->key)
            max_branch = R_BRANCH(k);
        if (p_list->v[k]->key < p_list->v[max_branch]->key) {
            change(&p_list->v[k], &p_list->v[max_branch]);
            down(p_list, max_branch);
        }
    }    
}

/*Creates a priority list of dish of the desired size.*/
p_fp create_p_list(int size) {
    p_fp p_list = malloc(sizeof(struct FP));
    p_list->v = malloc(size*sizeof(struct dish));
    p_list->n = 0;
    p_list->size = size;
    return p_list;
}

/*Inserts a dish in the heap of the priority list.*/
void insert (p_fp p_list, p_dish dish) {
    p_list->v[p_list->n] = dish;
    p_list->n++;
    up(p_list, p_list->n - 1);
}

/*Extracts the dish with the survivor with the greatest key.*/
p_dish extract_max(p_fp p_list) {
    p_dish dish = p_list->v[0];
    change(&p_list->v[0], &p_list->v[p_list->n - 1]);
    p_list->n--;
    down(p_list, 0);
    return dish;
}

/*Find the pos in the heap of the dish with the ID.*/
int find_pos(p_fp p_list, int ID) {
    for (int i = 0; i < p_list->n; i++) {
        if (p_list->v[i]->id == ID)
            return i;
    }
    return -1;
}

/*Changes the key of dish on the kth position on the heap.
The value to change can be negative or positive.*/
void change_key(p_fp p_list, int k, int value) {
    p_list->v[k]->key += value;
    if (value > 0)
        up(p_list, k);
    else
        down(p_list, k);
}

/*Frees the priority list.*/
void free_pl(p_fp p_list) {
    for (int i = 0; i < p_list->n; i++)
        free(p_list->v[i]);
    free(p_list->v);
    free(p_list);
}
