#include<stdio.h>
#include<string.h>

int anagrama(char str1[], char str2[]){
    if(strlen(str1)!=strlen(str2))
        return 0;

    int quantidadeLetra;
    for(int i = 0; i < strlen(str1);i++){
        quantidadeLetra = 1;
        for(int k = 0; k < strlen(str1);k++){
            if(str1[i]==str1[k] && i!=k)
                quantidadeLetra++;
        }

        for(int j = 0; j < strlen(str2);j++){
            if(str1[i]==str2[j]){
                quantidadeLetra--;
            }
        }

        if(quantidadeLetra!=0){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[]){

    char str1[] = "algoritmo";
    char str2[] = "logaritmo";
    printf("Teste 1: %d\n", anagrama(str1, str2));


    char str3[] = "abc";
    char str4[] = "cba";
    printf("Teste 2: %d\n", anagrama(str3, str4));


    char str5[] = "abb";
    char str6[] = "baa";
    printf("Teste 3: %d\n", anagrama(str5, str6));


    char str7[] = "casa";
    char str8[] = "saco";
    printf("Teste 4: %d\n", anagrama(str7, str8));

    char str9[] = "abc";
    char str10[] = "abcd";
    printf("Teste 5: %d\n", anagrama(str9, str10));

    return 0;
}