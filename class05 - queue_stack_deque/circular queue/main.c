#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

int main() {

    t_queue *queue = newQueue(5);
    int x;

    printf("empty: %d\n", isEmpty(queue));

    printf("\nenqueue 10: %d\n", enqueue(queue, 10));
    printf("enqueue 20: %d\n", enqueue(queue, 20));
    printf("enqueue 30: %d\n", enqueue(queue, 30));
    printf("enqueue 40: %d\n", enqueue(queue, 40));

    printQueue(queue);
    printf("size: %d\n", size(queue));
    printf("front: %d\n", front(queue));

    dequeue(queue, &x);
    printf("\nremoved: %d\n", x);
    printQueue(queue);

    enqueue(queue, 50);
    enqueue(queue, 60);

    printf("\nafter circular insertion:\n");
    printQueue(queue);

    dequeue(queue, &x);
    printf("\nremoved: %d\n", x);

    printQueue(queue);

    printf("\nsize: %d\n", size(queue));
    printf("empty: %d\n", isEmpty(queue));

    destroyQueue(queue);

    return 0;
}