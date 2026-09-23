/*
Advantages
    Simple implementation: The queue follows a straightforward FIFO (First In, First Out) structure, 
    making it easy to implement and understand.
    Efficient insertion and removal: Adding an element at the end and removing one from the beginning can be performed in O(1) time.

Disadvantages
    Limited space usage: In a simple static queue, once the rear reaches the end of the array, previously freed positions cannot be reused.
    Fixed size: The maximum number of elements must be defined when the queue is allocated.
    No direct access: Elements cannot be accessed directly by index according to the queue's logic; they must be processed in FIFO order.

When to use
    When elements need to be processed in the order they were added, especially in situations such as task scheduling,
    print queues, and request processing.
*/
#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

t_queue* create_queue(int max) {
    t_queue *queue = malloc(sizeof(t_queue));
    queue->max = max;
    queue->items = malloc(sizeof(int) * max);
    queue->begin = -1;
    queue->end = 0;
    return queue;
}

int is_empty(t_queue *queue){
    if (queue->begin == queue->end-1) return 1;
    return 0;
}

int is_full(t_queue *queue){
    if (queue->end == queue->max) return 1;
    return 0;
}

int in(t_queue *queue, int x){
    if(is_full(queue)) return 0;
    queue->items[queue->end] = x;
    queue->end++;
    return 1;
}

int out(t_queue *queue, int *x){
    if(is_empty(queue)) return 0;
    *x = peek(queue);
    queue->begin++;
    return 1;
}

int peek(t_queue *queue){
    if (is_empty(queue)) return -1;
    return queue->items[queue->begin + 1];
}

void printQueue(t_queue *queue){
    if (is_empty(queue)) return;

    printf("\nQueue: ");
    for (int i = queue->begin + 1; i < queue->end; i++){
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

void destroy(t_queue *queue){
    free(queue->items);
    free(queue);
}