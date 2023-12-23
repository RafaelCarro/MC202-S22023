#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

/*Function that returns a new struct of a match using 6 parameters, the rent const, the id of the match,
the number of players, the number of circuits, the number of rented equipment and a vector of circuits.*/
partida nova_partida(float rent, int id, int n_players, int n_circuits, int n_equipment, circuito *circuits) {
    partida p;
    p.rent = rent;
    p.id = id;
    p.n_players = n_players;
    p.n_circuits = n_circuits;
    p.n_equipment = n_equipment;
    p.circuitos = circuits;
    return p;
}

/*Function that returns the id of the hardest circuit in a match, the one with the most plays needed to 
get done with it.*/
int get_hardest(partida p) {
    int h_points = 0, h_id;
    for (int i = 0; i < p.n_circuits; i++) {
        if (p.circuitos[i].total_points > h_points) {
            h_points = p.circuitos[i].total_points;
            h_id = p.circuitos[i].id;
        }
    }
    return h_id;
}

/*Function that returns the sum of a circuit points of a player in a match.*/
int get_points(partida p, int player) {
    int sum = 0;
    for (int i = 0; i < p.n_circuits; i++) {
        sum += p.circuitos[i].n_plays[player];
    }
    return sum;
}

/*Function that prints the data of a match.*/
void print_partida(partida p){
    printf("Partida %d\n", p.id);
    printf("Num. de Jogadores: %d - Num. de Circuitos: %d - Num. de Equipamentos: %d\n",
            p.n_players, p.n_circuits, p.n_equipment);
    printf("Valor do Aluguel: R$ %.2f\n", p.rent);
    for (int i = 0; i < p.n_players; i++)
        printf("Jogador %d: %d\n", i + 1, get_points(p, i));
    printf("Circuito mais dificil: %d\n", get_hardest(p));
    printf("##########\n");
}

