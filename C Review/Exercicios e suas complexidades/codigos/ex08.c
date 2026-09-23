#include<stdio.h>

int procura_numero(int vet[], int n, int x){
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(vet[i]==x){
            cont++;
        }
    }
    return cont;
}

int main(int argc, char const *argv[]){
    int vet1[] = {4, 7, 2, 7, 9, 7};
    int vet2[] = {1, 2, 3, 4, 5};
    int vet3[] = {8, 8, 8, 8};
    int vet4[] = {10};
    int vet5[] = {5, 2, 5, 3, 5, 7, 5};

    printf("Caso 1: %d\n", procuraNumero(vet1, 6, 7));
    printf("Caso 2: %d\n", procuraNumero(vet2, 5, 8));
    printf("Caso 3: %d\n", procuraNumero(vet3, 4, 8));
    printf("Caso 4: %d\n", procuraNumero(vet4, 1, 10));
    printf("Caso 5: %d\n", procuraNumero(vet5, 7, 5));
}