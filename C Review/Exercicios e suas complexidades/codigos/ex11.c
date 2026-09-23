#include<stdio.h>

int ordena(int vet[], int n){
    int i, j, aux;
    int menor;

    for(i=0;i<n-1;i++){
        menor = i;
        for(j=i+1;j<n;j++){
            if(vet[menor]>vet[j]){
                menor = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}

void ordenacao_selecao(int *vetor, int n) {
    int i, j, aux;
    int indice_menor;

    for (i=0; i<n-1; i++){
        indice_menor = i;
        for (j=i+1; j<n; j++){
            if (vetor[j] < vetor[indice_menor])
            indice_menor = j;
        }

        aux = vetor[i];
        vetor[i] = vetor[indice_menor];
        vetor[indice_menor] = aux;
    }
}

void ordenacao_bolha(int *vetor, int n) {
    int aux, i, j;
    int troca;
    for(i = 0; i < n - 1; i++){
        troca = 0;

        for(j = 0; j < n - 1 - i; j++){
            if(vetor[j] > vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;

                troca = 1;
            }
        }

        if(troca == 0)
            break;
    }
}

void imprime(int vet[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}


int main(int argc, char const *argv[]){
    int vet1[] = {1, 2, 3, 4, 5};
    int vet2[] = {5, 4, 3, 2, 1};
    int vet3[] = {4, 2, 5, 1, 3};
    int vet4[] = {3, 1, 2, 3, 1};
    int vet5[] = {7};
    int vet6[] = {-2, 5, -8, 3, 0};

    ordena(vet1, 5);
    imprime(vet1, 5);
    ordena(vet2, 5);
    imprime(vet2, 5);
    ordena(vet3, 5);
    imprime(vet3, 5);
    ordena(vet4, 5);
    imprime(vet4, 5);
    ordena(vet5, 1);
    imprime(vet5, 1);
    ordena(vet6, 5);
    imprime(vet6, 5);
}