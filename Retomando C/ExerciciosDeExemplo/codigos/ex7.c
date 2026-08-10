#include<stdio.h>

int main(int argc, char const *argv[]){
    int n;
    scanf("%d",&n);

    int vetor_estatico[5];
    int vetor_vla[n];
    
    printf("Tamanho do int em bytes: %ld\n",sizeof(int));
    printf("Tamanho do vetor estatico em bytes: %ld\n",sizeof(vetor_estatico));
    printf("Tamanho do vetor ldvla em bytes: %ld\n",sizeof(vetor_vla)); //para o vla, faz em tempo de execucao, faz a conta
    printf("Endereço de n: %ld\n",(unsigned long)&n);
    printf("Endereço do vetor estatico: %ld\n",(unsigned long)vetor_estatico);
    printf("Endereço do vetor vla: %ld\n",(unsigned long)vetor_vla);
    //ou %p
    printf("Valor do primeiro elemento: %d\n",vetor_estatico[1]);
    printf("Outra forma: %d\n",*(vetor_estatico+1));

    return 0;
}
