/*
 * Juliana Yumi Nishimura
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char *argv[]) {

    t_queue *queue = create_queue(5);

    printf("queue size: %d\n", queue->end - queue->begin - 1);
    printf("empty: %d\n", is_empty(queue));

    printf("\ninsert 10: %d\n", in(queue, 10));
    printf("insert 20: %d\n", in(queue, 20));
    printf("insert 30: %d\n", in(queue, 30));

    printQueue(queue);

    printf("\nfirst element: %d\n", peek(queue));

    int x;
    printf("\nremove: %d\n", out(queue, &x));
    printf("\nremoved element: %d\n", x);

    printf("\nqueue after remove:");
    printQueue(queue);

    printf("\nfirst element: %d\n", peek(queue));

    printf("\ninsert 40: %d\n", in(queue, 40));
    printf("insert 50: %d\n", in(queue, 50));
    printf("insert 60: %d\n", in(queue, 60));

    printf("\nqueue:");
    printQueue(queue);

    printf("\ninsert 70: %d\n", in(queue, 70));

    printf("\nqueue:");
    printQueue(queue);

    printf("\nremove: %d\n", out(queue, &x));
    printf("\nremoved element: %d\n", x);

    printf("remove: %d\n", out(queue, &x));
    printf("\nremoved element: %d\n", x);

    printf("\nqueue after removes:");
    printQueue(queue);

    printf("\nremove: %d\n", out(queue, &x));
    printf("removed element: %d\n", x);

    printf("\nremove: %d\n", out(queue, &x));
    printf("removed element: %d\n", x);

    printf("\nremove: %d\n", out(queue, &x));
    printf("removed element: %d\n", x);


    printf("\nqueue after removing all elements:");
    printQueue(queue);

    printf("\nempty: %d\n", is_empty(queue));

    printf("\nremove from empty queue: %d\n", out(queue, &x));

    destroy(queue);

    return 0;
}