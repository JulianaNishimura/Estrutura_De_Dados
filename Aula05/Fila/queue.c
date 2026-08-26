#include<stdio.h>
#include<stdlib.h>
#include"queue.h"


t_queue* create_queue(int max) {
    t_queue *queue = malloc(sizeof(t_queue));
    queue->max = max;
    queue->items = malloc(sizeof(int) * max);
    queue->size = 0;
    queue->begin = 0;
    queue->end = 0;
    return queue;
}

int in(t_queue *queue, int x) {
    if (is_full(queue)) {
        return 0;
    }
    queue->items[queue->end] = x;
    queue->end = (queue->end + 1) % queue->max;
    queue->size++;
    return 1;
}

int out(t_queue *queue, int *x) {
    if (is_empty(queue)) {
        return 0;
    }
    *x = queue->items[queue->begin];
    queue->begin = (queue->begin + 1) % queue->max;
    queue->size--;
    return 1;
}