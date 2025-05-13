#include <stdio.h>
#include "mapa/mapa.h"
#include "populacao/individuo/individuo.h"
#include "populacao/populacao.h"
#include "simulacao/simulacao.h"
#include <stdlib.h>
#include <time.h>


int main() {

    srand(time(NULL));
    imprimirMapa();
    Populacao brasil;
    // Populacao alemanha;
    gerarPopulacao(&brasil);
    simularPopulacao(&brasil, mapa);

    return 0;
}