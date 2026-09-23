#include<stdio.h>

int verifica_ordenacao(int vet[], int n){
    int res,direcao;
    res = 1;
    direcao = 0;

    for(int i = 0; i < n-1; i++){
        if(vet[i] > vet[i+1] && direcao == 0){
            direcao = -1;
            res = -1;
        } 
        
        if(vet[i] < vet[i+1] && direcao == 0){
            direcao = 1;
        }

        if(direcao == 1){
            if(vet[i] > vet[i+1]){
                res = 0;
            }                
        } else if (direcao == -1) {
            if(vet[i] < vet[i+1]){
                res = 0;
            }
        }
    }

    return res;
}

int main(int argc, char const *argv[]){
    int vet1[] = {1, 2, 3, 4, 5};
    int vet2[] = {5, 4, 3, 2, 1};
    int vet3[] = {1, 2, 2, 3, 4};
    int vet4[] = {5, 5, 5, 5};
    int vet5[] = {1, 3, 2, 4, 5};
    int vet6[] = {5, 3, 4, 2, 1};
    int vet7[] = {4, 4, 4, 2, 1};
    int vet8[] = {6, 6, 8, 10, 13};

    printf("Caso 1: %d\n", verificaOrdenacao(vet1, 5));
    printf("Caso 2: %d\n", verificaOrdenacao(vet2, 5));
    printf("Caso 3: %d\n", verificaOrdenacao(vet3, 5));
    printf("Caso 4: %d\n", verificaOrdenacao(vet4, 4));
    printf("Caso 5: %d\n", verificaOrdenacao(vet5, 5));
    printf("Caso 6: %d\n", verificaOrdenacao(vet6, 5));
    printf("Caso 7: %d\n", verificaOrdenacao(vet7, 5));
    printf("Caso 8: %d\n", verificaOrdenacao(vet8, 5));
}