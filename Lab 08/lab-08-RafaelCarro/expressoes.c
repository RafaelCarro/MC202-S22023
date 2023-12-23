#include "binary_tree.h"
#include <string.h>
#include <stdio.h>

int main() {
    int n;
    char input[120];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p_node expression;
        scanf("%s", input);
        int size = strlen(input);
        expression = set_tree(input, size - 1);
        inorder(expression, 0);
        printf("\n");
        solve(expression);
        solve(expression);
        inorder(expression, 0);
        printf("\n\n");
        free_tree(expression);
    }
}