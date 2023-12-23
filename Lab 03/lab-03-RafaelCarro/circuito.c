#include <stdio.h>
#include <stdlib.h>
#include "circuito.h"

/*Function that returns a new struct of a circuit using 2 parameters, the circuit ID and the number os players.*/
circuito novo_circuito(int id, int n) {
    circuito c;
    c.id = id;
    c.n_participants = n;
    c.total_points = 0;
    c.n_plays = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &c.n_plays[i]);
        c.total_points += c.n_plays[i];
    }
    return c;
}