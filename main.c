#include <stdio.h>
#include "mapa/mapa.h"
#include "populacao/individuo/individuo.h"
#include <stdlib.h>
#include <time.h>

int main() {

srand(time(NULL));

    imprimirMapa();
    Individuo ind;
    gerarIndividuo(&ind);
    return 0;
}