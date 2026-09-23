#ifndef LIST_H
#define LIST_H

typedef struct{
    int max;
    int n;
    int *itens;
}t_ordered_list;

t_ordered_list* create_list(int max);

int size(t_ordered_list*list);
    
int is_empty(t_ordered_list*list);

int increase_list(t_ordered_list*list);

int insert(t_ordered_list*list, int element);

int remove_by_index(t_ordered_list*list, int index);

int remove_by_element(t_ordered_list*list, int element);

int index_of(t_ordered_list*list, int element);

int search(t_ordered_list*list, int element);

int get(t_ordered_list*list,int index);

int count(t_ordered_list*list,int element);

t_ordered_list* merge(t_ordered_list*list1, t_ordered_list*list2);

int equals(t_ordered_list*list1, t_ordered_list*list2);

int clear(t_ordered_list*list);

int destroy(t_ordered_list*list);

void imprime_lista(t_ordered_list*list);

#endif