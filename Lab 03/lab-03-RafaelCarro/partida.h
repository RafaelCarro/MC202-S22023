#include "circuito.h"

typedef struct {
    float rent;
    int id;
    int n_players;
    int n_circuits;
    int n_equipment;
    circuito *circuitos;
} partida;

partida nova_partida(float rent, int id, int n_players, int n_circuits, int n_equipment, circuito *circuits);

void print_partida(partida p);

int get_points(partida p, int player);