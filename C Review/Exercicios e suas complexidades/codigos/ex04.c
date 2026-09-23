#include<stdio.h>

void soma_sequencia(){
    int n;
    int par=0;
    int impar=0;
    do{
        scanf("%d",&n);
        if(n%2==0){ 
            par+=n;
        } else {
            impar+=n;
        }
    }while(n != 0);

    printf("Soma pares: %d\n",par);
    printf("Soma impares: %d\n",impar);
    printf("Soma total: %d\n",par+impar);
}

int main(int argc, char const *argv[]){
    somaSequencia();
}