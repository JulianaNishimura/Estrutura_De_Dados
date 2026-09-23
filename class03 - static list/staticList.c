/*
Advantages:
  Direct and fast index access: Provides constant-time access to any element stored in contiguous memory locations.
  Fast insertion at the end: Adding a new item after the last element takes constant time.

Disadvantages:
  Movement cost: Inserting or removing elements in the middle or at the beginning requires shifting several items in memory.
  Fixed size: The maximum size of the structure must be defined beforehand when allocating memory.
  Slow search: Searching for a key requires traversing the elements sequentially.

When to use:
  For small lists where the maximum size is known in advance and there are few insertions or removals at specific positions.
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct{
  int max;
  int n;
  int *itens;
} t_list;

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

void increase_list(t_list *list){
    int new_max = list->max + list->max / 2;

    if(new_max <= 1){
        new_max = 2;
    }

    int *new_items = realloc(list->itens, new_max * sizeof(int));
    if(new_items != NULL){
        list->itens = new_items;
        list->max = new_max;
    }
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
  if(index < 0 || index > list->n){
      return 0;
  }

  if(is_full(list)){
      increase_list(list);
  }
  
  for(int i = list->n; i > index; i--){
    list->itens[i] = list->itens[i-1];
  }
  
  list->n++;
  list->itens[index] = elem;
  return 1;
}

int update(t_list *list, int elem, int index){
  if(index >= list->n || index < 0){
    return 0;
  }
  
  list->itens[index] = elem;
  return 1;
}

int remove_by_index(t_list *list, int index){
  if(index < 0 || index > list->n){
    return 0;
  }
  
  for(int i = index; i < list->n-1; i++){
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

int remove_last(t_list *list, int *elem){
    if(is_empty(list)){
        return 0;
    }

    *elem = list->itens[list->n - 1];
    list->n--;
    return 1;
}

int get(t_list *list, int index){
  if(index >= list->n || index < 0){
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
