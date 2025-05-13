#include <stdlib.h>
#include "populacao.h"

void gerarPopulacao(Populacao *pop) {
    for (int i = 0; i < TAMANHO_POPULACAO; i++) {
        gerarIndividuo(&pop->individuos[i]);
    }
}