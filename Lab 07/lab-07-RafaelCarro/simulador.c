#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

//FUNÇÕES AUXILIARES PARA DIAGNOSTICO DO CÓDIGO

/*Função para printa uma lista ligada de partes.*/
void print_lista(p_node n) {
    if (n == NULL)
        printf("\n");
    else
        printf("%d, ", n->p->pack_time);
    if (n->prox != NULL)
        print_lista(n->prox);
}

/*Função que printa o estado da esteira no decorrer do tempo.*/
void print_esteira(p_queue q) {
    printf("Esteira: ");
    for (int i = q->size - 1; i >= 0; i--) {
        printf("%d ", q->v[(q->ini + i) % q->N]->class_time);
    }
    printf("\n");
} 

/*Printa a pilha ao decorrer do tempo usando a função de printar lista
ligada.*/
void print_pilha(p_stack s) {
    printf("Pilha: ");
    if (s->top != NULL)
        print_lista(s->top);
    printf("\n");
}

int main() {
    /*Criando as variaveis do problema como tempo, atraso além de variaveis
    auxiliares como o número de partes processadas e do embalador e classificador.*/
    int A, B, N, tempo = 1, atraso = 0, processados = 0;
    int embalador = 0;
    p_part classificador = malloc(sizeof(struct part));
    classificador->class_time = 0;
    classificador->pack_time = 0;
    scanf("%d %d %d", &A, &B, &N);
    /*Criação das estruturas da esteira e da pilha além das estruturas auxiliares
    do estoque para armazenar todas as peças e embalar que armazena as peças já
    classificadas.*/
    p_queue esteira = criar_fila(A);
    p_stack pilha = criar_pilha(B);
    p_part *estoque = malloc(sizeof(struct part) * N);
    for (int i = 0; i < N; i++) {
        estoque[i] = malloc(sizeof(struct part));
        get_input(estoque[i]);
    }
    p_part *embalar = malloc(sizeof(struct part) * N);
    for (int i = 0; i < N; i++) {
        embalar[i] = malloc(sizeof(struct part));
    }
    int c = 0, e = 0, classificados = 0;
    int embalando = 0;
    printf("##### Simulação\n");
    //COMEÇO DA SIMULAÇÂO!
    while (processados != N) {
        int pilha_e = 0, pilha_s = 0;
        int esteira_e = 0, esteira_s = 0;
        
        //Diagnostico
        /*printf("Tamanho da Esteira: %d\n", esteira->size);
        print_esteira(esteira);
        printf("Classificador: %d\n", classificador->class_time);
        printf("Tamanho da pilha: %d\n", pilha->size);
        print_pilha(pilha);
        printf("Embalador:");
        printf(" %d\n", embalador);
        printf("Processados: %d\n", processados);*/

        //embalador
        if (pilha->top != NULL && embalando == 0) {
            embalador = pilha->top->p->pack_time;
            embalando = 1;
            desempilhar(pilha);
        }
        if (embalando == 1) {
            if (embalador != 0)
                embalador--;
            else {
                processados++;
                pilha_s++;
                embalando = 0;
                if (pilha->top != NULL) {
                    embalador = pilha->top->p->pack_time;
                    embalando = 1;
                    desempilhar(pilha);
                    embalador--;
                }
            }
        }
        //pilha
        if (classificador->class_time == 0 && tempo > 2 && pilha->size < B && classificados < N) {
            embalar[e]->class_time = 0;
            embalar[e]->pack_time = classificador->pack_time;
            empilhar(pilha, embalar[e]);
            esteira_s++;
            pilha_e++;
            classificados++;
            e++;
            if (classificador->class_time == 0 && esteira->size > 0) {
                *classificador = *esteira->v[esteira->ini];
                desenfileira(esteira);
            }
        }
        //classificador
        if (classificador->class_time == 0 && esteira->size > 0 && pilha->size < B) {
            *classificador = *esteira->v[esteira->ini];
            desenfileira(esteira);
        }
        if(classificador->class_time > 0){
            classificador->class_time--;
        }
        //Esteira
        if (esteira->size < A && c < N) {
            enfileira(esteira, estoque[c]);
            esteira_e++;
            c++;
        }
        else if (c < N) {
            atraso++;
        }
        printf("Min. %d: Classificação (+%d,-%d) | Embalagem (+%d,-%d).\n", tempo,
        esteira_e, esteira_s, pilha_e, pilha_s);
        //printf("\n");
        tempo++;
    }
    free(classificador);
    destruir_fila(esteira);
    destruir_pilha(pilha);
    free(estoque);
    for (int i = 0; i < N; i++) {
        free(embalar[i]);
    }
    free(embalar);
    printf("Tempo atraso: %d.\n", atraso);
}