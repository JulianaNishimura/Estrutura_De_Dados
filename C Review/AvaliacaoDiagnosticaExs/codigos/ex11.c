#include<stdio.h>
#include<stdlib.h>

int** allocateMatrix(int linhas, int colunas) {
    int **matriz = malloc(linhas * sizeof(int *));
    for(int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(int));
    }
    return matriz;
}
int main() {
    int linhas = 3;
    int colunas = 4;
    int **matriz = allocateMatrix(linhas, colunas);
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = i+j;
        }
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
