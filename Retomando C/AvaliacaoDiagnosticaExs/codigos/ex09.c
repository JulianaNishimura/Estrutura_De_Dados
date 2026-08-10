#include <stdio.h>

void swap(int *i, int *y) {
    int aux = *i;
    *i = *y;
    *y = aux;
}
int main() {
    int x = 5, y = 10;
    printf("Antes do swap: x = %d, y = %d\n", x, y);
    swap(&x,&y);
    printf("Depois do swap: x = %d, y = %d\n", x, y);
    return 0;
}
