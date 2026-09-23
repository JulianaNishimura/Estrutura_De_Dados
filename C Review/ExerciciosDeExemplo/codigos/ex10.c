#include<stdio.h>
#include<stdlib.h>

int *criar_vetor_dinamico(int n){
	int *vetor;
	vetor = malloc(n * sizeof(int));

	if(vetor == NULL){
	   return NULL;
	}
	return vetor;
}

int main(int argc, char const *argv[]){
	int n;
	scanf("%d", &n);

	int *vetor_dinamico1;
        vetor_dinamico1 = criar_vetor_dinamico(n);

	printf("Tamanho do vetor_dinamico em bytes: %ld\n", sizeof(vetor_dinamico1));
	//por que 8? pois na declaracao ele nao sabe que é um vetor, sabe apenas que é um ponteiro. Ele nao faz a conta.
	printf("Endereco da memoria alocada: %ld\n", (unsigned long)vetor_dinamico1);
	printf("Endereco da variavel ponteiro: %p\n", &vetor_dinamico1);
	printf("Endereco da variavel n: %p\n", &n);
	
	int *vetor_dinamico2;
        vetor_dinamico2 = criar_vetor_dinamico(n);

	printf("Tamanho do vetor_dinamico em bytes: %ld\n", sizeof(vetor_dinamico2));
	printf("Endereco da memoria alocada: %ld\n", (unsigned long)vetor_dinamico2);
	printf("Endereco da variavel ponteiro: %p\n", &vetor_dinamico2);
	printf("Endereco da variavel n: %p\n", &n);

	free(vetor_dinamico1);
	free(vetor_dinamico2);
	return 0;
}
/*stack
 * n - 10 - 0x00
 * vetor_dinamico - 0x710 - 0x04
* 0x12(ponteiro tem 8 bytes, ent o vetor_dinamico tem 8 bytes)
*
 * heap
 *? - ? - 0x710
 .}
 . } 40 bytes
 .}
 */
