#include <stdlib.h>
#include <stdio.h>
#include "vetor.h"

/*Initializes a standard vector with size of 8 integers.*/
p_vector bat_init() {
    p_vector v;
    v = malloc(sizeof(struct vector));
    v->nums = malloc(8*sizeof(int));
    v->it = 0;
    v->size = 8;
    for (int i = 0; i < v->size; i++)
        v->nums[i] = 0;
    return v;
}

/*Gets the position of the first empty space on the memory that
has the size to hold an arbitrary number of integers.*/
int get_it(p_vector v, int size_of_memory) {
    for (int i = 0; i < v->size; i++) {
        int space = 0;
        while (v->nums[i] == 0 && i < v->size) {
            space++;
            if (space >= size_of_memory + 1)
                return i - size_of_memory;
            i++;
        }
    }
    return -1;
}


/*Allocates a given number of integers in the memory. If more
size is needed to allocate all the integers, the function doubles
the size of the structure untill it is able to hold all. The first
memory adress is used to store the size of the given vector.*/
void bat_alloc(p_vector v) {
    int *temp, size;
    scanf("%d", &size);
    int pos = get_it(v, size);
    while (pos == -1) {
        temp = v->nums;
        v->size *= 2;
        v->nums = malloc(v->size*sizeof(int*));
        for (int j = v->size/2; j <= v->size; j++)
            v->nums[j] = 0;
        for (int j = 0; j < v->size/2; j++)
            v->nums[j] = temp[j];
        free(temp);
        pos = get_it(v, size);
    }
    v->it = pos;
    v->nums[v->it] = size;
    printf("%d\n", v->it);
    v->it++;
    for(int i = 0;i < size; i++) {
        scanf("%d", &v->nums[v->it]);
        v->it++;
    }
}

/*Frees the given vector from memory. It gets the vector size
adress and cleans the memory from there. If after the operarion
only the first quarter has allocated memory, it resizes the
structure to half its size.*/
void bat_free(p_vector v) {
    int adress;
    scanf("%d", &adress);
    int n_free = v->nums[adress];
    for (int i = adress; i < adress + 1 + n_free; i++) {
        v->nums[i] = 0;
    }
    int pos = v->size/4;
    int free_flag = 1;
    while (pos < v->size) {
        if (v->nums[pos] != 0) {
            free_flag = 0;
            break;
        }
        pos++;
    }
    if (free_flag == 1) {
        int *temp;
        temp = v->nums;
        v->size /= 2;
        v->nums = malloc(v->size*sizeof(int));
        for (int j = 0; j < v->size; j++)
            v->nums[j] = temp[j];
        free(temp);
    }
}


/*Prints the stored vector of the given memory adress.*/
void bat_print(p_vector v) {
    int adress;
    scanf("%d", &adress);
    for (int i = adress + 1; i <= adress + v->nums[adress]; i++)
        printf("%d ", v->nums[i]);
    printf("\n");
}

/*Prints the current memory usage against the total avaliable.*/
void bat_uso(p_vector v) {
    int usage = 0;
    for (int i = 0; i < v->size; i++)
        if (v->nums[i] != 0)
            usage++;
    printf("%d de %d\n", usage, v->size);
}