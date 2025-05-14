#ifndef FITNESS_H
#define FITNESS_H

#include "../populacao/individuo/individuo.h"

typedef struct NoArvore {
    Individuo *individuo;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

int calcularFitness(Individuo *ind, int xObjetivo, int yObjetivo, int xFinal, int yFInal, NoArvore **raiz);
NoArvore* insertAF(NoArvore *raiz, Individuo *ind);
void percorrerFitness(NoArvore *raiz);
void melhoresFitness(NoArvore *raiz);

#endif