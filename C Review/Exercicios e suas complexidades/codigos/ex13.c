#include<stdio.h>
#include<string.h>

int repete_letra(char str1[]){
    int quantidadeLetra;
    for(int i = 0; i < strlen(str1);i++){
        quantidadeLetra = 1;
        for(int k = 0; k < strlen(str1);k++){
            if(str1[i]==str1[k] && i!=k)
                quantidadeLetra++;
        }

        if(quantidadeLetra>1){
            return 0;
        }
    }
    return 1;
}

int repete_letra_vetor(char str1[]) {
    int quantidade[256] = {0};

    for (int i = 0; str1[i] != '\0'; i++) {
        quantidade[(unsigned char)str1[i]]++;

        if (quantidade[(unsigned char)str1[i]] > 1) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char const *argv[]){
    char str1[] = "PERNAMBUCO";
    printf("Teste 1: %d\n", repeteLetra(str1));

    char str2[] = "ALGORITMO";
    printf("Teste 2: %d\n", repeteLetra(str2));

    char str3[] = "ABCDEF";
    printf("Teste 3: %d\n", repeteLetra(str3));

    char str4[] = "AABBCC";
    printf("Teste 4: %d\n", repeteLetra(str4));

    char str5[] = "A";
    printf("Teste 5: %d\n", repeteLetra(str5));

    char str6[] = "AA";
    printf("Teste 6: %d\n", repeteLetra(str6));

    char str7[] = "ABCADE";
    printf("Teste 7: %d\n", repeteLetra(str7));

    return 0;
}