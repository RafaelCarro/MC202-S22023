#include "part.h"

typedef struct queue *p_queue;

//Estrutura para uma fila feita com um vetor circular de struct part.
struct queue {
    p_part *v;
    int ini, end, N, size;
};

p_queue criar_fila(int N);

void destruir_fila(p_queue fila);

void enfileira(p_queue fila, p_part p);

void desenfileira(p_queue fila);