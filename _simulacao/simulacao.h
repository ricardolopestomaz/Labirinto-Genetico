#ifndef SIMULACAO_H
#define SIMULACAO_H

#include "../_populacao/populacao.h"
#include "../_fitness/fitness.h"

void simularPopulacao(Populacao *pop, int **mapa, int linhas, int colunas, int entradaX, int entradaY, int saidaX, int saidaY);

#endif
