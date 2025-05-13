#include "fitness.h"
#include <stdlib.h>
#include <stdio.h>

int calcularFitness(Individuo *ind, int xObjetivo, int yObjetivo, int xFinal, int yFinal){
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
    printf("\nFITNESS ADICIONADO\n");
    return fitness;
}