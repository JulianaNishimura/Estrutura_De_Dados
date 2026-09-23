#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

typedef struct queue {
    int *items;
    int maxsize;
    int front;
    int rear;
    int size;
} t_queue;

t_queue* newQueue(int);
int size(t_queue*);
int isEmpty(t_queue*);
int front(t_queue*);
int enqueue(t_queue*, int );
int dequeue(t_queue*, int*);
void printQueue(t_queue*);
void destroyQueue(t_queue*);

#endif