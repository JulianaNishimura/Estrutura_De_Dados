#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

t_queue* newQueue(int size) {
    t_queue *queue = malloc(sizeof(t_queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->items = malloc(size * sizeof(int));
    queue->maxsize = size;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int size(t_queue *queue) {
    return queue->size;
}

int isEmpty(t_queue *queue) {
    return (queue->size == 0 || queue == NULL);
}

int front(t_queue *queue) {
    if (isEmpty(queue)) return -1;
    
    return queue->items[queue->front];
}

int enqueue(t_queue *queue, int x) {
    if (size(queue) == queue->maxsize) return 0;

    queue->rear = (queue->rear + 1) % queue->maxsize;
    queue->items[queue->rear] = x;
    queue->size++;
    return 1;
}

int dequeue(t_queue *queue, int *x) {
    if (isEmpty(queue)) return 0;

    *x = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->maxsize;
    queue->size--;

    return 1;
}

void printQueue(t_queue *queue) {
    if (isEmpty(queue)) return;

    printf("Queue: ");
    int index = queue->front;
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->items[index]);
        index = (index + 1) % queue->maxsize;
    }
    printf("\n");
}

void destroyQueue(t_queue *queue) {
    if (queue == NULL) return;

    free(queue->items);
    free(queue);
}