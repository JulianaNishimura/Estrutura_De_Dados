/*
Juliana Yumi Nishimura
Ingrid Ferreira da Silva
*/
#include <stdio.h> 
#include <stdlib.h> 
#include "orderedList.h" 

int main(int argc, char *argv[]) { 
    t_ordered_list *list1 = create_list(5); 
    t_ordered_list *list2 = create_list(5); 
    t_ordered_list *list3 = create_list(5); 
    t_ordered_list *list4 = create_list(8); 
    
    printf("size: %d\n", size(list1)); 
    printf("empty: %d\n", is_empty(list1)); 

    printf("\ninsert list1 10: %d\n", insert(list1, 10));
    printf("insert list1 5: %d\n", insert(list1, 5));
    printf("insert list1 20: %d\n", insert(list1, 20)); 
    printf("insert list1 10: %d\n", insert(list1, 10)); 
    printf("insert list1 15: %d\n", insert(list1, 15)); 
    
    printf("\nlist1:"); 
    imprime_lista(list1); 

    printf("\ninsert list2 5: %d\n", insert(list2, 5)); 
    printf("insert list2 10: %d\n", insert(list2, 10)); 
    printf("insert list2 20: %d\n", insert(list2, 20)); 
    
    printf("\nlist2:"); 
    imprime_lista(list2); 
    
    printf("\ninsert list3 6: %d\n", insert(list3, 6)); 
    printf("insert list3 10: %d\n", insert(list3, 10)); 
    printf("insert list3 5: %d\n", insert(list3, 5)); 
    printf("insert list3 24: %d\n", insert(list3, 24)); 
    
    printf("\nlist3:"); 
    imprime_lista(list3); 

    printf("\ninsert list4 54: %d\n", insert(list4, 54)); 
    printf("insert list4 10: %d\n", insert(list4, 10)); 
    printf("insert list4 43: %d\n", insert(list4, 43)); 
    printf("insert list4 90: %d\n", insert(list4, 90)); 
    printf("insert list4 3: %d\n", insert(list4, 3)); 
    printf("insert list4 7: %d\n", insert(list4, 7)); 
    printf("insert list4 4: %d\n", insert(list4, 4)); 
    printf("insert list4 17: %d\n", insert(list4, 17)); 
    
    printf("\nlist4:"); 
    imprime_lista(list4); 
    
    printf("\nlist1 size: %d\n", size(list1)); 
    printf("index of 10 in list1: %d\n", index_of(list1, 10)); 
    printf("index of 99 in list1: %d\n", index_of(list1, 99)); 
    printf("search for 15 in list1: %d\n", search(list1, 15)); 
    printf("search for 99 in list1: %d\n", search(list1, 99)); 
    printf("get value at index 2 in list1: %d\n", get(list1, 2)); 
    printf("count how many 10s are in list1: %d\n", count(list1, 10)); 
    printf("remove index 1 from list1: %d\n", remove_by_index(list1, 1)); 
    
    printf("\nlist1:"); 
    imprime_lista(list1); 
    
    printf("\nremove number 15 from list1: %d\n", remove_by_element(list1, 15)); 

    printf("\nlist1:"); 
    imprime_lista(list1); 
    
    printf("\nlist2:"); 
    imprime_lista(list2); 
    
    printf("\nlist3:"); 
    imprime_lista(list3); 
    
    printf("\nlist4:"); 
    imprime_lista(list4); 
    
    printf("\nlists equal list1 and list2: %d\n", equals(list1, list2)); 
    printf("lists equal list1 and list3: %d\n", equals(list1, list3)); 
    printf("lists equal list1 and list4: %d\n", equals(list1, list4)); 
    printf("\nmerge list3 and list4:\n"); 
    
    t_ordered_list *result_list = merge(list3, list4); 
    printf("result list:"); 
    imprime_lista(result_list); 
    printf("\nresult list size: %d\n", size(result_list)); 
    
    clear(list1); 
    clear(list2); 
    clear(list3); 
    clear(list4); 
    
    printf("\nlist1 size after clear: %d\n", size(list1)); 
    printf("list1 empty after clear: %d\n", is_empty(list1)); 
    printf("\nlist2 size after clear: %d\n", size(list2)); 
    printf("list2 empty after clear: %d\n", is_empty(list2)); 
    printf("\nlist3 size after clear: %d\n", size(list3)); 
    printf("list3 empty after clear: %d\n", is_empty(list3)); 
    printf("\nlist4 size after clear: %d\n", size(list4)); 
    printf("list4 empty after clear: %d\n", is_empty(list4)); 
    
    destroy(list1); 
    destroy(list2); 
    destroy(list3); 
    destroy(list4); 

    return 0; 
}