#include <string.h>
#include <stdio.h>
#include "part.h"


/*Função que adquire as informações das peças no stdin e as transforma
nos valores númericos a serem guardados por um ponteiro de struct.*/
void get_input(p_part p) {
    char size[10];
    int type;
    scanf("%s %d", size, &type);
    if (strcmp(size, "pequena") == 0) {
        p->class_time = 1;
        if (type == 1)
            p->pack_time = 1;
        else
            p->pack_time = 2;
    }
    else if (strcmp(size, "media") == 0) {
        p->class_time = 2;
        if (type == 1)
            p->pack_time = 2;
        else
            p->pack_time = 3;
    }
    else if (strcmp(size, "grande") == 0) {
        p->class_time = 3;
        if (type == 1)
            p->pack_time = 2;
        else
            p->pack_time = 3;
    }
}