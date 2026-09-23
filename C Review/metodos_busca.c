#include <stdio.h>

int busca_sequencial(int* arr, int n, int elem) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem) {
            return 1;
        }
    }

    return 0;
}

/*
TESTE DE MESA - {2, 5, 8, 12}
n = 4
elem = 8
chama busca_sequencial(arr, 4, 8)
    i = 0
    0 < 4 ? sim

    arr[i](2) == elem(8) ? não
    i++

    i = 1
    1 < 4 ? sim

    arr[1](5) == elem(8) ? não
    i++

    i = 2
    2 < 4 ? sim

    arr[2](8) == elem(8) ? sim
    return 1
*/

int busca_binaria(int* arr, int n, int elem) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == elem) {
            return 1;
        }

        if (arr[meio] > elem) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return 0;
}


/*
TESTE DE MESA - {2, 5, 8, 12}
n = 4
elem = 8

chama busca_binaria(arr, 4, 8)
    inicio = 0
    fim = n - 1 = 4 - 1 = 3

    inicio(0) <= fim(3) ? sim
    entra no while:
        meio = inicio + (fim - inicio) / 2 = 0 + (3 - 0)/2 = 1
        arr[meio](5) == elem(8) ? nao
        arr[meio](5) > elem(8) ? não

        então entra no else:
            inicio = meio + 1
            inicio = 2

    inicio = 2
    fim = 3

    inicio(2) <= fim(3) ? sim
    entra no while:
        meio = inicio + (fim - inicio) / 2 = 2 + (3 - 0)/2 = 2
        arr[meio](8) == elem(8) ? sim
        return 1
*/