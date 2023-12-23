#include <stdlib.h>
#include "stack.h"

/*Creates a stack of size 0.*/
p_stack create_stack() {
    p_stack new = malloc(sizeof(struct stack));
    new->top = NULL;
    new->size = 0;
    return new;
}

/*Destroy stack recursively.*/
void destroy_stack(p_stack stack) {
    free_list(stack->top);
    free(stack);
}

/*Inserts a new item on the top of the stack.*/
void stack(p_stack stack, int v) {
    p_node new = malloc(sizeof(struct node));
    new->v = v;
    new->next = stack->top;
    stack->top = new;
    stack->size++;
}

/*Removes an item from the top of the stack.*/
int unstack(p_stack stack) {
    p_node s = stack->top;
    int r = s->v; 
    stack->top = stack->top->next;
    free(s);
    stack->size--;
    return r;
}
