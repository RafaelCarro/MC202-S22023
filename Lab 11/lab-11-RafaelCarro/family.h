typedef struct family *p_family;

/*Struct to hold a family information:
    -name: Family Name
    -candy: How many candy they have at the moment.
    -removed: Auxiliary data for the hash table.*/
struct family {
    char name[11];
    int candy;
    int removed;
};

p_family create_family(char *name, int candy);