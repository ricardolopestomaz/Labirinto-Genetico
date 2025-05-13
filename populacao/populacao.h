#ifndef POPULACAO_H
#define POPULACAO_H

#include "individuo/individuo.h"

#define TAMANHO_POPULACAO 10

typedef struct {
    Individuo individuos[TAMANHO_POPULACAO];
} Populacao;

void gerarPopulacao(Populacao *pop);

#endif
