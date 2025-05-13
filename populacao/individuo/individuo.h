#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#define TAMANHO_CROMOSSOMO 100

typedef struct {
    char cromossomo[TAMANHO_CROMOSSOMO];
    int passos;
    int concluido;
    int fitness;
} Individuo;

void gerarIndividuo(Individuo *ind);

#endif