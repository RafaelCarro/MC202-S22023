#include "linked_list.h"

typedef struct stack *p_stack;

/*stack struct.*/
struct stack {
    p_node top;
    int size;
};

p_stack create_stack();

void destroy_stack(p_stack stack);

void stack(p_stack stack, int v);

int unstack(p_stack stack);