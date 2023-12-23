#include <string.h>
#include <stdio.h>
#include "linked_list.h"

int main() {
    char action[20], book[MAX_LENGHT];
    p_node books;
    books = create_list();
    while(scanf("%s", action) == 1) {
        if (strcmp(action, "adicionar") == 0) {
            fgets(book, MAX_LENGHT, stdin);
            book[strlen(book) - 1] = '\0';
            books = add_book(books, book);
        }
        if (strcmp(action, "remover") == 0) {
            fgets(book, MAX_LENGHT, stdin);
            book[strlen(book) - 1] = '\0';
            books = remove_book(books, book);
        }
        else if (strcmp(action, "imprimir") == 0) {
            print_books(books);
        }
        else if (strcmp(action, "inicio") == 0) {
            last_node = NULL;
        }
        else if (strcmp(action, "final") == 0) {
            last_node = get_last(books);
        }
    }
    destroy_list(books);
}