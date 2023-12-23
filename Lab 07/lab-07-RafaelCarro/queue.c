#include <stdlib.h>
#include "queue.h"

/*Cria uma fila de tamanho n num vetor circular.*/
p_queue criar_fila(int N) {
    p_queue f;
    f = malloc(sizeof(struct queue));
    f->v = malloc(N*sizeof(int *));
    f->ini = 0;
    f->end = 0;
    f->N = N;
    f->size = 0;
    return f;
}

/*Destroi a fila.*/
void destruir_fila(p_queue fila) {
    free(fila->v);
    free(fila);
}

/*Adiciona uma parte a fila.*/
void enfileira(p_queue fila, p_part p) {
    fila->v[fila->end] = p;
    fila->end  = (fila->end + 1) % fila->N;
    fila->size++;
}

/*Remove uma parte da fila.*/
void desenfileira(p_queue fila) {
    free(fila->v[fila->ini]);
    fila->ini = (fila->ini + 1) % fila->N;
    fila->size--;
}
