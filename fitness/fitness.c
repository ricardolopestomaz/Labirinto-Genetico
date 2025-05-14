#include "fitness.h"
#include <stdlib.h>
#include <stdio.h>

int calcularFitness(Individuo *ind, int xObjetivo, int yObjetivo, int xFinal, int yFinal, NoArvore **raiz){
    int distancia = abs(xObjetivo - xFinal) + abs(yObjetivo - yFinal);
    int fitness = 0;

    // Quanto mais perto do objetivo mais pontos (maximo: 1000)
    fitness += 1000 - (distancia * 10);

    // Se chegou exatamente no objetivo
    if (xFinal == xObjetivo && yFinal == yObjetivo){
        fitness += 1000; // Bonus
    }

    if (ind->passos > 0){
        fitness -= ind->passos * 2;
    }

    if (fitness < 0){
        fitness = 0;
    }

    ind->fitness = fitness;
    *raiz = insertAF(*raiz, ind);

    return fitness;
}

NoArvore* insertAF(NoArvore *raiz, Individuo *ind) {
    if (raiz == NULL) {
        NoArvore *novo = malloc(sizeof(NoArvore));
        novo->individuo = ind;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    // Se o fitness for menor que o do nó atual, insira à esquerda.
    if (ind->fitness < raiz->individuo->fitness) {
        raiz->esquerda = insertAF(raiz->esquerda, ind);
    } else {
        raiz->direita = insertAF(raiz->direita, ind);
    }

    return raiz;
}

void percorrerFitness(NoArvore *raiz){
    if (raiz != NULL){
        percorrerFitness(raiz->direita);
        printf("fitness: %d\n",raiz->individuo->fitness);
        percorrerFitness(raiz->esquerda);
    }
}

void melhoresFitness(NoArvore *raiz){
    if(raiz != NULL){
        melhoresFitness(raiz->direita);
        printf("fitness: %d\n", raiz->individuo->fitness);
    }
}