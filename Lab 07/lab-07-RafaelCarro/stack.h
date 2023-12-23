#include "part.h"

typedef struct stack *p_stack;
typedef struct node *p_node;

//Estrutura de uma pilha feita com lista ligada, armazena struct part.
struct stack {
    p_node top;
    int size;
};

//Nó da lista ligada.
struct node {
    p_part p;
    p_node prox;
};

p_stack criar_pilha(int N);

void destruir_lista(p_node node);

void destruir_pilha(p_stack stack);

void empilhar(p_stack stack, p_part p);

void desempilhar(p_stack stack);