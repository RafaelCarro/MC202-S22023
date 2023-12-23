#ifndef PART
#define PART
typedef struct part *p_part;

//Struct para armazenar os tempos de classificação e empacotamento das peças
struct part {
    int class_time;
    int pack_time;
};

void get_input(p_part p);
#endif