#include "family.h"
#include <stdlib.h>
#include <string.h>

/*Creates a family struct.*/
p_family create_family(char *name, int candy) {
    p_family f = malloc(sizeof(struct family));
    strcpy(f->name, name);
    f->candy = candy;
    f->removed = 0;
    return f;
}