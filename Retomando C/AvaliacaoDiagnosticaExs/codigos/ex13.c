#include<stdio.h>
#include <stdlib.h>

int *allocateArray(int size) {
    int* arr = malloc(size * sizeof(int));
    if(arr == NULL){
        return 0;
    }

    for(int i = 0; i < size; i++){
        arr[i] = i+i;
    }
    return arr;
}

int findValue(int* array, int size, int x) {
    for(int i = 0; i < size; i++){
        if(array[i] == x){
            return i;
        }
    }
    return -1;
}

int le_vetor(int* array, int size) {
    for(int i = 0; i < size; i++){
        printf("%d ",array[i]);
    }
}

int main() {
    int n = 0;
    int x = 0;
    printf("Informe o tamanho do vetor: ");
    scanf("%d",&n);
    
    int *arr = allocateArray(n);
    le_vetor(arr,n);

    printf("Informe o valor a ser buscado: ");
    scanf("%d",&x);

    printf("-1 se não encontrado, ou o índice se encontrado, resposta: %d",findValue(arr,n,x));

    free(arr);
    return 0;
}