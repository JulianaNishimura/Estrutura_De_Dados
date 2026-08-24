#include<stdio.h>

typedef struct{
  int max;
  int n;
  int *itens;
} t_list

t_list* create_list(int max){
  t_list *list = malloc(sizeof(t_list));
  list->max=max;
  list->n=0;
  list->itens = malloc(sizeof(int)*max);
  return list;
}

void destroy_list(t_list *list){
  free(list->itens);
  free(list);
}

int size(t_list *list){
  return list->n;
}

int clear(t_list *list){
  list->n = 0;
  return 1;
}

int is_full(t_list *list){
  return list->n >= list->max;
}

int is_empty(t_list *list){
  return list->n == 0;
}

void aumenta_lista(t_list *list){
  list->max = list->max+list->max/2;
  list->itens = realloc(list->itens,list->max*sizeof(int));
}

int index_of(t_list *list, int elem){
  for(int i = 0; i < list->n; i++){
    if(list->itens[i] == elem){
      return i;
    }
  }
  return -1;
}

int append(t_list *list, int elem){
  if(!is_full(list)){
    list->itens[list->n]=elem;
    list->n++;
    return list->n-1;
  }
  return -1;
}

int insert(t_list *list, int elem, int index){
  if(index < 0){
    return 0;
  }
  if(index>list->n || is_full(list)) {
    aumenta_lista(lista);
  }
  
  for(int i = list->n; i > index; i--){
    list->itens[i] = list->itens[i-1];
  }
  list->n++;
  list->itens[index] = elem;
  return 1;
}

int update(t_list *list, int elem, int index){
  if(index > list->n || index < 0){
    return 0;
  }
  
  list->itens[index] = elem;
  return 1;
}

int remove_by_index(t_list *list, int index){
  if(index < 0 || index > list->n){
    return 0;
  }
  
  for(int i = index; i < list->n; i++){
    list->itens[i] = list->itens[i+1];
  }
  list->n--;
  return 1;
}

int remove_by_element(t_list *list, int elem){
  int ind = index_of(list, elem);
  if (ind == -1){
    return 0;
  }
  remove_by_index(list, ind);
  return 1;
}

int remove_last(t_list *list){
  if(is_empty(list)){
    return -1;
  }
  list->n--;
  return list->n;
}

int get(t_list *list, int index){
  if(index > list->n || index < 0){
    return 0;
  }
  return list->itens[index];
}

int count(t_list *list, int elem){
  int cont = 0;
  for(int i = 0; i < list->n; i++){
    if(list->itens[i]==elem){
      cont++;
    }
  }
  return cont;
}

void print_list(t_list *list){
  printf("[");
  for(int i = 0; i < list->n; i++){
    printf("%d ",list->itens[i]);
  }
  printf("]\n");
}

int main(){
  t_list *list;
  
  list = create_list(10);
}
