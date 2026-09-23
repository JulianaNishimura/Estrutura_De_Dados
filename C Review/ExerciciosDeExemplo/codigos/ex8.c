#include<stdio.h>

int swap_errado(int a, int b){
	int aux = a;
	a = b;
	b = aux;
}

int swap(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

int main(int argc, char const *argv[]){
	int x = 5;
	int y = 10;

	printf("antes: %d e %d\n",x,y);
	//swap_errado(x,y) - faz copia do valor. o a copia o x, o b copia o y.
	//faz a troca no contexto da função
	swap(&x, &y);
	printf("depois: %d e %d\n",x,y);
}
/*stack
 * x - 5 - 0x02
 * y - 10 - 0x06 (pois + 4 do tamanho do int, isso conta)
 * *a - 0x02 - 0x888
 * *b - 0x06
 * aux - 5(aponta para o que tem no endereço que está no a.)
 */
