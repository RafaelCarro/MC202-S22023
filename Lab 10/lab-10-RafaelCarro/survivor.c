#include "survivor.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

p_sur add_survivor() {
    char name[31], first_name[16], surname[16];
    p_sur survivor = malloc(sizeof(struct survivor));
    scanf("%s %s", first_name, surname);
    for (int i = 0; first_name[i] != '\0'; i++)
        name[i] = first_name[i];
    int j = strlen(first_name);
    name[j] = ' ';
    j++;
    for (int i = 0; surname[i] != '\0'; i++) {
        name[j] = surname[i];
        j++;
    }
    name[j] = '\0';
    strcpy(survivor->name, name);
    int x;
    scanf("%d", &x);
    survivor->days = x;
    return survivor;
}