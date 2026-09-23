#include<stdio.h>
#include <ctype.h>
#include <string.h>

void minusculo(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

void tiraEspaco(char str[]) {
    int quantidade = strlen(str);

    for (int i = 0; i < quantidade; i++) {
        if (str[i] == ' ') {
            for (int j = i; j < quantidade; j++) {
                str[j] = str[j + 1];
            }
            quantidade--;
            i--;
        }
    }
}

int isPalindrome(char str[]) {
    minusculo(str);
    tiraEspaco(str);
    int palindromo = 1;
    int quantidade = strlen(str);

    for(int i = 0; i < quantidade/2; i++){
        if(str[i]!=str[quantidade-1-i]){
            palindromo = 0;
        }
    }
    return palindromo;
}
int main() {
    char str[] = "arara";
    char str2[] = "A base do teto desaba";
    char str3[] = "gato";
    printf("%d",isPalindrome(str));
    printf("%d",isPalindrome(str2));
    printf("%d",isPalindrome(str3));
    return 0;
}