#ifndef FITNESS_H
#define FITNESS_H

#include "../_populacao/_individuo/individuo.h"
#include <stdbool.h>

typedef struct NoArvore {
    Individuo *individuo;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

int calcularFitness(Individuo *ind, int xObjetivo, int yObjetivo, int xFinal, int yFinal, bool bateu, NoArvore **raiz);
NoArvore* insertAF(NoArvore *raiz, Individuo *ind);
void percorrerFitness(NoArvore *raiz);
void melhoresFitness(NoArvore *raiz);

#endif