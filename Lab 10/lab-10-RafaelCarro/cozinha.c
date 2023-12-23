#include "priority_list.h"
#include "survivor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //Setup
    int P, S;
    scanf("%d %d", &P, &S);
    p_fp p_queue = create_p_list(S);
    p_sur *survivors = malloc(S*sizeof(struct survivor));
    //auxiliar vector to holds the dishes made.
    p_dish *trash = malloc(100000*sizeof(struct dish));
    int t = 0;
    for (int i = 0; i < S; i++) {
        survivors[i] = add_survivor();
        //printf("Sobrevivente %s está vivo a %d dias.\n", survivors[i]->name, survivors[i]->days);
    }
    //N Rounds
    int N, count = 1;
    scanf("%d", &N);
    while (N != 0) {
        for (int i = 0; i < N; i++) {
            char task[10], dish_name[26];
            int ID, value;
            scanf("%s %d ", task, &ID);
            if (strcmp("novo", task) == 0) {
                fgets(dish_name, 25, stdin);
                dish_name[strlen(dish_name) - 1] = '\0';
                p_dish temp = create_dish(ID, survivors[ID]->days, dish_name);
                insert(p_queue, temp);
            }
            else {
                scanf("%d", &value);
                int pos = find_pos(p_queue, ID);
                if(pos >= 0)
                    change_key(p_queue, pos, value);
            }
        }
        printf("---- rodada %d ----\n", count++);
        for (int i = 0; i < P && p_queue->n != 0; i++) {
            p_dish done = extract_max(p_queue);
            trash[t] = done;
            t++;
            printf("%s %s %d\n", survivors[done->id]->name, done->dish, done->key);
        }
        scanf("%d", &N);
    }
    //Remaining Dishes
    while (p_queue->n > 0) {
        printf("---- rodada %d ----\n", count++);
        for (int i = 0; i < P && p_queue->n != 0; i++) {
            p_dish done = extract_max(p_queue);
            trash[t] = done;
            t++;
            printf("%s %s %d\n", survivors[done->id]->name, done->dish, done->key);
        }
    }
    //Freeing the elements
    free_pl(p_queue);
    for (int i = 0; i < S; i++)
        free(survivors[i]);
    for (int i = 0; i < t; i++)
        free(trash[i]);
    free(trash);
    free(survivors);
}