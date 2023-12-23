typedef struct vector *p_vector;

struct vector {
    int *nums;
    int it;
    int size;
};

p_vector bat_init();

int get_it(p_vector v, int size_of_memory);

void bat_alloc(p_vector v);

void bat_free(p_vector v);

void bat_print(p_vector v);

void bat_uso(p_vector v);