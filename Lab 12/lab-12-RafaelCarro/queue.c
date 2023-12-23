#include <stdlib.h>
#include "queue.h"

/*Creates a queue of size 0.*/
p_queue create_queue(int N) {
    p_queue f;
    f = malloc(sizeof(struct queue));
    f->v = malloc(N*sizeof(int *));
    f->ini = 0;
    f->end = 0;
    f->N = N;
    f->size = 0;
    return f;
}

/*Frees the queue.*/
void destroy_queue(p_queue fila) {
    free(fila->v);
    free(fila);
}

/*Inserts a new item at the end of the queue.*/
void queue(p_queue fila, int p) {
    fila->v[fila->end] = p;
    fila->end  = (fila->end + 1) % fila->N;
    fila->size++;
}

/*Removes an item from the start of the queue.*/
int unqueue(p_queue fila) {
    int r = fila->v[fila->ini];
    fila->ini = (fila->ini + 1) % fila->N;
    fila->size--;
    return r;
}
