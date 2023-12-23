#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*Function that gets the matrix from the stdinput*/
int **get_matrix(int lc) {
    int **matriz;
    matriz = malloc(lc*sizeof(int *));
    for (int i = 0; i < lc; i++) 
        matriz[i] = malloc(lc*sizeof(int));
    for (int i = 0; i < lc; i++)
        for (int j = 0; j < lc; j++)
            scanf("%d", &matriz[i][j]);
    return matriz;
}

/*Function that searches a matrix of size N for a 
submatrix with size N - 1, with the maximum possible
sum of values*/
void max_block(int *lc, int **matriz) {
    int max = INT_MIN, _i, _j;
    int sum = 0;
    //searchs the upper left corner
    for (int i = 0; i < *lc - 1; i++)
        for (int j = 0; j < *lc - 1; j++)
            sum += matriz[i][j];
    if (sum > max) {
        _i = 0, _j = 0;
        max = sum;
    }
    sum = 0;
    //searches the bottom left corner
    for (int i = 1; i < *lc; i++)
        for (int j = 0; j < *lc - 1; j++)
            sum += matriz[i][j];
    if (sum > max) {
        _i = 1, _j = 0;
        max = sum;
    }
    sum = 0;
    //searches the upper right corner
    for (int i = 0; i < *lc - 1; i++)
        for (int j = 1; j < *lc; j++)
            sum += matriz[i][j];
    if (sum > max) {
        _i = 0, _j = 1;
        max = sum;
    }
    sum = 0;
    //searchs for the bottom right corner
    for (int i = 1; i < *lc; i++)
        for (int j = 1; j < *lc; j++)
            sum += matriz[i][j];
    if (sum > max) {
        _i = 1, _j = 1;
        max = sum;
    }
    *lc = *lc - 1;
    printf("Conjuntos que precisam de atenção:\n");
    //Transports the submatrix to the upper left corner
    //of the original matrix and treats the original one
    // as a matrix of size N - 1
    for (int i = 0; i < *lc; i++) {
        int k = i + _i;
        for (int j = 0; j < *lc; j++) {
            int l = j + _j;
            matriz[i][j] = matriz[k][l];
        }
    }
     for (int i = 0; i < *lc; i++)    {
        for (int j = 0; j < *lc; j++)
            printf("%d\t", matriz[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    int lc, **matriz;
    scanf("%d", &lc);
    int N = lc;
    matriz = get_matrix(lc);
    printf("Quadras:\n");
    for (int i = 0; i < lc; i++)    {
        for (int j = 0; j < lc; j++)
            printf("%d\t", matriz[i][j]);
        printf("\n");
    }
    printf("\n");
    max_block(&lc, matriz);
    int alt;
    //checking for the input for alterarions
    while (scanf("%d", &alt) == 1) {
        if (alt == 1) {
            int a_i, a_j, v;
            scanf("%d %d %d", &a_i, &a_j, &v);
            matriz[a_i][a_j] = v;
            max_block(&lc, matriz);
        }
    }
    for (int i = 0; i < N; i++) 
        free(matriz[i]);
    free(matriz);
    return 0;
}