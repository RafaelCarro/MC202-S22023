typedef struct node *p_node;

#define MAX_LENGHT 56

extern p_node last_node;

struct node {
    char book[MAX_LENGHT];
    p_node prox;
};

p_node create_list();

void destroy_list(p_node list);

p_node add_book(p_node list, char book[]);

p_node remove_book(p_node list, char book[]);

void print_books(p_node list);

p_node get_last(p_node list);
