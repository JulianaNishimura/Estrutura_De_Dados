#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]){
	int linhas = 1445;
	int colunas = linhas;

	printf("alocando memoria...");
	//int matriz[linhas][colunas];
	int **matriz;
	matriz = malloc(linhas * sizeof(int *));
	for(int i = 0; i < linhas; i++){
		matriz[i] = malloc(colunas * sizeof(int));
	}

	getchar();

	printf("liberando memoria...");
	for(int i = 0; i < linhas; i++){
		free(matriz[i]);
	}
	free(matriz);
}

