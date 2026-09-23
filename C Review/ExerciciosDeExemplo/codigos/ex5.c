#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if(n == 1 || n == 2){
	return 1;
    } else {
    	return fib(n - 1) + fib(n - 2);
    };
};

int main(int argc, char * argv[]){
    	int n = atoi(argv[1]); //posicao 0 - endereco de memoria do programa

	int res = fib(n);
	printf("%d\n", res);
};
