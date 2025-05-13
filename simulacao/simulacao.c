#include <stdio.h>
#include <stdbool.h>
#include "simulacao.h"
#include "../mapa/mapa.h"
#include "../populacao/individuo/individuo.h"

void simularIndividuo(Individuo *ind, int mapa[LINHA][COLUNA]){
    int x = 0, y = 1; // INICIO
    int passos = 0;

    for (int i = 0; i< TAMANHO_CROMOSSOMO; i++){
        if(ind->cromossomo[i] == 'C'){
            // ANDA PARA CIMA
            if(x > 0 && mapa[x-1][y] != 1){
                // VERIFICA SE NÃO É PAREDE
                x--;
                passos++;
                printf("ANDOU\n");
            }
            else{
                printf("PAREDE\n");
            }
        }
        else if(ind->cromossomo[i] == 'B'){
            if(x < 9 && mapa[x+1][y] != 1){
                x++;
                passos++;
                printf("ANDOU\n");
            }
            else{
                printf("PAREDE\n");
            }
        }
        else if(ind->cromossomo[i] == 'E'){
            if(y > 0 && mapa[x][y-1] != 1){
                y--;
                passos++;
                printf("ANDOU\n");
            }
            else{
                printf("PAREDE\n");
            }
        }
        else if(ind->cromossomo[i] == 'D'){
            if(y < 19 && mapa[x][y+1] != 1){
                y++;
                passos++;
                printf("ANDOU\n");
            }
            else{
                printf("PAREDE\n");
            }
        }

        // CHEGOU NA SAIDA
        if (x == 8 && y == 19) {
            ind->concluido = true;
            printf("\n________________\n");
            printf("CHEGOU\n");
            printf("\n________________\n");
            break;
        }
    }

    ind->passos = passos;

    // ind->fitness = calcularFitness(x, y);

}


void simularPopulacao(Populacao *pop, int mapa[LINHA][COLUNA]){
    for (int i = 0; i < TAMANHO_POPULACAO; i++){
        simularIndividuo(&pop->individuos[i], mapa);
    }
}