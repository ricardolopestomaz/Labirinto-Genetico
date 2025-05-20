#ifndef POPULACAO_H
#define POPULACAO_H

#include "_individuo/individuo.h"

typedef struct No {
    Individuo ind;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    int tamanho;
} Populacao;

void gerarPopulacao(Populacao* pop, int tamanho);
void liberarPopulacao(Populacao* pop);

#endif
