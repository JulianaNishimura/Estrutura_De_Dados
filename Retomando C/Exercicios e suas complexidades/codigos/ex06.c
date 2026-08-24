#include<stdio.h>

int primo(int nro){
    int primo = 1;
    int i = 2;

    while(primo && i < nro){
        if(nro%i==0){
            primo = 0;
        }
        i++;
    }
    return primo;
}

int main(int argc, char const *argv[]){
    printf("%d",primo(4));
    printf("%d",primo(7));
    printf("%d",primo(5));
    printf("%d",primo(13));
}