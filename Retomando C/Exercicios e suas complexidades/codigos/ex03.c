#include<stdio.h>

double numeroHarmonico(int nro){
    if(nro < 0) {
        printf("Número inválido");
        return -1;
    }
    double numeroHar = 0;
    for(int i = 1; i <= nro; i++){
        numeroHar += 1/i;
    }
    return numeroHar;
}

int main(int argc, char const *argv[]){
    printf("%d",numeroHarmonico(5));
    printf("%d",numeroHarmonico(-4));
}