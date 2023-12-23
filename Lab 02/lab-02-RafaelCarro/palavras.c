#include <stdio.h>
#define MAX_LENGHT 20
#define MAX_VAR 300

//Gets the amount of characters given word has
int get_len(char word[]) {
    int len = 0;
    for (int i = 0; word[i] != '\0'; i++)
        len++;
    return len;
}

//Checks the array of letters for the given word in the four possile
//directios (up <-> down, left <-> right)
int check_word(char words[], int L, int C, char letters[MAX_VAR][MAX_VAR]) {
    int len = get_len(words), eq_letters = 0;
    //left to right
    for (int j = 0; j < L; j++) {
        for (int k = 0, x = 0; k < C; k++) {
            if (words[x] == letters[j][k]) {
                eq_letters++;
                x++;
            }
            else {
                eq_letters = 0;
                x = 0;
                if (words[x] == letters[j][k]) {
                    eq_letters++;
                    x++;
                }
            }
            if (eq_letters == len)
                return 1;
        }
    }
    //right to left
    for (int j = 0; j < L; j++) {
        for (int k = C - 1, x = 0; k >= 0; k--) {
            if (words[x] == letters[j][k]) {
                eq_letters++;
                x++;
            }
            else {
                eq_letters = 0;
                x = 0;
                if (words[x] == letters[j][k]) {
                    eq_letters++;
                    x++;
                }
            }
            if (eq_letters == len)
                return 1;
        }
    }
    //top to bottom
    for (int j = 0; j < C; j++) {
        for (int k = 0, x = 0; k < L; k++) {
            if (words[x] == letters[k][j]) {
                eq_letters++;
                x++;
            }
            else {
                eq_letters = 0;
                x = 0;
                if (words[x] == letters[k][j]) {
                    eq_letters++;
                    x++;
                }
            }
            if (eq_letters == len)
                return 1;
        }
    }
    //bottom to top
    for (int j = 0; j < C; j++) {
        for (int k = L - 1, x = 0; k >= 0; k--) {
            if (words[x] == letters[k][j]) {
                eq_letters++;
                x++;
            }
            else {
                eq_letters = 0;
                x = 0;
                if (words[x] == letters[k][j]) {
                    eq_letters++;
                    x++;
                }
            }
            if (eq_letters == len)
                return 1;
        }
    }
    return 0;
}

int main() {
    int L, C, P;
    scanf("%d %d %d", &L, &C, &P);
    char letters[MAX_VAR][MAX_VAR];
    char words[MAX_VAR][MAX_LENGHT];
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++)
            scanf(" %c", &letters[i][j]);
    }
    for (int i = 0; i < P; i++) {
        scanf("%s", words[i]);
        if (check_word(words[i], L, C, letters) == 1)
            printf("A palavra %s está no texto!\n", words[i]);
        else
            printf("A palavra %s não está no texto!\n", words[i]);
    }
}