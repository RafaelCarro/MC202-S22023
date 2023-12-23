#include "stack.h"

#define MAX 21

typedef struct graph *p_graph;

/*Linked list graph representation struct.*/
struct graph {
    p_node *adjacent;
    int *exist_node;
    int n;
};

p_graph create_graph();

void destroy_graph(p_graph g);

void insert_node(p_graph g, int u);

void insert_connection(p_graph g, int u, int v);

void remove_connection(p_graph g, int u, int v);

int check_connection(p_graph g, int u, int v);

int * DFS(p_graph g, int v);

int * BFS(p_graph g, int v);