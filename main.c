#include "_mapa/mapa.h"
#include "_populacao/populacao.h"
#include "_simulacao/simulacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern int **mapa;
extern int linhas;
extern int colunas;

int main() {
    srand(time(NULL));
    carregarMapa("_mapa/mapa.txt");
    imprimirMapa();

    Populacao pop;
    gerarPopulacao(&pop, 100);

    // coordenadas mapa
    int entradaX = 9, entradaY = 1;
    int saidaX = 5, saidaY = 5;

    simularPopulacao(&pop, mapa, linhas, colunas, entradaX, entradaY, saidaX, saidaY);

    liberarPopulacao(&pop);
    liberarMapa();

    return 0;
}
