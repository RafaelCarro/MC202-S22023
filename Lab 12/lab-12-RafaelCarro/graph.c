#include "graph.h"
#include "queue.h"
#include <stdlib.h>

/*Creates a new graph of size MAX. Uses linked lists.*/
p_graph create_graph() {
    p_graph g = malloc(sizeof(struct graph));
    g->n = MAX;
    g->adjacent = malloc(MAX*sizeof(p_node));
    g->exist_node = malloc(MAX*sizeof(int));
    for (int i = 0; i < MAX; i++) {
        g->adjacent[i] = NULL;
        g->exist_node[i] = 0;
    }
    return g;
}

/*Frees the graph iteractively.*/
void destroy_graph(p_graph g) {
    for (int i = 0; i < g->n; i++) {
        free_list(g->adjacent[i]);
    }
    free(g->exist_node);
    free(g->adjacent);
    free(g);
}

/*Inserts a node in the graph.*/
void insert_node(p_graph g, int u) {
    g->exist_node[u] = 1;
}

/*Connects two nodes of the graph.*/
void insert_connection(p_graph g, int u, int v) {
    g->adjacent[v] = insert_on_list(g->adjacent[v], u);
    g->adjacent[u] = insert_on_list(g->adjacent[u], v);
}

/*Removes the connection between two nodes.*/
void remove_connection(p_graph g, int u, int v) {
    g->adjacent[v] = remove_on_list(g->adjacent[v], u);
    g->adjacent[u] = remove_on_list(g->adjacent[u], v);
}

/*Checks if two nodes have a direct connection between them.*/
int check_connection(p_graph g, int u, int v) {
    p_node t;
    for (t = g->adjacent[u]; t != NULL; t = t->next)
        if (t->v == v)
            return 1;
    return 0;
}

/*Depht First Search. Finds all the nodes connected to the root.*/
int * DFS(p_graph g, int v) {
    int *root = malloc(g->n*sizeof(int));
    int *checked = malloc(g->n*sizeof(int));
    p_stack p = create_stack();
    for (int i = 0; i < g->n; i++) {
        root[i] = -1;
        checked[i] = 0;
    }
    stack(p, v);
    root[v] = v;
    while(p->size != 0) {
        int i = unstack(p);
        if (checked[i])
            continue;
        checked[i] = 1;
        for (int j = 0; j < g->n; j++) {
            if (check_connection(g, i, j) && !checked[j]) {
                root[j] = v;
                stack(p, j);
            }
        }
    }
    destroy_stack(p);
    free(checked);
    return root;
}

/*Breath First Search. Finds the paths of all the nodes connected to the root.*/
int * BFS(p_graph g, int v) {
    int *root = malloc(g->n*sizeof(int));
    int *checked = malloc(g->n*sizeof(int));
    p_queue q = create_queue(g->n);
    for (int i = 0; i < g->n; i++) {
        root[i] = -1;
        checked[i] = 0;
    }
    queue(q, v);
    root[v] = v;
    checked[v] = 1;
    while (q->size != 0) {
        int i = unqueue(q);
        for (int j = 0; j < g->n; j++) {
            if (check_connection(g, i, j) && !checked[j]) {
                checked[j] = 1;
                root[j] = i;
                queue(q, j);
            }
        }
    }
    destroy_queue(q);
    free(checked);
    return root;
}