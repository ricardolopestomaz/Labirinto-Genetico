#include <stdlib.h>
#include <stdio.h>
#include "populacao.h"

void gerarPopulacao(Populacao* pop, int tamanho) {
    pop->inicio = NULL;
    pop->tamanho = 0;

    for (int i = 0; i < tamanho; i++) {
        No* novo = (No*) malloc(sizeof(No));
        if (!novo) {
            fprintf(stderr, "Erro ao alocar memória para indivíduo.\n");
            exit(1);
        }

        gerarIndividuo(&novo->ind); // Função já existente
        novo->prox = pop->inicio;
        pop->inicio = novo;
        pop->tamanho++;
    }
}

// Libera memória da população
void liberarPopulacao(Populacao* pop) {
    No* atual = pop->inicio;
    while (atual) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    pop->inicio = NULL;
    pop->tamanho = 0;
}
