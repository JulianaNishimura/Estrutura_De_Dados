#include<stdio.h>

double numeroHarmonico(int nro){
    if(nro < 0) {
        printf("Número inválido: ");
        return -1;
    } else {
        double numeroHar = 0;
        for(double i = 1; i <= nro; i++){
            numeroHar += 1/i;
        }
        return numeroHar;
    }
    return -1;
}

int main(int argc, char const *argv[]){
    printf("%lf",numeroHarmonico(5));
    printf("%lf",numeroHarmonico(-4));
}