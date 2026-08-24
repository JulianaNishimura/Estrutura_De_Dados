#include <stdio.h>
#include <stdlib.h>
#include "orderedList.h"

t_ordered_list  *create_list (int max){
    t_ordered_list *list=malloc(sizeof(t_ordered_list));
    list-> max=max;
    list->n=0;
    list-> itens=malloc(sizeof(int)*max);
    return list;
}

int size(t_ordered_list*list){
    return list->n;
}

int is_empty(t_ordered_list*list){
    if(list->n==0) return 1;
    return 0;
}

int increase_list(t_ordered_list*list){
    list->max = list->max+(list->max/3);
    list->itens = realloc(list->itens,list->max*sizeof(int));
    return 1;
}

int insert(t_ordered_list*list, int element){
    if(size(list)==list->max)
        increase_list(list);

    if(is_empty(list)){
        list->itens[0] = element;
        list->n++;
        return 1;
    }

    int i = 0;
    while(i < list->n && list->itens[i] <= element){
        i++;
    }

    for(int j = list->n; j > i; j--){
        list->itens[j] = list->itens[j-1];
    }

    list->itens[i] = element;
    list->n++;
    return 1;
}


int remove_by_index(t_ordered_list*list, int index){
    if(index>=list->n) return 0;
    if(index==list->n-1){
        list->n--;
        return 1;
    }

    for(int i=index;i<list->n-1;i++){
        list->itens[i] = list->itens[i+1];
    }
    list->n--;
    return 1;
}

int remove_by_element(t_ordered_list*list, int element){
    int index  = index_of(list,element);
    if(index  ==-1) return 0;
    remove_by_index(list,index);
    return 1;
}

int index_of(t_ordered_list*list, int element){
    int ini = 0;
    int fim = list->n-1;
    int meio;

    while(ini<=fim){
        meio = ini + (fim-ini)/2;
        if(element==list->itens[meio]) 
            return meio;
        if(element>list->itens[meio]) 
            ini = meio+1;
        if(element<list->itens[meio]) 
            fim = meio-1;
    }

    return -1;
}

int search(t_ordered_list*list, int element){
    if (index_of(list,element)>=0) return 1;
    return 0;
}

int get(t_ordered_list*list,int index){
    if(index>=list->n) return -1;
    return list->itens[index];
}

int count(t_ordered_list*list,int element){
    int quantidade = 0;
    for(int i = 0; i < list->n;i++){
        if(list->itens[i]==element)
            quantidade++;
    }
    return quantidade;
}

t_ordered_list* merge(t_ordered_list*list1, t_ordered_list*list2){
    t_ordered_list*result_list = create_list(list1->max+list2->max);
    int i = 0;
    int j = 0;
    int x = 0;
    while(i < list1->n && j < list2->n){
        if(list1->itens[i]<=list2->itens[j]){
            result_list->itens[x] = list1->itens[i];
            i++;
        } else {
            result_list->itens[x] = list2->itens[j];
            j++;
        }
        x++;
    }
}

int equals(t_ordered_list*list1, t_ordered_list*list2){
    int i;
    if(list1->n!=list2->n)
        return 0;
    for(int i = 0; i < list1->n;i++){
        if(list1->itens[i]!=list2->itens[i]){
            return 0;
        }
    }
    return 1;
}

int clear(t_ordered_list*list){
    list->n=0;
    return 1;
}

int destroy(t_ordered_list*list){
    free(list);
    return 1;
}

void imprime_lista(t_ordered_list*list){
    for(int i = 0; i < list->n; i++){
        printf("%d ", list->itens[i]);
    }
    printf("\n");
}
