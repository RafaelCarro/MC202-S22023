#include "linked_list.h"
#include <stdlib.h>

/*Frees the linked list recursively.*/
void free_list(p_node list) {
    if (list != NULL) {
        free_list(list->next);
        free(list);
    }
}

/*Inserts a new node on a linked list.*/
p_node insert_on_list(p_node list, int v) {
    p_node new = malloc(sizeof(struct node));
    new->v = v;
    new->next = list;
    return new;
}

/*Removes a node from a linked list.*/
p_node remove_on_list(p_node list, int v) {
    p_node next;
    if (list == NULL)
        return NULL;
    else if (list->v == v) {
        next = list->next;
        free(list);
        return next;
    }
    else {
        list->next = remove_on_list(list->next, v);
        return list;
    }
}