#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int matriz[4][3];

    //numero de linhas: n
    //numero de colunas: m

    for(int i = 0; i < 4; i++){
    	for(int j = 0; j < 3; j++){
	    matriz[i][j] = rand() % 10; // O(n*m)
	};
    };
}
