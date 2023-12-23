#include <stdio.h>

void cout(int five, int seven, int ten, int biggest_sequence, int salad_sequence) {
    printf("James vendeu %d saladas de 5 reais, %d de 7 reais e %d de 10 reais\n", five, seven, ten);
    printf("James vendeu %d saladas de %d reais consecutivamente\n", biggest_sequence, salad_sequence);
}

int main() {
    int n, five = 0, seven = 0 , ten = 0;
    int last_salad = 0, biggest_sequence = 0, current_sequence = 1, salad_sequence = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; 
        scanf("%d", &x);
        if (x == 5)
            five++;
        else if (x == 7)
            seven++;
        else
            ten++;
        if (x == last_salad)
            current_sequence++;
        else {
            current_sequence = 1;
        }
        if (current_sequence > biggest_sequence) {
                biggest_sequence = current_sequence;
                salad_sequence = x;
            }
        last_salad = x;
    }
    cout(five, seven, ten, biggest_sequence, salad_sequence);
}