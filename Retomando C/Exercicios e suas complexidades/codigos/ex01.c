#include<stdio.h>

int verificaAno(int ano){
    if(ano < 0) return -1;
    if(ano%400 == 0) return 1;
    if(ano%4 == 0 && ano%100 != 0) return 1;
    return 0;
}

int main(int argc, char const *argv[]){
    int a = 0;
    scanf("%d",&a);
    printf("%d",verificaAno(a));
}