#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "balanced_tree.h"
#define MAX 201

//AUXILIARY FUNCTIONS

/*Functions that search for a char in a string,
if it's present, returns 1, otherwise returns -1.*/
int find(char *arr, char obj) {
    int i = 0;
    while (arr[i] != '\0') {
        if (arr[i] == obj)
            return 1;
        i++;
    }
    return -1;
}

/*Function that gets an unfformated string and them
removes any leading whitespace from it.*/
void remove_leading_whitespace(char *string) {
    int size = strlen(string);
    char copy[MAX];
    memset(copy, 0, MAX);
    int i = 0;
    while (string[i] == ' ')
        i++;
    int j = 0;
    while (i < size) {
        copy[j] = string[i];
        i++; j++;
    }
    strcpy(string, copy);
}

int main() {
    char buffer[MAX];
    memset(buffer, 0, MAX);
    char symbols[MAX];
    memset(symbols, 0, MAX);
    int count = 1, error = 0;
    p_node symbols_tree = NULL;
    while (fgets(buffer, MAX, stdin) != NULL) {
        //removes tabs from the line.
        remove_leading_whitespace(buffer);
        //Checks if the line is acceptable for the analysis.
        if (find(buffer, '(') == -1) {
            //Variable Declaration
            if ((buffer[0] >= 'a' && buffer[0] <= 'z') || (buffer[0] >= 'A' && buffer[0] <= 'Z')) {
                sscanf(buffer, "%s", symbols);
                //Checks for the variable type.
                if (strcmp(symbols, "return") == 0)
                    ;
                else if (strcmp(symbols, "int") == 0){
                    sscanf(buffer + 3, "%s", symbols);
                    symbols[strlen(symbols) - 1] = '\0';
                    p_symbol s = create_symbol(symbols, "int");
                    symbols_tree = insert(symbols_tree, s);
                }
                else if (strcmp(symbols, "char") == 0) {
                    sscanf(buffer + 4, "%s", symbols);
                    symbols[strlen(symbols) - 1] = '\0';
                    p_symbol s = create_symbol(symbols, "char");
                    symbols_tree = insert(symbols_tree, s);
                }
                else if (strcmp(symbols, "double") == 0) {
                    sscanf(buffer + 6, "%s", symbols);
                    symbols[strlen(symbols) - 1] = '\0';
                    p_symbol s = create_symbol(symbols, "double");
                    symbols_tree = insert(symbols_tree, s);
                }
                //Operation Declaration
                else {
                    p_node s1, s2, s3;
                    s1 = search_tree(symbols_tree, symbols);
                    if (s1 != NULL) {
                        int x = strlen(symbols);
                        sscanf(buffer + x + 3, "%s", symbols);
                        s2 = search_tree(symbols_tree, symbols);
                        if (s2 != NULL) {
                            int y = strlen(symbols);
                            sscanf(buffer + x + 6 + y, "%s", symbols);
                            symbols[strlen(symbols) - 1] = '\0';
                            s3 = search_tree(symbols_tree, symbols);
                            if (s3 != NULL) {
                                if (strcmp(s2->symbol->type, s3->symbol->type) == 0) {
                                    if (strcmp(s2->symbol->type, s1->symbol->type) != 0) {
                                        printf("Linha %d: tipos incompatíveis: o símbolo %s espera %s, obteve %s.\n",count,s1->symbol->symbol,s1->symbol->type,s2->symbol->type);
                                        error++;
                                    }
                                }
                                else {
                                    sscanf(buffer + x + y + 3, "%s", symbols);
                                    printf("Linha %d: tipos incompatíveis: %s (%s) %s %s (%s).\n", count,s2->symbol->symbol,s2->symbol->type,symbols,s3->symbol->symbol,s3->symbol->type);
                                    error++;
                                }
                            }
                            else {
                                printf("Linha %d: o símbolo %s não foi definido.\n", count, symbols);
                                error++;
                            }
                        }
                        else {
                            printf("Linha %d: o símbolo %s não foi definido.\n", count, symbols);
                            error++;
                        }
                    }
                    else {
                        printf("Linha %d: o símbolo %s não foi definido.\n", count, symbols);
                        error++;
                    }
                }
            }
        }
        count++;
        memset(symbols, 0, MAX);
        memset(buffer, 0, MAX);
    }
    if (error == 0)
        printf("Não há erros de tipo.\n");
    inorder(symbols_tree);
    free_tree(symbols_tree);
}