typedef struct queue *p_queue;

/*queue struct*/
struct queue {
    int *v;
    int ini, end, N, size;
};

p_queue create_queue(int N);

void destroy_queue(p_queue fila);

void queue(p_queue fila, int p);

int unqueue(p_queue fila);