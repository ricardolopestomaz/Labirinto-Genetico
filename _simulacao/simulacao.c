#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "simulacao.h"
#include "../_mapa/mapa.h"
#include "../_populacao/_individuo/individuo.h"
#include "../_fitness/fitness.h"

void liberarArvore(NoArvore *raiz) {
    if (raiz == NULL) return;

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

void simularIndividuo(Individuo *ind, int **mapa, int linhas, int colunas, int entradaX, int entradaY, int saidaX, int saidaY, NoArvore **raiz) {
    int x = entradaX;
    int y = entradaY;
    int passos = 0;
    bool bateu = false;

    for (int i = 0; i < TAMANHO_CROMOSSOMO; i++) {
        int novoX = x;
        int novoY = y;

        if (ind->cromossomo[i] == 'C') {
            novoX = x - 1;
        } else if (ind->cromossomo[i] == 'B') {
            novoX = x + 1;
        } else if (ind->cromossomo[i] == 'E') {
            novoY = y - 1;
        } else if (ind->cromossomo[i] == 'D') {
            novoY = y + 1;
        }

        // Verifica se nova posição é inválida
        if (novoX < 0 || novoX >= linhas || novoY < 0 || novoY >= colunas || mapa[novoX][novoY] == PAREDE) {
            printf("Individuo bateu na parede na posicao (%d, %d) no passo %d. Parando simulacao.\n", novoX, novoY, passos + 1);
            bateu = true;
            break;
        }

        // Movimento válido
        x = novoX;
        y = novoY;
        passos++;

        if (x == saidaX && y == saidaY) {
            ind->concluido = true;
            printf("\n________________\nCHEGOU AO OBJETIVO!\n________________\n");
            break;
        }
    }

    ind->passos = passos;
    ind->fitness = calcularFitness(ind, saidaX, saidaY, x, y, bateu, raiz);
}




void simularPopulacao(Populacao *pop, int **mapa, int linhas, int colunas, int entradaX, int entradaY, int saidaX, int saidaY) {
    NoArvore *raiz = NULL;

    // Percorre lista encadeada da populacao
    for (No *no = pop->inicio; no != NULL; no = no->prox) {
        simularIndividuo(&no->ind, mapa, linhas, colunas, entradaX, entradaY, saidaX, saidaY, &raiz);
    }

    printf("\nFitness dos individuos:\n");
    melhoresFitness(raiz);

    // Libera a arvore de fitness para evitar vazamento
    liberarArvore(raiz);
    raiz = NULL;
}
