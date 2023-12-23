#include "dish.h"

typedef struct FP *p_fp;

//Priority List struct, uses a vector to hold information.
struct FP {
    p_dish *v;
    int n, size; // n -> number of elements
};

void change(p_dish *a, p_dish *b);

void up(p_fp p_list, int k);

void down(p_fp p_list, int k);

p_fp create_p_list(int size);

void insert (p_fp p_list, p_dish dish);

p_dish extract_max(p_fp p_list);

int find_pos(p_fp p_list, int ID);

void change_key(p_fp p_list, int k, int value);

void free_pl(p_fp p_list);