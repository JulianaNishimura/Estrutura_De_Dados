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

    printf("tamanho: %d\n", size(list1));
    printf("vazio: %d\n", is_empty(list1));

    printf("\ninsere l1 10: %d\n", insert(list1, 10));
    printf("insere l1 5: %d\n", insert(list1, 5));
    printf("insere l1 20: %d\n", insert(list1, 20));
    printf("insere l1 10: %d\n", insert(list1, 10));
    printf("insere l1 15: %d\n", insert(list1, 15));
    
    printf("\nl1:");
    imprime_lista(list1);

    printf("\ninsere l2 5: %d\n", insert(list2, 5));
    printf("insere l2 10: %d\n", insert(list2, 10));
    printf("insere l2 20: %d\n", insert(list2, 20));

    printf("\nl2:");
    imprime_lista(list2);

    printf("\ninsere l3 6: %d\n", insert(list3, 6));
    printf("insere l3 10: %d\n", insert(list3, 10));
    printf("insere l3 5: %d\n", insert(list3, 5));
    printf("insere l3 24: %d\n", insert(list3, 24));

    printf("\nl3:");
    imprime_lista(list3);

    printf("\ninsere l4 54: %d\n", insert(list4, 54));
    printf("insere l4 10: %d\n", insert(list4, 10));
    printf("insere l4 43: %d\n", insert(list4, 43));
    printf("insere l4 90: %d\n", insert(list4, 90));
    printf("insere l4 3: %d\n", insert(list4, 3));
    printf("insere l4 7: %d\n", insert(list4, 7));
    printf("insere l4 4: %d\n", insert(list4, 4));
    printf("insere l4 17: %d\n", insert(list4, 17));

    printf("\nl4:");
    imprime_lista(list4);

    printf("\ntamanho l1: %d\n", size(list1));
    printf("index de 10 na l1: %d\n", index_of(list1, 10));
    printf("index de 99 na l1: %d\n", index_of(list1, 99));
    printf("procura 15 na l1: %d\n", search(list1, 15));
    printf("procura 99 na l1: %d\n", search(list1, 99));
    printf("pega o valor no index 2 na l1: %d\n", get(list1, 2));
    printf("conta quantos 10 tem na l1: %d\n", count(list1, 10));
    printf("remove index 1 na l1: %d\n", remove_by_index(list1, 1));

    printf("\nl1:");
    imprime_lista(list1);
    printf("\nremove numero 15 na l1: %d\n", remove_by_element(list1, 15));
    
    printf("\nl1:");
    imprime_lista(list1);

    printf("\nl2:");
    imprime_lista(list2);

    printf("\nl3:");
    imprime_lista(list3);

    printf("\nl4:");
    imprime_lista(list4);

    printf("\nlistas iguais l1 e l2: %d\n", equals(list1, list2));
    printf("listas iguais l1 e l3: %d\n", equals(list1, list3));
    printf("listas iguais l1 e l4: %d\n", equals(list1, list4));

    printf("\nmerge l3 e l4:\n");
    t_ordered_list *lista_resultado = merge(list3, list4);
    printf("lista resultado:");
    imprime_lista(lista_resultado);
    printf("\ntamanho lista resultado: %d\n", size(lista_resultado));

    clear(list1);
    clear(list2);
    clear(list3);
    clear(list4);

    printf("\nl1 tamanho depois de clear: %d\n", size(list1));
    printf("l1 vazio depois de clear: %d\n", is_empty(list1));

    printf("\nl2 tamanho depois de clear: %d\n", size(list2));
    printf("l2 vazio depois de clear: %d\n", is_empty(list2));

    printf("\nl3 tamanho depois de clear: %d\n", size(list3));
    printf("l3 vazio depois de clear: %d\n", is_empty(list3));

    printf("\nl4 tamanho depois de clear: %d\n", size(list4));
    printf("l4 vazio depois de clear: %d\n", is_empty(list4));

    destroy(list1);
    destroy(list2);
    destroy(list3);
    destroy(list4);

    return 0;
}