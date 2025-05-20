#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

int **mapa = NULL;
int linhas = 0;
int colunas = 0;

void carregarMapa(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    // Lê a primeira linha: ex. "10,6"
    if (fscanf(arquivo, "%d,%d\n", &colunas, &linhas) != 2) {
        fprintf(stderr, "Erro ao ler as dimensões do mapa\n");
        fclose(arquivo);
        exit(1);
    }

    // Aloca dinamicamente o mapa
    mapa = malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        mapa[i] = malloc(colunas * sizeof(int));
    }

    char ch;
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            do {
                ch = fgetc(arquivo);
                if (ch == EOF) {
                    fprintf(stderr, "Fim de arquivo inesperado em [%d][%d]\n", l, c);
                    fclose(arquivo);
                    exit(1);
                }
            } while (ch == '\n' || ch == '\r');

            switch (ch) {
                case '#': mapa[l][c] = PAREDE; break;
                case ' ': mapa[l][c] = VAZIO; break;
                case 'S': mapa[l][c] = ENTRADA; break;
                case 'E': mapa[l][c] = SAIDA; break;
                default:
                    fprintf(stderr, "Caractere inválido '%c' no mapa em [%d][%d]\n", ch, l, c);
                    fclose(arquivo);
                    exit(1);
            }
        }
    }

    fclose(arquivo);
}

void imprimirMapa() {
    for (int l = 0; l < linhas; l++) {
        for (int c = 0; c < colunas; c++) {
            switch (mapa[l][c]) {
                case VAZIO:   printf("  "); break;
                case PAREDE:  printf("%c%c", 219, 219); break;
                case ENTRADA: printf(">>"); break;
                case SAIDA:   printf("**"); break;
            }
        }
        printf("\n");
    }
}

void liberarMapa() {
    for (int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);
}
