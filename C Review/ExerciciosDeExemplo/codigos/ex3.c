#include<stdio.h>

int main(){
    int vetor[] = {1, 3, 5, 8, 3, 10, 15, 5};
    //int vetor[] = {1, 3, 5, 8, 4, 10, 15, 2};
    int n = 8;
    int repetido = 0;
    int qtd_operacoes = 0;

    for (int i = 0; i < n - 1 && !repetido; i++){
        for(int j = i + 1; j < n; j++){
	    qtd_operacoes++;
	    if(vetor[i] == vetor[j]){
	       repetido = 1;
	       break;
	    };
	};
    };
    printf("Quantidade de operacoes: %d\n", qtd_operacoes);
    printf("Repetido: %d\n", repetido);
}
