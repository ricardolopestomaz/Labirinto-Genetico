#include <stdlib.h>
#include "individuo/individuo.h"
#include "populacao.h"
#include <stdio.h>

void gerarPopulacao(Populacao *pop) {
    for (int i = 0; i < TAMANHO_POPULACAO; i++) {
        printf("--- INDIVIDUO [%d] ---\n", i + 1);
        gerarIndividuo(&pop->individuos[i]);
    }
}