#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int x;
  int y;
} t_ponto;

int main(int argc, char const *argv[]){
  t_ponto ponto_na_stack;
  t_ponto *ponto_na_heap;
  
  ponto_na_stack.x = 10;
  ponto_na_stack.y = 2;
  ponto_na_heap = malloc(sizeof(t_ponto));
  
  (*ponto_na_heap).x = 20; 
  (*ponto_na_heap).y = 15;
  
  //ambas equivalentes a:
  ponto_na_heap->x = 20; 
  ponto_na_heap->y = 15;
  
  free(ponto_na_heap);
  return 0;
}
/* stack
ponto na stack - x -
" - y
ponto na heap - 0x700

heap
...} 0x700
...}
*/
