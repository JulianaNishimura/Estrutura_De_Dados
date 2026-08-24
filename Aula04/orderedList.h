#ifndef LIST_H
#define LIST_H

typedef struct{
    int max;
    int n;
    int *itens;
}t_ordered_list;

t_ordered_list  *create_List (int max);





#endif