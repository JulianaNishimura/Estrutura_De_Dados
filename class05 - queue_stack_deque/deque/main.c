#include <stdio.h>
#include "deque.h"

int main() {
    Deque* deque = createDeque();
    int x;
    insertLast(deque, 10);  
    insertLast(deque, 20);  
    insertFirst(deque, 5);  
    
    printDeque(deque);

    printf("\nRemoving first: %d\n", removeFirst(deque,&x)); 
    printf("Removed element: %d\n",x); 

    printDeque(deque);

    printf("\nRemoving last: %d\n", removeLast(deque,&x));   
    printf("Removed element: %d\n",x); 

    printDeque(deque);

    destroyDeque(deque);
    return 0;
}
