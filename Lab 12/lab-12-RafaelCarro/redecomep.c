#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    p_graph network = create_graph();
    int action;
    scanf("%d", &action);
    while (action > 0 && action < 7) {
        if (action == 1) {
            int u;
            scanf("%d", &u);
            insert_node(network, u);
        }
        else if (action == 2) {
            int u, v;
            scanf("%d %d", &u, &v);
            insert_connection(network, u, v);
        }
        else if (action == 3) {
            int u, v;
            scanf("%d %d", &u, &v);
            remove_connection(network, u, v);
        }
        else if (action == 4) {
            int u, v;
            scanf("%d %d", &u, &v);
            int *roots;
            roots = DFS(network, u);
            if (roots[u] == roots[v])
                printf("Existe conexão entre os nós.\n");
            else
                printf("Não existe conexão entre os nós.\n");
            free(roots);
        }
        else if (action == 5) {
            int u, v;
            scanf("%d %d", &u, &v);
            int *roots;
            roots = BFS(network, v);
            int p = u;
            if (roots[p] != -1) {
                printf("%d ->", p);
                while (p != v) {
                    p = roots[p];
                    if (p == v)
                    printf(" %d\n", p);
                    else
                    printf(" %d ->", p);
                }
                free(roots);
            }
            else
                printf("Não existe conexão entre os nós.\n");
        }
        else if (action == 6) {
            for (int i = 1; i < network->n; i++) {
                if (network->exist_node[i] != 0) {
                    int *roots;
                    printf("Ponto %d (Pontos diretamente ou indiretamente conectados): ", i);
                    roots = DFS(network, i);
                    for (int j = 1; j < network->n; j++) {
                        if (roots[j] == i)
                            printf("%d ", j);
                    }
                    printf("\n");
                    free(roots);
                }
            }
        }
        scanf("%d\n", &action);
    }
    destroy_graph(network);
}