#include<stdio.h>
#include <string.h>

int palindromo(char palavra[]){
    int palindromo = 1;
    int tam = strlen(palavra);
    for(int i = 0; i < tam/2;i++){
        if(palavra[i]!=palavra[tam-i-1]){
            palindromo = 0;
        }
    }
    return palindromo;
}

int main(int argc, char const *argv[]){
    printf("Caso 1: %d\n", palindromo("arara"));
    printf("Caso 2: %d\n", palindromo("radar"));
    printf("Caso 3: %d\n", palindromo("gato"));
    printf("Caso 4: %d\n", palindromo("ovo"));
    printf("Caso 5: %d\n", palindromo("abcba"));
    printf("Caso 6: %d\n", palindromo("abcd"));
    printf("Caso 7: %d\n", palindromo("a"));
    printf("Caso 8: %d\n", palindromo("aa"));
    printf("Caso 9: %d\n", palindromo("ab"));
}