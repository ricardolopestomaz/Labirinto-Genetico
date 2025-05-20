#include "fitness.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int calcularFitness(Individuo *ind, int xObjetivo, int yObjetivo, int xFinal, int yFinal, bool bateu, NoArvore **raiz) {
    int distancia = abs(xObjetivo - xFinal) + abs(yObjetivo - yFinal);
    int fitness = 0;

    // Quanto mais perto do objetivo, mais pontos (máximo: 1000)
    fitness += 1000 - (distancia * 10);

    // Bônus se chegou ao objetivo
    if (xFinal == xObjetivo && yFinal == yObjetivo) {
        fitness += 1000;
    }

    if (ind->passos > 0) {
        fitness -= ind->passos * 2;
    }

    if (bateu) {
        fitness -= 500;  // Penalidade extra
    }


    if (fitness < 0) {
        fitness = 0;
    }



    ind->fitness = fitness;
    *raiz = insertAF(*raiz, ind);

    printf("Distancia: %d, Passos: %d, Bateu: %d, Fitness calculado: %d\n", distancia, ind->passos, bateu, fitness);


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
int id = 1;

void melhoresFitness(NoArvore *raiz){
    if(raiz != NULL){
        melhoresFitness(raiz->direita);
        printf("[%d] fitness: %d\n", id++ ,raiz->individuo->fitness);
        melhoresFitness(raiz->esquerda);
    }
}
