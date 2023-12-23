#ifndef DISH
#define DISH

typedef struct dish *p_dish;

//Struct that holds information about a dish
//id-> ID of the survivor that requested the dish
//dish-> Name of the dish
//key-> Number of days survived, wich servers as key for the heap
struct dish {
    int id;
    char dish[26];
    int key;
};

p_dish create_dish(int ID, int key, char *dish_name);

#endif