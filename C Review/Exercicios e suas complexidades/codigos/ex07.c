#include<stdio.h>

int fatorial(int nro){
    if(nro==0) return 1;
    int res = nro;
    for(int i = 2; i < nro; i++){
        res*=i;
    }
    return res;
}

int soma_fatoriais(int nro){
    if(nro < 0) return -1;
    int soma = 0;
    for(int i = 0; i <= nro; i++){
        soma+=fatorial(i);
    }
    return soma;
}

int main(int argc, char const *argv[]){
    printf("%d\n",somaFatoriais(10));
    printf("%d\n",somaFatoriais(4));
}