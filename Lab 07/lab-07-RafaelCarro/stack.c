#include <stdlib.h>
#include "stack.h"

/*Cria uma pilha com tamanho inicial 0.*/
p_stack criar_pilha(int N) {
    p_stack new = malloc(sizeof(struct stack));
    new->top = NULL;
    new->size = 0;
    return new;
}

/*Destroi a lista ligada que a pilha aponta recursivamente.*/
void destruir_lista(p_node list) {
    if (list != NULL) {
        destruir_lista(list->prox);
        free(list);
    }
}

/*Destroi a pilha.*/
void destruir_pilha(p_stack stack) {
    destruir_lista(stack->top);
    free(stack);
}

/*Empilha uma parte na pilha e aumenta seu tamanho em 1.*/
void empilhar(p_stack stack, p_part p) {
    p_node new = malloc(sizeof(struct node));
    new->p = p;
    new->prox = stack->top;
    stack->top = new;
    stack->size++;
}

/*Desempilha uma parte da pilha e reduz seu tamanho em 1.*/
void desempilhar(p_stack stack) {
    p_node s = stack->top;
    stack->top = stack->top->prox;
    free(s);
    stack->size--;
}
