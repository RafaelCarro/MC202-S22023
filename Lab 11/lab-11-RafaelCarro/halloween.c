#include "hash.h"
#include <stdio.h>
#include <string.h>

int main() {
    char action[15];
    p_hash houses = create_hash();
    scanf("%s", action);
    while(strcmp(action, "FINALIZAR") != 0) {
        if (strcmp(action, "ENTRAR") == 0) {
            char name[11];
            int candy;
            scanf("%s %d", name, &candy);
            p_family f = create_family(name, candy);
            insert(houses, f);
        }
        if (strcmp(action, "SAIR") == 0) {
            char name[11];
            scanf("%s", name);
            int pos = search(houses, name);
            printf("A familia %s saiu com %d doce(s) sobrando.\n", name, houses->v[pos]->candy);
            delete(houses, name);
        }
        if (strcmp(action, "COMPRAR") == 0) {
            char name[11];
            int candy;
            scanf("%s %d", name, &candy);
            int pos = search(houses, name);
            houses->v[pos]->candy += candy;
            printf("A familia %s agora possui %d doces.\n", name, houses->v[pos]->candy);
        }
        if (strcmp(action, "TRICKORTREAT") == 0) {
            char first_name[11], surname[11];
            int n_houses;
            int candy = 0;
            scanf("%s %s %d", first_name, surname, &n_houses);
            for (int j = 0; j < n_houses; j++) {
                char name[11];
                char grade[11];
                scanf("%s %s", name, grade);
                int pos = search(houses, name);
                if (strcmp(grade, "Boa") == 0) {
                    if (houses->v[pos]->candy <= 0)
                        ;
                    else if (houses->v[pos]->candy <= 3) {
                        candy += houses->v[pos]->candy;
                        houses->v[pos]->candy = 0;
                        printf("A familia %s ficou sem doces.\n", name);
                    }
                    else {
                        houses->v[pos]->candy -= 3;
                        candy += 3;
                    }
                }
                else if (strcmp(grade, "Media") == 0) {
                    if (houses->v[pos]->candy <= 0)
                        ;
                    else if (houses->v[pos]->candy <= 2) {
                        candy += houses->v[pos]->candy;
                        houses->v[pos]->candy = 0;
                        printf("A familia %s ficou sem doces.\n", name);
                    }
                    else {
                        houses->v[pos]->candy -= 2;
                        candy += 2;
                    }
                }
                else {
                    if (houses->v[pos]->candy <= 0)
                        ;
                    else if (houses->v[pos]->candy <= 1) {
                        candy += houses->v[pos]->candy;
                        houses->v[pos]->candy = 0;
                        printf("A familia %s ficou sem doces.\n", name);
                    }
                    else {
                        houses->v[pos]->candy -= 1;
                        candy += 1;
                    }
                }
            }
            if (candy == 0)
                printf("%s %s recebeu 10 doces da prefeitura.\n", first_name, surname);
            else
                printf("%s %s recebeu %d doce(s) das familias.\n", first_name, surname, candy);
        }
        scanf("%s", action);
    }
    free_hash(houses);
}