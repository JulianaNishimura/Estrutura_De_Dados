#include<stdio.h>

int fatorial(int nro){
    if(nro < 0) return -1;
    if(nro == 0) return 1;
    int res = nro;
    for(int i = 1; i < nro; i++){
        res*=i;
    }
    return res;
}

int main(int argc, char const *argv[]){
    printf("%d\n",fatorial(4));
    printf("%d\n",fatorial(7));
    printf("%d",fatorial(5));
}