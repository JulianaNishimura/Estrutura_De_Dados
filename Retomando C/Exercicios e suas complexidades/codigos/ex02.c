#include<stdio.h>

void verificaSeVota(int idade){
    if((idade < 16 || idade >= 70) && idade > 0){
    	printf("dispensado"); 
    	return;
    }
    if(idade >= 16 && idade < 18){
    	printf("facultativo"); 
    	return;
    }
    if(idade >= 18 && idade < 70){
    	printf("obrigatório"); 
    	return;
    }
    printf("idade inválida");
    return;
}

int main(int argc, char const *argv[]){
    verificaSeVota(19);
    verificaSeVota(12);
    verificaSeVota(17);
    verificaSeVota(87);
    verificaSeVota(-2);

}