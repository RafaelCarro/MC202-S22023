typedef struct symbol *p_symbol;
#define MAX 201

struct symbol {
    char symbol[MAX];
    char type[10];
};

p_symbol create_symbol(char *symbol, char *type);