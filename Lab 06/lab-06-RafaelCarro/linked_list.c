#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*Global variable that stores the last added book position*/
p_node last_node;

p_node create_list() {
    return NULL;
}


void destroy_list(p_node list) {
    if (list != NULL) {
        destroy_list(list->prox);
        free(list);
    }
}

/*Adds a book in the linked list after the last book added,
or starts a new linked list with the book on it.*/
p_node add_book(p_node list, char book[]) {
    p_node new;
    int size = strlen(book);
    new = malloc(sizeof(struct node));
    memcpy(new->book, book, size + 1);
    if (list == NULL || last_node == NULL) {
        new->prox = list;
        last_node = new;
        return new;
    }
    new->prox = last_node->prox;
    last_node->prox = new;
    last_node = new;
    return list;
}

/*Looks for the given book in the linked list them
deletes it.*/
p_node remove_book(p_node list, char book[]) {
    p_node curr = list, prev;
    if (strcmp(curr->book, book) == 0) {
        curr = list->prox;
        last_node = NULL;
        free(list);
        return curr;
    }
    while (curr != NULL && strcmp(curr->book, book) != 0) {
        prev = curr;
        curr = curr->prox;
    }
    prev->prox = curr->prox;
    if (last_node == curr)
        last_node = prev;
    free(curr);
    return list;
}

/*Prints the linked list of books in the stdout.*/
void print_books(p_node list) {
    p_node current;
    if (list == NULL) {
        return ;
    }
    current = list;
    printf("%s", current->book);
    current = current->prox;
    for (;current != NULL; current = current->prox) {
        printf(",%s", current->book);
    }
    printf("\n");
}

/*Runs throught the linked list to get the pointer
of the last element.*/
p_node get_last(p_node list) {
    p_node last = list;
    if (list == NULL)
        return list;
    while (last->prox != NULL)
        last = last->prox;
    return last;
}