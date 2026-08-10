#include <stdio.h>

int main(){
    int n = 32;
    int soma;

    soma = 0;
    for(int i = 1; i <= n; i = i * 2){
    	soma += i;
    }; //i = 1;2;4;8;16;32... operacoes: 6x+1+1+1... O(logN)

    soma = 0;
    for(int i = 1; i <= n; i++){ //n vezes
    	for(int j = 1; j <= n; j = j * 2){ //log_n vezes
	    soma += j; // n * log_n
	};
    };
};
