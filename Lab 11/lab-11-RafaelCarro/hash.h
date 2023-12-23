#include "family.h"

#define MAX 2999

typedef struct hash *p_hash;

//Struct to hold the hash table.
struct hash {
    p_family v[MAX];
};

void free_hash(p_hash h);

int hash(char *key);

p_hash create_hash();

void insert(p_hash h, p_family f);

int search(p_hash h, char *key);

void delete(p_hash h, char *key);