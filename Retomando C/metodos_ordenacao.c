#include<stdio.h>

void selection_sort(int* arr, int n) {
    int menor, aux;
    for(int i = 0; i < n; i++){
        menor = i;
        for(int j = i+1;j < n;j++){
            if(arr[menor]>arr[j]){
                menor = j;
            }
        }
        if (menor != i) {
            int aux = arr[i];
            arr[i] = arr[menor];
            arr[menor] = aux;
        }
    }
}
/*
teste de mesa - arr = {5, 2, 4, 6, 1, 3}
menor = 0 (item 5);
de index 1 a 5 - 
    j = 1, arr[menor] = 5 > arr[j] = 2 ? sim entao menor = 1
    j = 2, arr[menor] = 2 > arr[j] = 4 ? não entao menor = 2
    j = 3, arr[menor] = 2 > arr[j] = 6 ? não entao menor = 2
    j = 4, arr[menor] = 2 > arr[j] = 1 ? sim entao menor = 4
    j = 5, arr[menor] = 1 > arr[j] = 3 ? nao entao menor = 4
sai do laço.
menor é i(0)? não, então troca arr[0] com arr[4]
arr = {1, 2, 4, 6, 5, 3}
e assim por diante.
*/

void bubble_sort_menor_inicio(int* arr, int n) {
    int aux,i,trocou;
    for(int i = 0; i < n-1; i++){
        trocou = 0;
        for(int j = n-1; j > i; j--){
            if(arr[j]<arr[j-1]){
                aux = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = aux;
                trocou = 1;
            }
        }
        if(!trocou) break;
    }
}

void bubble_sort_maior_final(int* arr, int n) {
    int aux,i,trocou;
    for(int i = 0; i < n-1; i++){
        trocou = 0;
        for(int j = 0; j < n-1-i; j++){
            if(arr[j]>arr[j+1]){
                aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
                trocou = 1;
            }
        }
        if(!trocou) break;
    }
}

/*
explicações:

por que n-1? porque quando chegamos à última posição restante, ela já estará ordenada.

por que o segundo for começa de n-1 e vai até i?
Os elementos que já estão nas posições anteriores a i já foram
ordenados e não precisam ser comparados novamente.

j = n-1 e j-- direita → esquerda | arr[j] < arr[j-1] | menor → início |
j = 0 ej++ esquerda → direita | arr[j] > arr[j+1] | maior → final  |

teste de mesa - {5, 2, 4, 6, 1, 3}
i = 0, trocou = 0
segundo for:
    j = 5, arr[5] = 3 < arr[4] = 1 ? não
    vetor = {5, 2, 4, 6, 1, 3}

    j = 4, arr[4] = 1 < arr[3] = 6 ? sim
    vetor = {5, 2, 4, 1, 6, 3}
    trocou = 1

    j = 3, arr[3] = 1 < arr[2] = 4 ? sim
    vetor = {5, 2, 1, 4, 6, 3}

    j = 2, arr[2] = 1 < arr[1] = 2 ? sim
    vetor = {5, 1, 2, 4, 6, 3}

    j = 1, arr[1] = 1 < arr[0] = 5 ? sim
    vetor = {1, 5, 2, 4, 6, 3}

entao:
arr = {1, 5, 2, 4, 6, 3}
i = 1, trocou = 0
segundo for:
    j = 5, arr[5] = 3 < arr[4] = 6 ? sim
    vetor = {1, 5, 2, 4, 3, 6}
    trocou = 1

    j = 4, arr[4] = 3 < arr[3] = 4 ? sim
    vetor = {1, 5, 2, 3, 4, 6}

    j = 3, arr[3] = 3 < arr[2] = 2 ? não
    vetor = {1, 5, 2, 3, 4, 6}

    j = 2, arr[2] = 2 < arr[1] = 5 ? sim
    vetor = {1, 2, 5, 3, 4, 6}

depois da segunda iteração:
arr = {1, 2, 5, 3, 4, 6}
*/

void insertion_sort(int* arr, int n) {
    int chave,i,j;
    for(i = 1; i < n; i++){
        chave = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > chave){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = chave;
    }
}

/*
teste de mesa - arr = {5, 2, 4, 6, 1, 3}
i = 1, chave = 2, j = 0
while:
    j >= 0? sim
    arr[j] = 5 > chave = 2? sim
    arr[j+1(1)] = 2 recebendo arr[j(0)] = 5 → arr = {5, 5, 4, 6, 1, 3}
    j-- → j = -1
sai do while, arr[j+1(0)] = chave(2) → arr = {2, 5, 4, 6, 1, 3}

i = 2, chave = 4, j = 1
while:
    j >= 0? sim
    arr[j] = 5 > chave = 4? sim
    arr[j+1(2)] = 4 recebendo arr[j(1)] = 5 → arr = {2, 5, 5, 6, 1, 3}
    j-- → j = 0
sai do while, arr[j+1(1)] = primeiro 5 recebendo chave(4) = 4 → arr = {2, 4, 5, 6, 1, 3}

i = 3, chave = 6, j = 2
while:
    j >= 0? sim
    arr[j] = 5 > chave = 6? não

e assim por diante
*/

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        }
        else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/*
teste de mesa - { 12, 11, 13, 5, 6, 7 }

chama o mergeSort(arr, 0, 5)
0 < 5 ? sim, então entra e faz o mid
mid = 0 + (5 - 0) / 2 = 2

chama mergeSort(arr, 0, 2) - esq
    0 < 2 ? sim, então entra e faz o mid
    mid = 0 + (2 - 0) / 2 = 1

    chama mergeSort(arr, 0, 1) - esq
        0 < 1 ? sim, então entra e faz o mid
        mid = 0 + (1 - 0) / 2 = 0

        chama mergeSort(arr, 0, 0) - esq
            0 < 0 ? não, então retorna

        chama mergeSort(arr, 1, 1) - dir
            1 < 1 ? não, então retorna

        chama merge(arr, 0, 0, 1)
            n1 = mid - left + 1 = 0 - 0 + 1 = 1;
            n2 = right - mid = 1 - 0 = 1;

            int leftArr[n1], rightArr[n2];

            preenche eles
            for (i = 0; i < n1; i++)
                leftArr[i] = arr[left + i];
            for (j = 0; j < n2; j++)
                rightArr[j] = arr[mid + 1 + j];

            i = 0;
            j = 0;
            k = left = 0;

            i = 0 < n1 = 1 ? sim
            &&
            j = 0 < n2 = 1 ? sim
            entao entra no while:
                leftArr[i(0)] = 12 <= rightArr[j(0)] = 11 ? não
                entao arr[k(0)] = rightArr[j(0)] = 11
                j = 1
                k = 1
                i = 0 < n1 = 1 ? sim
                &&
                j = 1 < n2 = 1 ? não
            sai do while

            i = 0 < n1 = 1 ? sim
            entao arr[k(1)] = leftArr[i(0)] = 12
            i=1
            k=2
            i=1 < n1 = 1 ? não
            sai do while

            j = 1 < n2 = 1 ? não
            nao entra no while
            FIM DO MERGE

    chama mergeSort(arr, 2, 2) - dir
        2 < 2 ? não, então retorna

    chama merge(arr, 0, 1, 2)

chama mergeSort(arr, 3, 5) - dir
    3 < 5 ? sim, então entra e faz o mid
    mid = 3 + (5 - 3) / 2 = 4

    chama mergeSort(arr, 3, 4) - esq
        3 < 4 ? sim, então entra e faz o mid
        mid = 3 + (4 - 3) / 2 = 3

        chama mergeSort(arr, 3, 3) - esq
            3 < 3 ? não, então retorna

        chama mergeSort(arr, 4, 4) - dir
            4 < 4 ? não, então retorna

        chama merge(arr, 3, 3, 4)

    chama mergeSort(arr, 5, 5) - dir
        5 < 5 ? não, então retorna

    chama merge(arr, 3, 4, 5)

chama merge(arr, 0, 2, 5)
*/

int particiona(int vet[], int inicio, int fim) {
    int pivo = vet[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vet[j] <= pivo) {
            i++;
            int aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }

    int aux = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = aux;

    return i + 1;
}

void quickSort(int vet[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particiona(vet, inicio, fim);

        quickSort(vet, inicio, pivo - 1);
        quickSort(vet, pivo + 1, fim);
    }
}

/*
teste de mesa - { 10, 7, 8, 9, 1, 6 }
chama quickSort(vet, 0, 5)
0 < 5 ? sim, então entra e chama particiona(vet, 0, 5)
    pivo = vet[5] = 6
    i = -1
    for j = 0; j < 5; j++
        j=0, vet[0] = 10 <= pivo = 6 ? não
        j=1, vet[1] = 7 <= pivo = 6 ? não
        j=2, vet[2] = 8 <= pivo = 6 ? não
        j=3, vet[3] = 9 <= pivo = 6 ? não
        j=4, vet[4] = 1 <= pivo = 6 ? sim
            i++ → i=0
            troca vet[i(0)] com vet[j(4)] → {1, 7, 8, 9, 10, 6}
    troca vet[i+1(1)] com vet[fim(5)] → {1, 6, 8, 9, 10, 7}
    retorna i+1 = 1
    
    chama quickSort(vet, 0, 0) - esq
        0 < 0 ? não, então retorna
    chama quickSort(vet, 2, 5) - dir
        2 < 5 ? sim, então entra
        chama particiona(vet, 2, 5)
            pivo = vet[5] = 7
            i = 1
            for j = 2; j < 5; j++
                j=2, vet[2] = 8 <= pivo = 7 ? não
                j=3, vet[3] = 9 <= pivo = 7 ? não
                j=4, vet[4] = 10 <= pivo = 7 ? não
            troca vet[i+1(2)] com vet[fim(5)] → {1, 6, 7, 9, 10, 8}
            retorna i+1 = 2
    chama quickSort(vet, 2, 1) - esq
        2 < 1 ? não, então retorna
    chama quickSort(vet, 3, 5) - dir
        3 < 5 ? sim, então entra  
        chama particiona(vet, 3, 5)
            pivo = vet[5] = 8
            i = 2
            for j = 3; j < 5; j++
                j=3, vet[3] = 9 <= pivo = 8 ? não
                j=4, vet[4] = 10 <= pivo = 8 ? não
            troca vet[i+1(3)] com vet[fim(5)] → {1, 6, 7, 8, 10, 9}
            retorna i+1 = 3
    chama quickSort(vet, 3, 2) - esq
        3 < 2 ? não, então retorna 
    chama quickSort(vet, 4, 5) - dir
        4 < 5 ? sim, então entra
        chama particiona(vet, 4, 5)
            pivo = vet[5] = 9
            i = 3
            for j = 4; j < 5; j++
                j=4, vet[4] = 10 <= pivo = 9 ? não
            troca vet[i+1(4)] com vet[fim(5)] → {1, 6, 7, 8, 9, 10}
            retorna i+1 = 4
    chama quickSort(vet, 4, 3) - esq
        4 < 3 ? não, então retorna
    chama quickSort(vet, 5, 5) - dir
        5 < 5 ? não, então retorna
    finaliza o quickSort
    vetor = {1, 6, 7, 8, 9, 10}
*/