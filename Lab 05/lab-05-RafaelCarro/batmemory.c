#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vetor.h"

int main() {
    p_vector bat_memory = bat_init();
    int n_actions;
    scanf("%d", &n_actions);
    for (int i = 0; i < n_actions; i++) {
        char action[10];
        scanf("%s", action);
        if (strcmp(action, "bat-alloc") == 0)
            bat_alloc(bat_memory);
        else if (strcmp(action, "bat-free") == 0)
            bat_free(bat_memory);
        else if (strcmp(action, "bat-print") == 0)
            bat_print(bat_memory);
        else if (strcmp(action, "bat-uso") == 0)
            bat_uso(bat_memory);
    }
    free(bat_memory->nums);
    free(bat_memory);
}