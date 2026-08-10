#include<stdio.h>

int main(){
    int n = 100;
    int soma = 0;

    printf("%d\n", n);
    
    for (int i = 1; i <= n; i++){
    	soma += i; //complexidade O(n)
    };

    printf("Soma: %d\n", soma);

    soma = 0;
    for(int i = 1; i <= n; i++){
	if(i % 2 == 0){ //O(n) -> n vezes
	   soma += i;
	}
    }

    printf("Soma dos pares: %d\n", soma);

    soma = 0;
    for(int i = 2; i <= n; i += 2){
    	soma += i; //n/2 vezes -> porém complexidade de O(n)
    }

    printf("Soma dos pares versão 2: %d\n", soma);
    //Entre ambos com o mesmo O, sabemos que o primeiro é mais custoso pois faz mais operações, mesmo que a escalabilidade/crescimento linear são iguais. São equivalentes apenas em crescimento, e não tempo ou custo.
}
