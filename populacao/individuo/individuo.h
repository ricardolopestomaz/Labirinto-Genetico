#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#define TAMANHO_CROMOSSOMO 100

typedef struct {
    char cromossomo[TAMANHO_CROMOSSOMO];
    int passos;
    int concluido;
    float fitness;
} Individuo;

void gerarIndividuo(Individuo *ind);

void calcularFitness(Individuo *ind, int mapa[10][20]);

#endif