#include "dish.h"
#include <stdlib.h>
#include <string.h>

/*Creates a dish with the choosen name and desired int key.*/
p_dish create_dish(int ID, int key, char *dish_name) {
    p_dish dish = malloc(sizeof(struct dish));
    dish->id = ID;
    dish->key = key;
    strcpy(dish->dish, dish_name);
    return dish;
}