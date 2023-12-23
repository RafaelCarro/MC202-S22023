typedef struct node *p_node;

//Node of a linked list
struct node {
    int v;
    p_node next;
};

void free_list(p_node list);

p_node insert_on_list(p_node list, int v);

p_node remove_on_list(p_node list, int v);