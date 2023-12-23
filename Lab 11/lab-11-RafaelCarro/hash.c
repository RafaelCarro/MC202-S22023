#include "hash.h"
#include <stdlib.h>
#include <string.h>

/*Generates a hash using a string as key by the method
of multiplication.*/
int hash(char *key) {
    int i, n = 0;
    for (i = 0; i < strlen(key); i++)
        n = (256*n + key[i]) % MAX;
    return n;
}

/*Frees the hash table.*/
void free_hash(p_hash h) {
    for (int i = 0; i < MAX; i++) {
        if (h->v[i] != NULL)
            free(h->v[i]);
    }
    free(h);
}

/*Create a hash of MAX size.*/
p_hash create_hash() {
    p_hash h = malloc(sizeof(struct hash));
    for (int i = 0; i < MAX; i++) {
        h->v[i] = NULL;
    }
    return h;
}

/*Inserts an element into the hash. If there are two elements
with the same hash, moves the hash up untill a space is avaliable.*/
void insert(p_hash h, p_family f) {
    int key = hash(f->name);
    while (h->v[key] != NULL && h->v[key]->removed == 0)
        key = (key + 1) % MAX;
    h->v[key] = f;
}

/*Searches for a string in the hash table.*/
int search(p_hash h, char *key) {
    int s_key = hash(key);
    while (strcmp(h->v[s_key]->name, key) != 0) {
        if (h->v[s_key] == NULL) {
            return -1;
        }
        s_key = (s_key + 1) % MAX;
    }
    if (h->v[s_key]->removed == 1)
        return -1;
    return s_key;
}

/*Deletes a hash from the table.*/
void delete(p_hash h, char *key) {
    int p = search(h, key);
    if (p != -1)
        h->v[p]->removed = 1;
}