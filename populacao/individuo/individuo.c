#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "individuo.h"

void gerarIndividuo(Individuo *ind){
    const char movimentos[] = {'C', 'B', 'E', 'D'};
    for (int i = 0; i < TAMANHO_CROMOSSOMO; i++){
        int r = rand() % 4;
        ind -> cromossomo[i] = movimentos[r];
        printf("Movimentos [%d]: %c\n", i, ind -> cromossomo[i]);
    }
    ind -> passos = 0;
    ind -> concluido = 0;
    ind -> fitness = 0;
    
}