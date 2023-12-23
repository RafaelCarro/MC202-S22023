#include <stdlib.h>
#include <string.h>
#include "symbol.h"


/*Creates a struct that stores a symbol with its correspondent type.*/
p_symbol create_symbol(char *symbol, char *type) {
    p_symbol x = malloc(sizeof(struct symbol));
    strcpy(x->symbol, symbol);
    strcpy(x->type, type);
    return x;
}