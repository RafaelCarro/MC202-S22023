#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

int main() {
    int n_partidas;
    scanf("%d", &n_partidas);
    //for loop for N matches
    for (int i = 0; i < n_partidas; i++) {
        int n_players, n_circuits, n_equipments;
        scanf("%d %d %d", &n_players, &n_circuits, &n_equipments);
        //dynamic allocated vector for a list of circuits
        circuito *p_circuits;
        p_circuits = malloc(n_circuits*sizeof(circuito));
        //calcualtion the rent
        float rent = 10*n_circuits + 17.5*n_equipments;
        //loop to get all the circuits
        for (int j = 0; j < n_circuits; j++) {
            int id;
            scanf("%d", &id);
            p_circuits[j] = novo_circuito(id, n_players);
        }
        //creating the match
        partida p = nova_partida(rent, i + 1, n_players, n_circuits, n_equipments, p_circuits);
        print_partida(p);
        //freeing the memory
        for (int i = 0; i < n_circuits; i++)
            free(p_circuits[i].n_plays);
        free(p_circuits);
    }
}