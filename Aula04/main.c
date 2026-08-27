/*
Juliana Yumi Nishimura
Ingrid Ferreira da Silva
*/
#include <stdio.h>
#include <stdlib.h>
#include "orderedList.h"

int main(int argc, char const *argv[]){
    t_ordered_list *list1 = create_list(5);
    t_ordered_list *list2 = create_list(5);
    t_ordered_list *list3 = create_list(5);
    t_ordered_list *list4 = create_list(8);

    printf("size: %d\n", size(list1));
    printf("empty: %d\n", is_empty(list1));

    printf("insert l1 10: %d\n", insert(list1, 10));
    printf("insert l1 5: %d\n", insert(list1, 5));
    printf("insert l1 20: %d\n", insert(list1, 20));
    printf("insert l1 10: %d\n", insert(list1, 10));
    printf("insert l1 15: %d\n", insert(list1, 15));

    printf("insert l2 5: %d\n", insert(list2, 5));
    printf("insert l2 10: %d\n", insert(list2, 10));
    printf("insert l2 20: %d\n", insert(list2, 20));

    printf("insert l3 6: %d\n", insert(list3, 6));
    printf("insert l3 10: %d\n", insert(list3, 10));
    printf("insert l3 5: %d\n", insert(list3, 5));
    printf("insert l3 24: %d\n", insert(list3, 24));

    printf("insert l4 54: %d\n", insert(list4, 54));
    printf("insert l4 10: %d\n", insert(list4, 10));
    printf("insert l4 43: %d\n", insert(list4, 43));
    printf("insert l4 90: %d\n", insert(list4, 90));
    printf("insert l4 3: %d\n", insert(list4, 3));
    printf("insert l4 7: %d\n", insert(list4, 7));
    printf("insert l4 4: %d\n", insert(list4, 4));
    printf("insert l4 17: %d\n", insert(list4, 17));

    printf("l1:");
    imprime_lista(list1);

    printf("size: %d\n", size(list1));
    printf("index 10: %d\n", index_of(list1, 10));
    printf("index 99: %d\n", index_of(list1, 99));
    printf("search 15: %d\n", search(list1, 15));
    printf("search 99: %d\n", search(list1, 99));
    printf("get 3: %d\n", get(list1, 2));
    printf("count 10: %d\n", count(list1, 10));

    printf("remove index 1: %d\n", remove_by_index(list1, 1));

    printf("l1:");
    imprime_lista(list1);

    printf("remove numero 15: %d\n", remove_by_element(list1, 15));
    
    printf("l1:");
    imprime_lista(list1);

    printf("l2:");
    imprime_lista(list2);

    printf("l3:");
    imprime_lista(list3);

    printf("l4:");
    imprime_lista(list4);

    printf("equals l1 e l2: %d\n", equals(list1, list2));
    printf("equals l1 e l3: %d\n", equals(list1, list3));
    printf("equals l1 e l4: %d\n", equals(list1, list4));

    clear(list1);
    clear(list2);

    printf("l1 size depois clear: %d\n", size(list1));
    printf("l1 empty depois clear: %d\n", is_empty(list1));

    printf("l2 size depois clear: %d\n", size(list2));
    printf("l2 empty depois clear: %d\n", is_empty(list2));

    printf("l3 size depois clear: %d\n", size(list3));
    printf("l3 empty depois clear: %d\n", is_empty(list3));

    printf("l4 size depois clear: %d\n", size(list4));
    printf("l4 empty depois clear: %d\n", is_empty(list4));

    destroy(list1);
    destroy(list2);
    destroy(list3);
    destroy(list4);

    return 0;
}